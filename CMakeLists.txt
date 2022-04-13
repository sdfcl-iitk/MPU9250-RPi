cmake_minimum_required(VERSION 3.15)

project(MPU9250)

include_directories(include)
add_executable(simple_rpy examples/simple_rpy.cpp)
target_link_libraries(simple_rpy -li2c)