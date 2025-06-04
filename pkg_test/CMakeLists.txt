cmake_minimum_required(VERSION 3.8)
project(pkg_test)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
include_directories(
  include/pkg_test
)

# Build library with logic (without main)
add_library(hello_world_lib
  src/pub.cpp
  src/sub.cpp
)
ament_target_dependencies(hello_world_lib rclcpp std_msgs)

# Declare executable target for the publisher (with main)
add_executable(hello_world_publisher src/main_pub.cpp)
target_link_libraries(hello_world_publisher hello_world_lib)
ament_target_dependencies(hello_world_publisher rclcpp std_msgs)

# Declare executable target for the subscriber (with main)
add_executable(hello_world_subscriber src/main_sub.cpp)
target_link_libraries(hello_world_subscriber hello_world_lib)
ament_target_dependencies(hello_world_subscriber rclcpp std_msgs)

# Install executables
install(TARGETS
  hello_world_publisher
  hello_world_subscriber
  DESTINATION lib/${PROJECT_NAME})


install(PROGRAMS
  pkg_test/sub_node.py
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  find_package(ament_cmake_gtest REQUIRED)
  find_package(std_msgs REQUIRED)
  find_package(ament_cmake_python REQUIRED)
  find_package(ament_cmake_pytest REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)

  ament_add_gtest(test_${PROJECT_NAME}
    test/test_pub_sub.cpp
  )


  set(ament_cmake_flake8_FOUND TRUE)

  ament_add_pytest_test(
    test_python_subscriber
    test/test_sub_node.py
    PYTHON_EXECUTABLE ${PYTHON_EXECUTABLE}
  )
  target_link_libraries(test_${PROJECT_NAME} hello_world_lib)
  ament_target_dependencies(test_${PROJECT_NAME} rclcpp std_msgs)

  ament_lint_auto_find_test_dependencies()
endif()
ament_python_install_package(pkg_test)
ament_package()


# per controllare il test