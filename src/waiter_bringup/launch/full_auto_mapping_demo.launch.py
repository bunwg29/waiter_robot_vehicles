from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    return LaunchDescription([
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(PathJoinSubstitution([
                FindPackageShare('waiter_bringup'), 'launch', 'sim_demo.launch.py'
            ])),
            launch_arguments={
                'with_navigation': 'false',
                'with_slam': 'true',
                'run_dispatcher': 'false',
                'use_rviz': 'false',
            }.items(),
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(PathJoinSubstitution([
                FindPackageShare('waiter_tasks'), 'launch', 'auto_mapping.launch.py'
            ])),
        ),
    ])