# Waiter Robot - Quick Start Guide

ROS 2 Jazzy workspace for a simulated restaurant waiter robot using Gazebo,
Nav2, AMCL, SLAM Toolbox, and a simple delivery task node.

## Setup

Run these commands from a new terminal:

```bash
source /opt/ros/jazzy/setup.bash
colcon build --symlink-install
source install/setup.bash
```

After changing source files, rebuild and source again:

```bash
colcon build --symlink-install
source install/setup.bash
```

## Quick Run Commands

### 1. Delivery Mode

Runs Gazebo, loads the pre-built restaurant map, starts Nav2 localization and
navigation, then sends the robot through the delivery sequence.

```bash
ros2 launch waiter_bringup demo.launch.py
```

Default delivery sequence:

```text
Table 1 -> Kitchen -> Table 2 -> Kitchen -> ... -> Table 8 -> Kitchen
```

Run only selected tables:

```bash
ros2 launch waiter_bringup demo.launch.py delivery_sequence:="1,2"
```

Run all tables explicitly:

```bash
ros2 launch waiter_bringup demo.launch.py delivery_sequence:="1,2,3,4,5,6,7,8"
```

### 2. Mapping Mode

Runs Gazebo, starts SLAM Toolbox, and lets the robot auto-explore for 120
seconds.

```bash
ros2 launch waiter_bringup mapping.launch.py
```

After exploration, the map saver overwrites:

```text
src/waiter_navigation/maps/restaurant.pgm
src/waiter_navigation/maps/restaurant.yaml
```

The robot does not perform deliveries in mapping mode.

## Launch Files

| Launch file | Purpose |
| --- | --- |
| `waiter_bringup/launch/demo.launch.py` | Full delivery demo: simulation + Nav2 + waiter node |
| `waiter_bringup/launch/mapping.launch.py` | Full mapping demo: simulation + SLAM + auto explorer |
| `waiter_simulation/launch/simulation.launch.py` | Gazebo world, robot spawn, ROS-Gazebo bridges, odom TF |
| `waiter_navigation/launch/navigation.launch.py` | Map server, AMCL, Nav2 navigation stack |
| `waiter_navigation/launch/slam.launch.py` | SLAM Toolbox + Nav2 navigation stack |

## Configuration

| File | Purpose |
| --- | --- |
| `src/waiter_bringup/config/tables.yaml` | Kitchen and table goal poses |
| `src/waiter_navigation/config/nav2_params.yaml` | Nav2, AMCL, costmap, planner, controller parameters |
| `src/waiter_navigation/config/slam_params.yaml` | SLAM Toolbox parameters |
| `src/waiter_navigation/maps/restaurant.yaml` | Map metadata |
| `src/waiter_navigation/maps/restaurant.pgm` | Occupancy grid map image |
| `src/waiter_description/urdf/waiter.xacro` | Robot model |
| `src/waiter_simulation/worlds/restaurant.sdf` | Gazebo restaurant world |

The delivery map path is resolved through `FindPackageShare('waiter_navigation')`
in `navigation.launch.py`, so it is portable across different computers after
building the workspace. Do not hardcode `/home/<user>/...` map paths in
`nav2_params.yaml`.

## Debug Commands

```bash
ros2 node list
ros2 topic list
ros2 topic echo /odom
ros2 topic echo /scan
ros2 topic echo /cmd_vel
ros2 action list
ros2 action info /navigate_to_pose
ros2 run tf2_ros tf2_echo odom base_link
ros2 run tf2_ros tf2_echo map base_link
```

Check launch arguments:

```bash
ros2 launch waiter_navigation navigation.launch.py --show-args
```

## Troubleshooting

If `colcol` is not found, the command is misspelled. Use:

```bash
colcon build --symlink-install
```

If `map_server` prints `yaml-filename parameter is empty`, rebuild and source the
workspace again:

```bash
colcon build --symlink-install
source install/setup.bash
```

If Nav2 prints `Invalid frame ID "map"` or `Waiting for map`, check that
`navigation.launch.py` is launching `map_server` with the map argument and that
`restaurant.yaml` exists:

```bash
ls src/waiter_navigation/maps/restaurant.yaml
ros2 launch waiter_navigation navigation.launch.py --show-args
```

If Nav2 prints `Invalid frame ID "odom"` for a few seconds at startup, that can
happen while Gazebo is still spawning the robot. It should clear after `/odom`
starts publishing.

## Package Structure

| Package | Purpose |
| --- | --- |
| `waiter_description` | URDF/Xacro robot model |
| `waiter_simulation` | Gazebo world, robot spawning, bridges, odom TF |
| `waiter_navigation` | Nav2 config, SLAM config, map files, navigation launch |
| `waiter_bringup` | Top-level launch files and task scripts |
