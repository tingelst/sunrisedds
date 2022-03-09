cmake_minimum_required(VERSION 3.5)
project(sunrisedds_interfaces)

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
                           "msg/DirectServo.msg"
                           "msg/JointPosition.msg"
                           "msg/JointQuantity.msg"
                           "msg/ServoCommand.msg"
                           "msg/SmartServo.msg"
                           "msg/SmartServoLin.msg"
                           DEPENDENCIES
                           geometry_msgs
                           std_msgs)

ament_export_dependencies(rosidl_default_runtime)
ament_package()
