import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

from launch_ros.actions import Node


def generate_launch_description():

    model_name = os.getenv('TURTLEBOT3_MODEL', 'burger')
    pkg_share = get_package_share_directory('navigation')
    # Package locations
    tb3_gazebo_dir = get_package_share_directory('turtlebot3_gazebo')

    # Launch Gazebo world
    world_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                tb3_gazebo_dir,
                'launch',
                'empty_world.launch.py'
            )
        )
    )

    # map handling
    map_yaml_path = os.path.join(pkg_share, 'maps', 'nav_map.yaml')
    map_odom_tf = Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='map_to_odom_tf',
            arguments=[
                '--x', '0',
                '--y', '0',
                '--z', '0',
                '--yaw', '0',
                '--frame-id', 'map',
                '--child-frame-id', 'odom'
            ]
    )
    map_server = Node(
        package='nav2_map_server',
        executable='map_server', 
        name='map_server', 
        output='screen',
        parameters=[
            {'yaml_filename': map_yaml_path}, 
            {'use_bond': True}
        ]
    )
    lifecycle_manager = Node(
        package='nav2_lifecycle_manager', 
        executable='lifecycle_manager', 
        name='lifecycle_manager', 
        output='screen',
        parameters=[
            {'node_names': ['map_server']},
            {'autostart': True},
            {'bond_timeout': 10.0}
        ]
    )

    # RViz
    rviz = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        parameters=[
            {
                'use_sim_time': True
            }
        ]
    )

    return LaunchDescription([
        world_launch,
        lifecycle_manager,
        map_server,
        map_odom_tf,
        rviz
    ])