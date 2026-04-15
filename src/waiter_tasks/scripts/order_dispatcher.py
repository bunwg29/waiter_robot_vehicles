#!/usr/bin/env python3
import math
from pathlib import Path
import time

import rclpy
from action_msgs.msg import GoalStatus
from geometry_msgs.msg import PoseStamped, Twist
from nav2_msgs.action import NavigateToPose
from rclpy.action import ActionClient
from rclpy.node import Node
import yaml
from ament_index_python.packages import get_package_share_directory


def yaw_to_quaternion(yaw):
    half = yaw / 2.0
    return (0.0, 0.0, math.sin(half), math.cos(half))


class OrderDispatcher(Node):
    """Delivery queue: kitchen -> approach table -> wait -> kitchen, repeated per table."""

    def __init__(self):
        super().__init__("order_dispatcher")

        self.declare_parameter("table_id", 3)
        self.declare_parameter("delivery_sequence", "")
        self.declare_parameter("wait_at_table_sec", 10.0)
        self.declare_parameter("tables_config_path", "")
        self.declare_parameter("approach_standoff_distance", 0.9)
        self.declare_parameter("kitchen_x", 0.0)
        self.declare_parameter("kitchen_y", 0.0)
        self.declare_parameter("kitchen_yaw", 0.0)

        self.wait_at_table_sec = float(self.get_parameter("wait_at_table_sec").value)
        self.table_id = int(self.get_parameter("table_id").value)
        self.approach_standoff_distance = float(self.get_parameter("approach_standoff_distance").value)
        self.delivery_sequence = self._parse_delivery_sequence(
            self.get_parameter("delivery_sequence").value,
            self.table_id,
        )

        self.kitchen_pose = self._build_pose(
            float(self.get_parameter("kitchen_x").value),
            float(self.get_parameter("kitchen_y").value),
            float(self.get_parameter("kitchen_yaw").value),
        )

        self.tables = self._load_tables()

        self._ac = ActionClient(self, NavigateToPose, "navigate_to_pose")
        self._cmd_pub = self.create_publisher(Twist, "/cmd_vel_nav", 10)

    def _tables_config_path(self) -> Path:
        configured_path = str(self.get_parameter("tables_config_path").value).strip()
        if configured_path:
            return Path(configured_path)

        return Path(get_package_share_directory("waiter_tasks")) / "config" / "tables.yaml"

    def _parse_delivery_sequence(self, raw_value, fallback_table_id):
        sequence = []
        if raw_value is None:
            sequence = []
        elif isinstance(raw_value, (list, tuple, set)):
            sequence = list(raw_value)
        else:
            text = str(raw_value).strip()
            if text:
                text = text.strip("[]")
                sequence = [item.strip() for item in text.split(",")]

        parsed_sequence = []
        for item in sequence:
            if item in (None, ""):
                continue

            try:
                parsed_sequence.append(int(item))
            except (TypeError, ValueError):
                self.get_logger().warn(f"Skipping invalid table id in delivery_sequence: {item!r}")

        if not parsed_sequence:
            parsed_sequence = [fallback_table_id]

        return parsed_sequence

    def _load_tables(self):
        tables_path = self._tables_config_path()
        if not tables_path.exists():
            self.get_logger().error(f"Tables config not found: {tables_path}")
            return {}

        with tables_path.open("r", encoding="utf-8") as stream:
            data = yaml.safe_load(stream) or {}

        tables = data.get("tables", data)
        parsed_tables = {}
        for key, pose in tables.items():
            if not key.startswith("table_"):
                continue
            try:
                table_id = int(key.split("_", 1)[1])
            except ValueError:
                continue

            parsed_tables[table_id] = {
                "x": float(pose["x"]),
                "y": float(pose["y"]),
                "yaw": float(pose.get("yaw", 0.0)),
                "standoff_distance": float(pose.get("standoff_distance", self.approach_standoff_distance)),
            }

        self.get_logger().info(f"Loaded tables from {tables_path}: {sorted(parsed_tables.keys())}")
        return parsed_tables

    def _build_pose(self, x, y, yaw):
        pose = PoseStamped()
        pose.header.frame_id = "map"
        pose.pose.position.x = x
        pose.pose.position.y = y
        qx, qy, qz, qw = yaw_to_quaternion(yaw)
        pose.pose.orientation.x = qx
        pose.pose.orientation.y = qy
        pose.pose.orientation.z = qz
        pose.pose.orientation.w = qw
        return pose

    def _compute_approach_pose(self, table_pose, label):
        table_x = table_pose["x"]
        table_y = table_pose["y"]
        standoff = table_pose["standoff_distance"]

        dx = table_x - self.kitchen_pose.pose.position.x
        dy = table_y - self.kitchen_pose.pose.position.y
        distance = math.hypot(dx, dy)
        if distance < 1e-6:
            self.get_logger().warn(f"Kitchen and {label} are at the same point; using table pose directly.")
            approach_x = table_x
            approach_y = table_y
        else:
            ux = dx / distance
            uy = dy / distance
            approach_x = table_x - ux * standoff
            approach_y = table_y - uy * standoff

        heading = math.atan2(table_y - approach_y, table_x - approach_x)
        return self._build_pose(approach_x, approach_y, heading)

    def _send_goal_blocking(self, pose, label):
        goal = NavigateToPose.Goal()
        goal.pose = pose
        goal.pose.header.stamp = self.get_clock().now().to_msg()

        self.get_logger().info(f"Sending goal: {label}")
        send_future = self._ac.send_goal_async(goal)
        rclpy.spin_until_future_complete(self, send_future)
        goal_handle = send_future.result()
        if goal_handle is None or not goal_handle.accepted:
            self.get_logger().error(f"Goal rejected: {label}")
            return False

        result_future = goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self, result_future)
        result = result_future.result()
        if result is None:
            self.get_logger().error(f"Goal failed (no result): {label}")
            return False

        status = result.status
        if status != GoalStatus.STATUS_SUCCEEDED:
            self.get_logger().warn(f"Goal not succeeded (status={status}): {label}")
            return False

        self.get_logger().info(f"Goal reached: {label}")
        return True

    def _deliver_to_table(self, table_id, step_index, total_steps):
        table_pose = self.tables[table_id]
        approach_pose = self._compute_approach_pose(table_pose, f"Table {table_id}")

        if not self._send_goal_blocking(
            approach_pose,
            f"Table {table_id} approach ({step_index}/{total_steps})",
        ):
            self.get_logger().warn(f"Skipping Table {table_id} because approach failed")
            return False

        self.get_logger().info(
            f"Table {table_id}: waiting {self.wait_at_table_sec:.1f} seconds for serving"
        )
        time.sleep(self.wait_at_table_sec)

        if not self._send_goal_blocking(self.kitchen_pose, f"Kitchen return after Table {table_id}"):
            self.get_logger().error(f"Failed to return to kitchen after Table {table_id}")
            return False

        return True

    def run_mission(self):
        if not self.delivery_sequence:
            self.get_logger().error("Delivery sequence is empty")
            return

        self.get_logger().info(f"Mission queue: {self.delivery_sequence}")
        completed = 0
        total_steps = len(self.delivery_sequence)

        for step_index, table_id in enumerate(self.delivery_sequence, start=1):
            if table_id not in self.tables:
                self.get_logger().error(f"Unknown table id in delivery sequence: {table_id}")
                continue

            if not self._deliver_to_table(table_id, step_index, total_steps):
                self.get_logger().error("Mission aborted because a delivery step failed")
                break

            completed += 1

        self.get_logger().info(f"Mission finished: {completed}/{total_steps} deliveries completed")

    def _drive_for(self, linear_x, angular_z, duration_sec):
        msg = Twist()
        msg.linear.x = linear_x
        msg.angular.z = angular_z
        end_t = time.time() + duration_sec
        while rclpy.ok() and time.time() < end_t:
            self._cmd_pub.publish(msg)
            time.sleep(0.1)

        stop = Twist()
        self._cmd_pub.publish(stop)

    def _fallback_motion(self):
        # Simple visible routine for debugging when Nav2 cannot complete a goal.
        self._drive_for(0.0, 0.5, 2.0)
        self._drive_for(0.22, 0.0, 3.0)
        self._drive_for(0.0, -0.5, 2.0)
        self._drive_for(0.22, 0.0, 3.0)


def main():
    rclpy.init()
    node = OrderDispatcher()

    node.get_logger().info("Waiting for /navigate_to_pose action server...")
    deadline = time.time() + 180.0
    while rclpy.ok() and time.time() < deadline:
        if node._ac.wait_for_server(timeout_sec=5.0):
            break
        node.get_logger().warn("/navigate_to_pose is not available yet, retrying...")
    else:
        node.get_logger().error("/navigate_to_pose is not available after waiting.")
        node.destroy_node()
        rclpy.shutdown()
        raise SystemExit(1)

    node.run_mission()
    node.get_logger().info("Demo run finished.")
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
