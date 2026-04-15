#!/usr/bin/env python3
import math
import subprocess
import time
from pathlib import Path

import rclpy
from ament_index_python.packages import get_package_share_directory
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from rclpy.node import Node
import yaml


class AutoMapper(Node):
    def __init__(self):
        super().__init__("auto_mapper")
        self.declare_parameter("waypoints_config_path", "")
        self.declare_parameter("map_save_path", "")
        self.declare_parameter("pause_sec", 2.0)
        self.declare_parameter("position_tolerance", 0.22)
        self.declare_parameter("yaw_tolerance", 0.2)
        self.declare_parameter("linear_speed", 0.18)
        self.declare_parameter("angular_speed", 0.75)
        self.declare_parameter("waypoint_timeout_sec", 180.0)

        self.pause_sec = float(self.get_parameter("pause_sec").value)
        self.position_tolerance = float(self.get_parameter("position_tolerance").value)
        self.yaw_tolerance = float(self.get_parameter("yaw_tolerance").value)
        self.linear_speed = float(self.get_parameter("linear_speed").value)
        self.angular_speed = float(self.get_parameter("angular_speed").value)
        self.waypoint_timeout_sec = float(self.get_parameter("waypoint_timeout_sec").value)
        self.waypoints = self._load_waypoints()
        self.map_save_path = self._resolve_map_save_path()

        self._cmd_pub = self.create_publisher(Twist, "/cmd_vel_nav", 10)
        self._odom_sub = self.create_subscription(Odometry, "/odom", self._odom_callback, 10)
        self._latest_odom = None
        self._odom_anchor = None

    def _waypoints_config_path(self):
        configured_path = str(self.get_parameter("waypoints_config_path").value).strip()
        if configured_path:
            return Path(configured_path)

        return Path(get_package_share_directory("waiter_navigation")) / "config" / "auto_mapping_waypoints.yaml"

    def _resolve_map_save_path(self):
        configured_path = str(self.get_parameter("map_save_path").value).strip()
        if configured_path:
            return configured_path

        return str(Path(get_package_share_directory("waiter_navigation")) / "maps" / "restaurant")

    def _load_waypoints(self):
        waypoints_path = self._waypoints_config_path()
        if not waypoints_path.exists():
            self.get_logger().error(f"Waypoint config not found: {waypoints_path}")
            return []

        with waypoints_path.open("r", encoding="utf-8") as stream:
            data = yaml.safe_load(stream) or {}

        entries = data.get("waypoints", [])
        parsed = []
        for entry in entries:
            parsed.append({
                "name": str(entry.get("name", f"waypoint_{len(parsed) + 1}")),
                "x": float(entry["x"]),
                "y": float(entry["y"]),
                "yaw": float(entry.get("yaw", 0.0)),
            })

        self.get_logger().info(f"Loaded {len(parsed)} waypoints from {waypoints_path}")
        return parsed

    def _normalize_angle(self, angle):
        while angle > math.pi:
            angle -= 2.0 * math.pi
        while angle < -math.pi:
            angle += 2.0 * math.pi
        return angle

    def _odom_callback(self, message):
        self._latest_odom = message
        if self._odom_anchor is None:
            position = message.pose.pose.position
            orientation = message.pose.pose.orientation
            self._odom_anchor = (
                position.x,
                position.y,
                math.atan2(
                    2.0 * (orientation.w * orientation.z + orientation.x * orientation.y),
                    1.0 - 2.0 * (orientation.y * orientation.y + orientation.z * orientation.z),
                ),
            )

    def _get_robot_pose(self):
        if self._latest_odom is None or self._odom_anchor is None:
            raise RuntimeError("Odom not ready")

        position = self._latest_odom.pose.pose.position
        orientation = self._latest_odom.pose.pose.orientation
        current_yaw = math.atan2(
            2.0 * (orientation.w * orientation.z + orientation.x * orientation.y),
            1.0 - 2.0 * (orientation.y * orientation.y + orientation.z * orientation.z),
        )

        anchor_x, anchor_y, anchor_yaw = self._odom_anchor
        dx = position.x - anchor_x
        dy = position.y - anchor_y
        cos_anchor = math.cos(anchor_yaw)
        sin_anchor = math.sin(anchor_yaw)
        relative_x = cos_anchor * dx + sin_anchor * dy
        relative_y = -sin_anchor * dx + cos_anchor * dy
        relative_yaw = self._normalize_angle(current_yaw - anchor_yaw)
        return relative_x, relative_y, relative_yaw

    def _publish_stop(self):
        self._cmd_pub.publish(Twist())

    def _spin_in_place(self, duration_sec):
        twist = Twist()
        twist.angular.z = 0.45
        end_time = time.time() + duration_sec
        while rclpy.ok() and time.time() < end_time:
            self._cmd_pub.publish(twist)
            time.sleep(0.1)
        self._publish_stop()

    def _drive_to_waypoint(self, waypoint):
        target_x = waypoint["x"]
        target_y = waypoint["y"]
        target_yaw = waypoint["yaw"]
        label = waypoint["name"]

        self.get_logger().info(f"Driving to mapping waypoint: {label}")
        deadline = time.time() + self.waypoint_timeout_sec

        while rclpy.ok() and time.time() < deadline:
            rclpy.spin_once(self, timeout_sec=0.01)
            try:
                robot_x, robot_y, robot_yaw = self._get_robot_pose()
            except Exception:
                time.sleep(0.1)
                continue

            dx = target_x - robot_x
            dy = target_y - robot_y
            distance = math.hypot(dx, dy)
            heading_to_goal = math.atan2(dy, dx)
            heading_error = self._normalize_angle(heading_to_goal - robot_yaw)

            if distance <= self.position_tolerance:
                yaw_error = self._normalize_angle(target_yaw - robot_yaw)
                if abs(yaw_error) <= self.yaw_tolerance:
                    self._publish_stop()
                    self.get_logger().info(f"Reached waypoint: {label}")
                    return True

                twist = Twist()
                twist.angular.z = max(-self.angular_speed, min(self.angular_speed, 1.5 * yaw_error))
                self._cmd_pub.publish(twist)
                time.sleep(0.1)
                continue

            twist = Twist()
            turn_factor = max(0.0, 1.0 - min(abs(heading_error) / 1.2, 1.0))
            twist.linear.x = min(self.linear_speed, 0.55 * distance) * turn_factor
            twist.angular.z = max(-self.angular_speed, min(self.angular_speed, 1.8 * heading_error))
            self._cmd_pub.publish(twist)
            time.sleep(0.1)

        self._publish_stop()
        self.get_logger().warn(f"Timed out while driving to waypoint: {label}")
        return False

    def _save_map(self):
        self.get_logger().info(f"Saving map to: {self.map_save_path}")
        result = subprocess.run(
            ["ros2", "run", "nav2_map_server", "map_saver_cli", "-f", self.map_save_path],
            check=False,
            capture_output=True,
            text=True,
        )
        if result.returncode != 0:
            self.get_logger().error(f"Map save failed: {result.stderr.strip() or result.stdout.strip()}")
            return False

        self.get_logger().info("Map saved successfully")
        return True

    def run(self):
        if not self.waypoints:
            self.get_logger().error("No waypoints configured")
            return

        self.get_logger().info("Waiting for odom data from simulation...")
        deadline = time.time() + 180.0
        while rclpy.ok() and time.time() < deadline:
            rclpy.spin_once(self, timeout_sec=0.01)
            try:
                self._get_robot_pose()
                break
            except Exception:
                time.sleep(0.2)
        else:
            self.get_logger().error("odom data is not available")
            return

        for waypoint in self.waypoints:
            if not self._drive_to_waypoint(waypoint):
                self.get_logger().warn(f"Skipping remaining waypoints after failure at {waypoint['name']}")
                break

            self._spin_in_place(2.0)
            if self.pause_sec > 0.0:
                self.get_logger().info(f"Pausing {self.pause_sec:.1f} seconds to collect scan data")
                time.sleep(self.pause_sec)

        self._save_map()


def main():
    rclpy.init()
    node = AutoMapper()
    try:
        node.run()
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()