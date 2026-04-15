#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from geometry_msgs.msg import TransformStamped
from tf2_ros import TransformBroadcaster


class OdomTfBroadcaster(Node):
    def __init__(self):
        super().__init__('odom_tf_broadcaster')
        self._tf_broadcaster = TransformBroadcaster(self)
        self._last_odom = None
        self._subscription = self.create_subscription(
            Odometry,
            '/odom',
            self._odom_callback,
            20,
        )
        self._timer = self.create_timer(0.05, self._publish_transform)

    def _odom_callback(self, msg: Odometry) -> None:
        self._last_odom = msg

    def _publish_transform(self) -> None:
        transform = TransformStamped()
        transform.header.stamp = self.get_clock().now().to_msg()
        transform.header.frame_id = 'odom'
        transform.child_frame_id = 'base_link'

        if self._last_odom is None:
            transform.transform.translation.x = 0.0
            transform.transform.translation.y = 0.0
            transform.transform.translation.z = 0.0
            transform.transform.rotation.x = 0.0
            transform.transform.rotation.y = 0.0
            transform.transform.rotation.z = 0.0
            transform.transform.rotation.w = 1.0
        else:
            transform.transform.translation.x = self._last_odom.pose.pose.position.x
            transform.transform.translation.y = self._last_odom.pose.pose.position.y
            transform.transform.translation.z = self._last_odom.pose.pose.position.z
            transform.transform.rotation = self._last_odom.pose.pose.orientation

        self._tf_broadcaster.sendTransform(transform)


def main() -> None:
    rclpy.init()
    node = OdomTfBroadcaster()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
