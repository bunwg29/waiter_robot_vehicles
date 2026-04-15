from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, TimerAction
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PythonExpression, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    with_navigation = LaunchConfiguration('with_navigation')
    with_slam = LaunchConfiguration('with_slam')
    run_dispatcher = LaunchConfiguration('run_dispatcher')
    use_rviz = LaunchConfiguration('use_rviz')
    delivery_sequence = LaunchConfiguration('delivery_sequence')

    return LaunchDescription([
        DeclareLaunchArgument('with_navigation', default_value='false'),
        DeclareLaunchArgument('with_slam', default_value='false'),
        DeclareLaunchArgument('run_dispatcher', default_value='false'),
        DeclareLaunchArgument('use_rviz', default_value='true'),
        DeclareLaunchArgument('delivery_sequence', default_value='3'),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(PathJoinSubstitution([
                FindPackageShare('waiter_simulation'), 'launch', 'gazebo.launch.py'
            ])),
            launch_arguments={'use_rviz': use_rviz}.items(),
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(PathJoinSubstitution([
                FindPackageShare('waiter_navigation'), 'launch', 'navigation.launch.py'
            ])),
            condition=IfCondition(PythonExpression([
                "'", with_navigation, "' == 'true' and '", with_slam, "' == 'false'"
            ])),
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(PathJoinSubstitution([
                FindPackageShare('waiter_navigation'), 'launch', 'slam_mapping.launch.py'
            ])),
            condition=IfCondition(PythonExpression([
                "'", with_slam, "' == 'true' and '", with_navigation, "' == 'false'"
            ])),
        ),
        TimerAction(
            period=20.0,
            actions=[
                IncludeLaunchDescription(
                    PythonLaunchDescriptionSource(PathJoinSubstitution([
                        FindPackageShare('waiter_tasks'), 'launch', 'order_dispatcher.launch.py'
                    ])),
                    launch_arguments={
                        'delivery_sequence': delivery_sequence,
                    }.items(),
                    condition=IfCondition(PythonExpression([
                        "'", with_navigation, "' == 'true' and '", with_slam, "' == 'false' and '", run_dispatcher, "' == 'true'"
                    ])),
                ),
            ],
        ),
    ])
