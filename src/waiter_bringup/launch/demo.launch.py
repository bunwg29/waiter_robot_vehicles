from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    delivery_seq = LaunchConfiguration('delivery_sequence')
    return LaunchDescription([
        DeclareLaunchArgument('delivery_sequence', default_value='1,3'),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(PathJoinSubstitution([
                FindPackageShare('waiter_simulation'), 'launch', 'simulation.launch.py'])),
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(PathJoinSubstitution([
                FindPackageShare('waiter_navigation'), 'launch', 'navigation.launch.py'])),
        ),
        TimerAction(
            period=10.0,
            actions=[
                Node(
                    package='waiter_bringup',
                    executable='waiter_node.py',
                    name='waiter_node',
                    output='screen',
                    parameters=[{
                        'use_sim_time': True,
                        'delivery_sequence': delivery_seq,
                        'wait_at_table_sec': 10.0,
                    }],
                ),
            ],
        ),
    ])
