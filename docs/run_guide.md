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

### 1️⃣ Simulation Only (No Navigation)
```bash
ros2 launch waiter_bringup sim_demo.launch.py
```

### 2️⃣ Auto Mapping + Delivery (Full Cycle)
```bash
bash src/waiter_bringup/scripts/run_full_auto_cycle.sh
```
Phases:
1. Robot automatically explores the restaurant (SLAM mapping) → Saves map
2. Robot delivers food to tables 1 & 3

### 3️⃣ Only Mapping (Create Map)
```bash
ros2 launch waiter_bringup full_auto_mapping_demo.launch.py
```

### 4️⃣ Only Delivery (Using Existing Map)
```bash
ros2 launch waiter_bringup full_delivery_demo.launch.py delivery_sequence:="1,3"
```
Change tables: `delivery_sequence:="1,2,3,4"`

---

## Debug Commands
```bash
ros2 node list              # List all nodes
ros2 topic list             # List all topics
ros2 topic echo /odom       # View odometry data
ros2 topic echo /scan       # View LiDAR scan
ros2 action list            # List available actions
```

---

## Packages Structure
| Package | Purpose |
|---------|---------|
| `waiter_description` | URDF robot model (base, wheels, lidar) |
| `waiter_simulation` | Gazebo simulator + world |
| `waiter_navigation` | Nav2 + SLAM config + pre-built map |
| `waiter_msgs` | Custom messages & actions |
| `waiter_tasks` | Dispatcher & auto mapper nodes |
| `waiter_bringup` | Launch files orchestration |

---

## Configuration Files
- **Tables**: `src/waiter_navigation/config/tables.yaml` - Table positions & kitchen location
- **Waypoints**: `src/waiter_navigation/config/auto_mapping_waypoints.yaml` - Exploration path
- **Nav2 Params**: `src/waiter_navigation/config/nav2_params.yaml`
- **Map**: `src/waiter_navigation/maps/restaurant.{pgm,yaml}`

---

## Notes
- Default delivery: **Table 3**. Override with: `delivery_sequence:="1,3,4"`
- First-time users: Run **Setup** commands
- Mapping duration: ~5 minutes, Delivery: ~2 minutes
