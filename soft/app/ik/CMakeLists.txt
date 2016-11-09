cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(ik)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories("/usr/local/AversivePlusPlus/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../lib")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../lib/cereal/include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")

file(GLOB_RECURSE MSG "${CMAKE_CURRENT_SOURCE_DIR}/../../lib/messages/*.hpp")

file(GLOB SOURCE_CPP "*.cpp")
file(GLOB SOURCE_HPP "*.hpp")

add_executable(ik ${SOURCE_CPP} ${SOURCE_HPP} ${MSG})
target_link_libraries(ik zmq)
