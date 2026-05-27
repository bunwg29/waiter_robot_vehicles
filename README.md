# Waiter Robot - Quick Start Guide

## Setup (First Time)

```bash
cd ~/waiter_robot_ws
source /opt/ros/jazzy/setup.bash
colcon build --symlink-install
source install/setup.bash
```

---

## Quick Run Commands

### 1. Delivery Mode (Auto Navigation)

Runs the automated food delivery sequence using the pre-built map.

```bash

```

- Default delivery sequence: **Table 1 -> Kitchen -> Table 3**.
- To override the sequence and visit all tables, run:

```bash
ros2 launch waiter_bringup demo.launch.py delivery_sequence:="1,2,3,4,5,6,7,8"
```

### 2. Mapping Mode (Auto SLAM)

Runs the SLAM algorithm and auto-explores the environment to generate a new map.

```bash
ros2 launch waiter_bringup mapping.launch.py
```

- The robot will automatically roam and scan the restaurant for 120 seconds.
- After 120 seconds, it automatically overwrites the map files (`restaurant.pgm` and `restaurant.yaml`).
- **Note:** The robot does NOT perform deliveries in this mode.

---

## Debug Commands

```bash
ros2 node list              # List all nodes
ros2 topic list             # List all topics
ros2 topic echo /odom       # View odometry data
ros2 topic echo /scan       # View LiDAR scan
```

---

## Packages Structure

| Package              | Purpose                                   |
| -------------------- | ----------------------------------------- |
| `waiter_description` | URDF robot model (base, wheels, lidar)    |
| `waiter_simulation`  | Gazebo simulator + world                  |
| `waiter_navigation`  | Nav2 + SLAM config + maps                 |
| `waiter_bringup`     | Launch files orchestration & main scripts |

---

## Configuration Files

- **Tables & Kitchen positions**: `src/waiter_bringup/config/tables.yaml`
- **Nav2 Params**: `src/waiter_navigation/config/nav2_params.yaml`
- **Map Files**: `src/waiter_navigation/maps/restaurant.{pgm,yaml}`
