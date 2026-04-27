#!/usr/bin/env bash
set -eo pipefail

source /opt/ros/jazzy/setup.bash
source "$(dirname "$0")/../../../install/setup.bash"
set -u

MAP_PREFIX_SRC="$(dirname "$0")/../../../src/waiter_navigation/maps/restaurant"
MAP_PREFIX_INSTALL="$(dirname "$0")/../../../install/waiter_navigation/share/waiter_navigation/maps/restaurant"

if pgrep -f "gz sim" >/dev/null 2>&1; then
	echo "[full_auto_cycle] Another Gazebo process is running."
	echo "[full_auto_cycle] Stop old simulation first, then run this script again."
	exit 1
fi

map_exists() {
	local prefix="$1"
	[[ -f "${prefix}.yaml" && -f "${prefix}.pgm" ]]
}

echo "[full_auto_cycle] Step 1/2: automatic mapping"
set +e
ros2 launch waiter_bringup full_auto_mapping_demo.launch.py
MAPPING_RC=$?
set -e

# The mapping launch may exit non-zero when launch is shutdown by design.
if [[ ${MAPPING_RC} -ne 0 ]]; then
	if map_exists "${MAP_PREFIX_SRC}" || map_exists "${MAP_PREFIX_INSTALL}"; then
		echo "[full_auto_cycle] Mapping launch exited with code ${MAPPING_RC}, but map files exist. Continuing."
	else
		echo "[full_auto_cycle] Mapping failed (exit ${MAPPING_RC}) and map files are missing."
		exit ${MAPPING_RC}
	fi
fi

echo "[full_auto_cycle] Step 2/2: delivery mission"
ros2 launch waiter_bringup full_delivery_demo.launch.py delivery_sequence:="1,3"