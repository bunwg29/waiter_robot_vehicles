#!/usr/bin/env bash
set -eo pipefail

source /opt/ros/jazzy/setup.bash
source "$(dirname "$0")/../../../install/setup.bash"

set -u

ros2 launch waiter_bringup full_auto_mapping_demo.launch.py
ros2 launch waiter_bringup full_delivery_demo.launch.py delivery_sequence:="1,3"