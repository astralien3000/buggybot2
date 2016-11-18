cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(servo-mapper)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../lib")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../lib/cereal/include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE MSG "${CMAKE_CURRENT_SOURCE_DIR}/../../lib/messages/*.hpp")

add_executable(servo-mapper main.cpp ${MSG})
target_link_libraries(servo-mapper zmq)
