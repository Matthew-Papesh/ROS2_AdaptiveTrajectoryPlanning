import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node

def generate_launch_description():
    model_name = os.getenv('TURTLEBOT3_MODEL', 'burger')
    pkg_path = get_package_share_directory('turtlebot3_description')
    tb3_gazebo_dir = get_package_share_directory('turtlebot3_gazebo')
    world_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(tb3_gazebo_dir, 'launch', 'empty_world.launch.py')
        )
    )

    urdf_file = os.path.join(pkg_path, 'urdf', f'turtlebot3_{model_name}.urdf')
    robot_desc = None
    with open(urdf_file, 'r') as infp:
        robot_desc = infp.read()

    robot = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='screen',
        parameters=[{
            'use_sim_time': True, 
            'robot_description': robot_desc
        }]
    )

    rviz = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        parameters=[{'use_sim_time': True}],
        output='screen'
    )

    return LaunchDescription([
        world_launch,
        robot,
        rviz
    ])

