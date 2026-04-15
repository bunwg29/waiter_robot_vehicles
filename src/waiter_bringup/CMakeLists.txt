cmake_minimum_required(VERSION 3.8)
project(waiter_bringup)

find_package(ament_cmake REQUIRED)

install(DIRECTORY launch config
  DESTINATION share/${PROJECT_NAME}
)

install(PROGRAMS
  scripts/run_full_auto_cycle.sh
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
