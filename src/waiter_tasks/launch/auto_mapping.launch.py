from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, EmitEvent, RegisterEventHandler
from launch.event_handlers import OnProcessExit
from launch.events import Shutdown
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    waypoints_config_path = LaunchConfiguration('waypoints_config_path')
    map_save_path = LaunchConfiguration('map_save_path')
    pause_sec = LaunchConfiguration('pause_sec')

    auto_mapper = Node(
        package='waiter_tasks',
        executable='auto_mapper.py',
        name='auto_mapper',
        output='screen',
        parameters=[{
            'waypoints_config_path': waypoints_config_path,
            'map_save_path': map_save_path,
            'pause_sec': pause_sec,
        }]
    )

    return LaunchDescription([
        DeclareLaunchArgument(
            'waypoints_config_path',
            default_value=PathJoinSubstitution([
                FindPackageShare('waiter_navigation'), 'config', 'auto_mapping_waypoints.yaml'
            ])
        ),
        DeclareLaunchArgument(
            'map_save_path',
            default_value=PathJoinSubstitution([
                FindPackageShare('waiter_navigation'), 'maps', 'restaurant'
            ])
        ),
        DeclareLaunchArgument('pause_sec', default_value='2.0'),
        auto_mapper,
        RegisterEventHandler(
            OnProcessExit(
                target_action=auto_mapper,
                on_exit=[EmitEvent(event=Shutdown(reason='automatic mapping completed'))],
            )
        ),
    ])