from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import Command, FindExecutable, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    robot_description = ParameterValue(
        Command([
            FindExecutable(name='xacro'), ' ',
            PathJoinSubstitution([
                FindPackageShare('waiter_description'),
                'urdf',
                'waiter.xacro'
            ]),
        ]),
        value_type=str
    )

    world_path = PathJoinSubstitution([
        FindPackageShare('waiter_simulation'),
        'worlds',
        'restaurant.sdf',
    ])

    return LaunchDescription([
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                PathJoinSubstitution([
                    FindPackageShare('ros_gz_sim'),
                    'launch',
                    'gz_sim.launch.py',
                ])
            ),
            launch_arguments={'gz_args': ['-r ', world_path]}.items(),
        ),

        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            output='screen',
            parameters=[{
                'robot_description': robot_description,
                'use_sim_time': True
            }],
        ),

        Node(
            package='ros_gz_sim',
            executable='create',
            output='screen',
            arguments=[
                '-name', 'waiter_robot',
                '-topic', 'robot_description',
                '-x', '-5.55',
                '-y', '-3.25',
                '-z', '0.1',
                '-Y', '1.57',
            ],
        ),

        Node(
            package='ros_gz_bridge',
            executable='parameter_bridge',
            output='screen',
            arguments=[
                '/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock',
                '/cmd_vel@geometry_msgs/msg/Twist]gz.msgs.Twist',
                '/odom@nav_msgs/msg/Odometry[gz.msgs.Odometry',
                '/scan@sensor_msgs/msg/LaserScan[gz.msgs.LaserScan',
            ],
            parameters=[{'use_sim_time': True}],
        ),

        Node(
            package='waiter_simulation',
            executable='odom_tf_broadcaster.py',
            name='odom_tf_broadcaster',
            output='screen',
            parameters=[{'use_sim_time': True}],
        ),

        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='lidar_frame_bridge',
            output='screen',
            arguments=[
                '--x', '0',
                '--y', '0',
                '--z', '0',
                '--roll', '0',
                '--pitch', '0',
                '--yaw', '0',
                '--frame-id', 'lidar_link',
                '--child-frame-id', 'waiter_robot/base_footprint/lidar',
            ],
            parameters=[{'use_sim_time': True}],
        ),
    ])