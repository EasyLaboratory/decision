cmake_minimum_required(VERSION 3.0.2)
project(decision)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  perception_msgs
  roscpp
  std_msgs
)

find_package(Eigen3 REQUIRED)



catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES decision
 CATKIN_DEPENDS perception_msgs roscpp std_msgs 
#  DEPENDS system_lib
)


include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIR}
)

add_executable(fake_publisher src/fake_publisher.cpp)
target_link_libraries(fake_publisher ${catkin_LIBRARIES})

add_executable(decision src/decision.cpp)
target_link_libraries(decision ${catkin_LIBRARIES} ${EIGEN3_LIBRARIES})


