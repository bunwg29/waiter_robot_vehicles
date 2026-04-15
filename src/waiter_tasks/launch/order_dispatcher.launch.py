from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument('table_id', default_value='3'),
        DeclareLaunchArgument('delivery_sequence', default_value='3'),
        DeclareLaunchArgument(
            'tables_config_path',
            default_value=PathJoinSubstitution([
                FindPackageShare('waiter_tasks'), 'config', 'tables.yaml'
            ])
        ),
        DeclareLaunchArgument('approach_standoff_distance', default_value='0.9'),
        Node(
            package='waiter_tasks',
            executable='order_dispatcher.py',
            name='order_dispatcher',
            output='screen',
            parameters=[{
                'table_id': LaunchConfiguration('table_id'),
                'delivery_sequence': LaunchConfiguration('delivery_sequence'),
                'wait_at_table_sec': 10.0,
                'tables_config_path': LaunchConfiguration('tables_config_path'),
                'approach_standoff_distance': LaunchConfiguration('approach_standoff_distance'),
                'kitchen_x': 0.0,
                'kitchen_y': 0.0,
                'kitchen_yaw': 0.0,
            }]
        )
    ])
