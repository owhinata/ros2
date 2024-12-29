# ros2

Gazebo Turtlebot3
```bash
$ sudo apt-get install ros-humble-gazebo-* \
ros-humble-cartographer \
ros-humble-cartographer-ros \
ros-humble-navigation2 \
ros-humble-nav2-bringup \
ros-humble-dynamixel-sdk \
ros-humble-turtlebot3-msgs \
ros-humble-turtlebot3
```

TurtleBot3 Simulation
```bash
$ mkdir -p turtlebot3_ws/src
$ cd turtlebot3_ws
$ git clone -b humble-devel https://github.com/ROBOTIS-GIT/turtlebot3_simulations.git src/turtlebot3_simulations
$ colcon build --symlink-install
```

Gazeboの起動 ※ gazebo/setup.sh がないとだめ
```bash
$ export TURTLEBOT3_MODEL=burger
$ . /opt/ros/humble/setup.bash
$ . /usr/share/gazebo/setup.sh
```
