cmake_minimum_required(VERSION 3.8)
project(waiter_tasks)

find_package(ament_cmake REQUIRED)

install(PROGRAMS
  scripts/order_dispatcher.py
  scripts/auto_mapper.py
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch config
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
