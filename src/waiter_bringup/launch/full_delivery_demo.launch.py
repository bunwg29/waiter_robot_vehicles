from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    delivery_sequence = LaunchConfiguration('delivery_sequence')

    return LaunchDescription([
        DeclareLaunchArgument('delivery_sequence', default_value='1,3'),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(PathJoinSubstitution([
                FindPackageShare('waiter_bringup'), 'launch', 'sim_demo.launch.py'
            ])),
            launch_arguments={
                'with_navigation': 'true',
                'run_dispatcher': 'true',
                'delivery_sequence': delivery_sequence,
            }.items(),
        )
    ])
