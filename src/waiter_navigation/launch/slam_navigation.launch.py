from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    slam_params_file = LaunchConfiguration('slam_params_file')

    return LaunchDescription([
        DeclareLaunchArgument(
            'slam_params_file',
            default_value=PathJoinSubstitution([
                FindPackageShare('waiter_navigation'), 'config', 'slam_toolbox.yaml'
            ])
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(PathJoinSubstitution([
                FindPackageShare('waiter_navigation'), 'launch', 'slam_mapping.launch.py'
            ])),
            launch_arguments={
                'slam_params_file': slam_params_file,
            }.items(),
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(PathJoinSubstitution([
                FindPackageShare('nav2_bringup'), 'launch', 'bringup_launch.py'
            ])),
            launch_arguments={
                'slam': 'False',
                'use_sim_time': 'true',
                'autostart': 'true',
                'slam_params_file': slam_params_file,
                'use_localization': 'False',
            }.items(),
        ),
    ])