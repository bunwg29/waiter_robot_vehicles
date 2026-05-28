#!/usr/bin/env python3

import math
import time
from pathlib import Path

import rclpy
import yaml

from action_msgs.msg import GoalStatus
from ament_index_python.packages import get_package_share_directory
from geometry_msgs.msg import PoseStamped
from geometry_msgs.msg import PoseWithCovarianceStamped
from lifecycle_msgs.srv import GetState
from nav2_msgs.action import NavigateToPose
from rclpy.action import ActionClient
from rclpy.node import Node
from rclpy.time import Time
from tf2_ros import Buffer, TransformListener


class WaiterNode(Node):

    def __init__(self):
        super().__init__('waiter_node')

        self.declare_parameter(
            'delivery_sequence',
            '1,2,3,4,5,6,7,8'
        )

        self.declare_parameter(
            'wait_at_table_sec',
            1.5
        )

        self.wait_at_table_sec = float(
            self.get_parameter(
                'wait_at_table_sec'
            ).value
        )

        raw = str(
            self.get_parameter(
                'delivery_sequence'
            ).value
        )

        self.delivery_seq = [
            int(x.strip())
            for x in raw.split(',')
            if x.strip()
        ]

        config_path = (
            Path(
                get_package_share_directory(
                    'waiter_bringup'
                )
            )
            / 'config'
            / 'tables.yaml'
        )

        with open(config_path) as f:
            config = yaml.safe_load(f)

        self.kitchen = config['kitchen']
        self.tables = config['tables']

        self._nav_client = ActionClient(
            self,
            NavigateToPose,
            'navigate_to_pose'
        )

        self._initialpose_pub = self.create_publisher(
            PoseWithCovarianceStamped,
            '/initialpose',
            10
        )

        self._bt_state = self.create_client(
            GetState,
            '/bt_navigator/get_state'
        )

        self._tf_buf = Buffer()

        self._tf_listener = TransformListener(
            self._tf_buf,
            self
        )

        self.get_logger().info(
            'Waiter node started'
        )

    def _spin_sleep(self, sec):

        end = time.time() + sec

        while rclpy.ok() and time.time() < end:

            rclpy.spin_once(
                self,
                timeout_sec=0.05
            )

    @staticmethod
    def _yaw_to_quat(yaw):

        return (
            0.0,
            0.0,
            math.sin(yaw / 2.0),
            math.cos(yaw / 2.0)
        )

    def _make_pose(self, x, y, yaw):

        pose = PoseStamped()

        pose.header.frame_id = 'map'

        pose.header.stamp = (
            self.get_clock().now().to_msg()
        )

        pose.pose.position.x = float(x)
        pose.pose.position.y = float(y)

        _, _, qz, qw = self._yaw_to_quat(yaw)

        pose.pose.orientation.z = qz
        pose.pose.orientation.w = qw

        return pose

    def _publish_initial_pose(self):

        msg = PoseWithCovarianceStamped()

        msg.header.frame_id = 'map'

        msg.pose.pose.position.x = self.kitchen['x']
        msg.pose.pose.position.y = self.kitchen['y']

        _, _, qz, qw = self._yaw_to_quat(
            self.kitchen.get('yaw', 0.0)
        )

        msg.pose.pose.orientation.z = qz
        msg.pose.pose.orientation.w = qw

        cov = [0.0] * 36

        cov[0] = 0.25
        cov[7] = 0.25
        cov[35] = 0.05

        msg.pose.covariance = cov

        for _ in range(3):

            msg.header.stamp = (
                self.get_clock().now().to_msg()
            )

            self._initialpose_pub.publish(msg)

            self._spin_sleep(0.3)

    def _wait_for_map_tf(self, timeout=30.0):

        deadline = time.time() + timeout

        while rclpy.ok() and time.time() < deadline:

            rclpy.spin_once(
                self,
                timeout_sec=0.1
            )

            try:

                if self._tf_buf.can_transform(
                    'map',
                    'base_link',
                    Time()
                ):

                    return True

            except Exception:
                pass

        return False

    def _wait_for_bt_active(self, timeout=60.0):

        deadline = time.time() + timeout

        while rclpy.ok() and time.time() < deadline:

            if not self._bt_state.wait_for_service(
                timeout_sec=1.0
            ):

                continue

            req = GetState.Request()

            future = self._bt_state.call_async(req)

            rclpy.spin_until_future_complete(
                self,
                future,
                timeout_sec=2.0
            )

            result = future.result()

            if result:

                if result.current_state.label == 'active':

                    return True

            self._spin_sleep(0.5)

        return False

    def _go_to(self, pose, label, retries=2):

        self.get_logger().info(
            f'Navigating to {label}'
        )

        goal = NavigateToPose.Goal()

        goal.pose = pose

        for attempt in range(retries):

            if not self._nav_client.wait_for_server(
                timeout_sec=2.0
            ):

                self.get_logger().warn(
                    'Nav2 server unavailable'
                )

                continue

            send_future = (
                self._nav_client.send_goal_async(goal)
            )

            rclpy.spin_until_future_complete(
                self,
                send_future
            )

            goal_handle = send_future.result()

            if not goal_handle:

                continue

            if not goal_handle.accepted:

                self.get_logger().warn(
                    'Goal rejected'
                )

                continue

            result_future = (
                goal_handle.get_result_async()
            )

            rclpy.spin_until_future_complete(
                self,
                result_future
            )

            result = result_future.result()

            if result:

                if result.status == GoalStatus.STATUS_SUCCEEDED:

                    self.get_logger().info(
                        f'Reached {label}'
                    )

                    return True

            self.get_logger().warn(
                f'Failed attempt {attempt + 1}'
            )

            self._spin_sleep(0.5)

        return False

    def run(self):

        self.get_logger().info(
            'Waiting systems...'
        )

        self._spin_sleep(2.0)

        self._publish_initial_pose()

        if not self._wait_for_map_tf():

            self.get_logger().error(
                'TF not ready'
            )

            return

        if not self._wait_for_bt_active():

            self.get_logger().error(
                'BT Navigator inactive'
            )

            return

        kitchen_pose = self._make_pose(
            self.kitchen['x'],
            self.kitchen['y'],
            self.kitchen.get('yaw', 0.0)
        )

        while rclpy.ok():

            for table_id in self.delivery_seq:

                table = (
                    self.tables.get(str(table_id))
                    or self.tables.get(table_id)
                )

                if not table:

                    continue

                table_pose = self._make_pose(
                    table['x'],
                    table['y'],
                    table.get('yaw', 0.0)
                )

                ok = self._go_to(
                    table_pose,
                    f'Table {table_id}'
                )

                if not ok:

                    continue

                self.get_logger().info(
                    f'Waiting at table {table_id}'
                )

                self._spin_sleep(
                    self.wait_at_table_sec
                )

                self._go_to(
                    kitchen_pose,
                    'Kitchen'
                )

            self.get_logger().info(
                'Delivery cycle completed'
            )

            break


def main():

    rclpy.init()

    node = WaiterNode()

    try:

        node.run()

    except KeyboardInterrupt:

        pass

    finally:

        node.destroy_node()

        try:

            rclpy.shutdown()

        except Exception:

            pass


if __name__ == '__main__':

    main()