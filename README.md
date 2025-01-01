# ros2

Link

- https://docs.ros.org/en/humble/index.html
- https://docs.ros2.org/latest/api/rclcpp/index.html
- https://docs.ros2.org/latest/api/rclpy/index.html
- https://github.com/gabrielnhn/ros2-line-follower
- https://www.originbot.org/en/application/deeplearning_line_follower/
- https://github.com/MM-X/self-driving-car

Gazebo Turtlebot3
```bash
sudo apt-get install ros-humble-gazebo-* \
ros-humble-cartographer \
ros-humble-cartographer-ros \
ros-humble-navigation2 \
ros-humble-nav2-bringup \
ros-humble-turtlebot3 \
ros-humble-turtlebot3-msgs \
ros-humble-turtlebot3-gazebo
```

Gazeboの起動 ※ gazebo/setup.sh がないとだめ
```bash
. /opt/ros/humble/setup.bash
. /usr/share/gazebo/setup.sh
export TURTLEBOT3_MODEL=waffle  # burger
ros2 launch turtlebot3_gazebo empty_world.launch.py
```

Gazeboの操作 (別端末)
```
. /opt/ros/humble/setup.bash
. /usr/share/gazebo/setup.sh
export TURTLEBOT3_MODEL=waffle
ros2 run turtlebot3_teleop teleop_keyboard
```
