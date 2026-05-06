#!/usr/bin/env python3
import math
import time
from pathlib import Path
import rclpy
import yaml
from action_msgs.msg import GoalStatus
from ament_index_python.packages import get_package_share_directory
from geometry_msgs.msg import PoseStamped, PoseWithCovarianceStamped
from lifecycle_msgs.srv import GetState
from nav2_msgs.action import NavigateToPose
from rclpy.action import ActionClient
from rclpy.node import Node
from rclpy.time import Time
from tf2_ros import Buffer, TransformListener

class WaiterNode(Node):
    def __init__(self):
        super().__init__('waiter_node')
        self.declare_parameter('delivery_sequence', '1,2,3,4')
        self.declare_parameter('wait_at_table_sec', 10.0)
        self.wait_at_table_sec = self.get_parameter('wait_at_table_sec').value
        raw = str(self.get_parameter('delivery_sequence').value)
        self.delivery_seq = [int(x.strip()) for x in raw.split(',') if x.strip()]
        config_path = Path(get_package_share_directory('waiter_bringup')) / 'config' / 'tables.yaml'
        with open(config_path) as f:
            config = yaml.safe_load(f)
        self.kitchen = config['kitchen']
        self.tables = config['tables']
        self._nav_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')
        self._initialpose_pub = self.create_publisher(PoseWithCovarianceStamped, '/initialpose', 10)

        self._bt_state = self.create_client(GetState, '/bt_navigator/get_state')
        self._tf_buf = Buffer()
        self._tf_listener = TransformListener(self._tf_buf, self)

    def _spin_sleep(self, sec):
        end = time.time() + sec
        while rclpy.ok() and time.time() < end:
            rclpy.spin_once(self, timeout_sec=min(0.1, max(0, end - time.time())))

    @staticmethod
    def _yaw_to_quat(yaw):
        return (0.0, 0.0, math.sin(yaw / 2), math.cos(yaw / 2))

    def _make_pose(self, x, y, yaw):
        p = PoseStamped()
        p.header.frame_id = 'map'
        p.header.stamp.sec = 0
        p.header.stamp.nanosec = 0
        p.pose.position.x = float(x)
        p.pose.position.y = float(y)
        _, _, qz, qw = self._yaw_to_quat(float(yaw))
        p.pose.orientation.z = qz
        p.pose.orientation.w = qw
        return p

    def _publish_initial_pose(self):
        pose = PoseWithCovarianceStamped()
        pose.header.frame_id = 'map'
        pose.pose.pose.position.x = self.kitchen['x']
        pose.pose.pose.position.y = self.kitchen['y']
        _, _, qz, qw = self._yaw_to_quat(self.kitchen.get('yaw', 0.0))
        pose.pose.pose.orientation.z = qz
        pose.pose.pose.orientation.w = qw
        cov = [0.0] * 36
        cov[0] = cov[7] = 0.25
        cov[35] = 0.07
        pose.pose.covariance = cov
        for i in range(5):
            pose.header.stamp = self.get_clock().now().to_msg()
            self._initialpose_pub.publish(pose)
            self._spin_sleep(0.5)

    def _wait_for_map_tf(self, timeout=60.0):
        deadline = time.time() + timeout
        while rclpy.ok() and time.time() < deadline:
            rclpy.spin_once(self, timeout_sec=0.2)
            try:
                if self._tf_buf.can_transform('map', 'base_link', Time()):
                    return True
            except Exception:
                pass
        return False



    def _wait_for_bt_active(self, timeout=120.0):
        deadline = time.time() + timeout
        while rclpy.ok() and time.time() < deadline:
            if not self._bt_state.wait_for_service(timeout_sec=2.0):
                continue
            req = GetState.Request()
            future = self._bt_state.call_async(req)
            rclpy.spin_until_future_complete(self, future, timeout_sec=5.0)
            resp = future.result()
            if resp and resp.current_state.label == 'active':
                return True
            self._spin_sleep(2.0)
        return False

    def _go_to(self, pose, label, retries=5):
        goal = NavigateToPose.Goal()
        goal.pose = pose
        for attempt in range(retries):
            if not self._nav_client.wait_for_server(timeout_sec=5.0):
                self._spin_sleep(2.0)
                continue
            send_future = self._nav_client.send_goal_async(goal)
            rclpy.spin_until_future_complete(self, send_future)
            gh = send_future.result()
            if not gh or not gh.accepted:
                self._spin_sleep(3.0)
                continue
            result_future = gh.get_result_async()
            rclpy.spin_until_future_complete(self, result_future)
            result = result_future.result()
            if result and result.status == GoalStatus.STATUS_SUCCEEDED:
                return True
            self._spin_sleep(2.0)
        return False

    def run(self):
        while rclpy.ok():
            rclpy.spin_once(self, timeout_sec=0.5)
            if self.get_clock().now().nanoseconds > 0:
                break
        self._spin_sleep(3.0)
        self._publish_initial_pose()
        if not self._wait_for_map_tf(): return
        if not self._wait_for_bt_active(): return
        self._spin_sleep(2.0)
        kitchen_pose = self._make_pose(self.kitchen['x'], self.kitchen['y'], self.kitchen.get('yaw', 0.0))
        for table_id in self.delivery_seq:
            table_id_str = str(table_id)
            if table_id_str not in self.tables and table_id not in self.tables:
                continue
            table = self.tables.get(table_id_str) or self.tables.get(table_id)
            table_pose = self._make_pose(table['x'], table['y'], table.get('yaw', 0.0))
            if not self._go_to(table_pose, f'Table {table_id}'):
                continue
            self._spin_sleep(self.wait_at_table_sec)
            if not self._go_to(kitchen_pose, 'Kitchen'):
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
        try: rclpy.shutdown()
        except: pass

if __name__ == '__main__':
    main()
