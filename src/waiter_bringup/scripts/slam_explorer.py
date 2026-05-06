#!/usr/bin/env python3
import subprocess
import time
import rclpy
from geometry_msgs.msg import Twist
from rclpy.node import Node
from sensor_msgs.msg import LaserScan

class SlamExplorer(Node):
    def __init__(self):
        super().__init__('slam_explorer')
        self.declare_parameter('explore_duration_sec', 120.0)
        self.declare_parameter('map_save_path', '')
        self.explore_duration = self.get_parameter('explore_duration_sec').value
        self._cmd_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self._min_front_dist = 999.0
        self.create_subscription(LaserScan, '/scan', self._scan_cb, 10)

    def _scan_cb(self, msg: LaserScan):
        n = len(msg.ranges)
        front_indices = list(range(0, n // 12)) + list(range(11 * n // 12, n))
        valid = [msg.ranges[i] for i in front_indices if msg.range_min < msg.ranges[i] < msg.range_max]
        self._min_front_dist = min(valid) if valid else 999.0

    def _spin_sleep(self, sec):
        end = time.time() + sec
        while rclpy.ok() and time.time() < end:
            rclpy.spin_once(self, timeout_sec=0.1)

    def run(self):
        self._spin_sleep(5.0)
        deadline = time.time() + self.explore_duration
        twist = Twist()
        while rclpy.ok() and time.time() < deadline:
            rclpy.spin_once(self, timeout_sec=0.05)
            if self._min_front_dist < 0.5:
                twist.linear.x = 0.0
                twist.angular.z = 0.6
            elif self._min_front_dist < 1.0:
                twist.linear.x = 0.08
                twist.angular.z = 0.4
            else:
                twist.linear.x = 0.18
                twist.angular.z = 0.15
            self._cmd_pub.publish(twist)
        self._cmd_pub.publish(Twist())
        self._spin_sleep(1.0)
        self._save_map()

    def _save_map(self):
        save_path = str(self.get_parameter('map_save_path').value).strip()
        if not save_path:
            save_path = '/home/bun29/waiter_robot_ws/src/waiter_navigation/maps/restaurant'
        for attempt in range(3):
            try:
                result = subprocess.run(
                    ['ros2', 'run', 'nav2_map_server', 'map_saver_cli', '-f', save_path, '--ros-args', '-p', 'use_sim_time:=true'],
                    capture_output=True, text=True, timeout=30,
                )
                if result.returncode == 0:
                    return
            except subprocess.TimeoutExpired:
                pass
            self._spin_sleep(2.0)

def main():
    rclpy.init()
    node = SlamExplorer()
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
