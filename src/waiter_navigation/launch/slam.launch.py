from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    nav_pkg = FindPackageShare('waiter_navigation')
    nav2_pkg = FindPackageShare('nav2_bringup')
    slam_pkg = FindPackageShare('slam_toolbox')
    slam_params = LaunchConfiguration('slam_params_file')
    nav2_params = LaunchConfiguration('params_file')
    return LaunchDescription([
        DeclareLaunchArgument('slam_params_file', default_value=PathJoinSubstitution([
            nav_pkg, 'config', 'slam_params.yaml'])),
        DeclareLaunchArgument('params_file', default_value=PathJoinSubstitution([
            nav_pkg, 'config', 'nav2_params.yaml'])),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(PathJoinSubstitution([
                slam_pkg, 'launch', 'online_async_launch.py'])),
            launch_arguments={
                'slam_params_file': slam_params,
                'use_sim_time': 'true',
            }.items(),
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(PathJoinSubstitution([
                nav2_pkg, 'launch', 'navigation_launch.py'])),
            launch_arguments={
                'params_file': nav2_params,
                'use_sim_time': 'true',
                'autostart': 'true',
            }.items(),
        ),
    ])
