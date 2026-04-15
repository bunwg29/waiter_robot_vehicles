# Waiter Robot - Run Guide (ROS2 Jazzy)

## 1) Workspace Architecture

Core packages:
- `waiter_description`: URDF/Xacro robot model (base, wheels, caster, lidar)
- `waiter_simulation`: Gazebo world + spawn launch + RViz config
- `waiter_navigation`: SLAM/AMCL/Nav2 configuration
- `waiter_tasks`: order dispatcher node (kitchen -> table -> wait -> kitchen)
- `waiter_msgs`: custom message/action definitions for task flow
- `waiter_bringup`: top-level launch orchestration

Node/topic data flow:
- `gz sim` + `ros_gz_sim create`
  - Subscribes: `/cmd_vel`
  - Publishes: `/odom`, `/tf` (odom -> base_link)
- `lidar` bridge plugin
  - Publishes: `/scan`
- `robot_state_publisher`
  - Publishes: `/tf`, `/tf_static`
- `nav2_bringup` (planner/controller/amcl/behavior tree)
  - Subscribes: `/map`, `/scan`, `/odom`, `/tf`
  - Action: `/navigate_to_pose`
  - Publishes: `/cmd_vel`
- `slam_toolbox` (mapping mode)
  - Subscribes: `/scan`, `/tf`
  - Publishes: `/map`, `/tf`
- `order_dispatcher.py`
  - Sends action goals to `/navigate_to_pose`
  - Delivery sequence: kitchen -> approach table -> wait 10s -> kitchen, repeated for each table in `delivery_sequence`

## 2) Build

```bash
cd ~/waiter_robot_ws
source /opt/ros/jazzy/setup.bash
colcon build --symlink-install
source install/setup.bash
```

## 3) Run Simulation Only

```bash
ros2 launch waiter_bringup sim_demo.launch.py
```

## 4) Run SLAM Mapping Mode (create map)

```bash
ros2 launch waiter_bringup full_mapping_demo.launch.py
```

If you want the robot to explore and save the map automatically:

```bash
ros2 launch waiter_bringup full_auto_mapping_demo.launch.py
```

Drive robot around to cover the restaurant, then save map:

```bash
ros2 run nav2_map_server map_saver_cli -f ~/waiter_robot_ws/src/waiter_navigation/maps/restaurant
```

## 5) Run Full Delivery Demo (AMCL + Global Planner + DWB + Dispatcher)

```bash
ros2 launch waiter_bringup full_delivery_demo.launch.py
```

If you want to force a specific mode, keep them separated:

```bash
ros2 launch waiter_bringup sim_demo.launch.py with_navigation:=true
ros2 launch waiter_bringup sim_demo.launch.py with_slam:=true
```

To run multiple deliveries in one session:

```bash
ros2 launch waiter_bringup full_delivery_demo.launch.py delivery_sequence:="1,3"
```

One-command automatic cycle for mapping first, then delivery:

```bash
ros2 run waiter_bringup run_full_auto_cycle.sh
```

## 6) Useful Debug Commands

```bash
ros2 topic list
ros2 topic echo /scan
ros2 topic echo /odom
ros2 action list
ros2 node list
```

## 7) Notes

- Map file is `waiter_navigation/maps/restaurant.yaml` + `restaurant.pgm`.
- Default delivery sequence is table 3. Override it with `delivery_sequence` when launching.
- In delivery mode: AMCL publishes `map -> odom` dynamically (no static map->odom TF).
- If localization drifts, publish initial pose in RViz (`2D Pose Estimate`) before sending goals.

## 8) Required ROS2 Packages

Install these if missing in your machine:

```bash
sudo apt update
sudo apt install -y \
  python3-colcon-common-extensions \
  ros-jazzy-navigation2 \
  ros-jazzy-nav2-bringup \
  ros-jazzy-nav2-dwb-controller \
  ros-jazzy-joint-state-publisher \
  ros-jazzy-joint-state-publisher-gui \
  ros-jazzy-slam-toolbox \
  ros-jazzy-ros-gz-sim \
  ros-jazzy-ros-gz-bridge
```
