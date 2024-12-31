cmake_minimum_required(VERSION 3.8)
project(more_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(rclcpp REQUIRED)

set(msg_files "msg/AddressBook.msg")
rosidl_generate_interfaces(${PROJECT_NAME} ${msg_files})

rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} rosidl_typesupport_cpp)

ament_export_dependencies(rosidl_default_runtime)

add_executable(publish_address_book src/publish_address_book.cpp)
target_link_libraries(publish_address_book "${cpp_typesupport_target}")

ament_target_dependencies(publish_address_book rclcpp)

install(TARGETS publish_address_book DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
