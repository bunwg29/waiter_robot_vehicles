from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    return LaunchDescription([
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(PathJoinSubstitution([
                FindPackageShare('waiter_simulation'), 'launch', 'simulation.launch.py'])),
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(PathJoinSubstitution([
                FindPackageShare('waiter_navigation'), 'launch', 'slam.launch.py'])),
        ),
        TimerAction(
            period=15.0,
            actions=[
                Node(
                    package='waiter_bringup',
                    executable='slam_explorer.py',
                    name='slam_explorer',
                    output='screen',
                    parameters=[{
                        'use_sim_time': True,
                        'explore_duration_sec': 120.0,
                    }],
                ),
            ],
        ),
    ])
