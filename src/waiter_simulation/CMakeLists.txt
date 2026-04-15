cmake_minimum_required(VERSION 3.8)
project(waiter_simulation)

find_package(ament_cmake REQUIRED)

install(DIRECTORY launch worlds config
  DESTINATION share/${PROJECT_NAME}
)

install(PROGRAMS
  scripts/odom_tf_broadcaster.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
