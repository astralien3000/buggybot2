cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(optoforce)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5SerialPort REQUIRED)

link_directories("/usr/local/AversivePlusPlus/lib/native")
include_directories("/usr/local/AversivePlusPlus/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../lib")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../lib/cereal/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../lib/nzmqt/include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE MSG "${CMAKE_CURRENT_SOURCE_DIR}/../../lib/messages/*.hpp")

add_executable(optoforce main.cpp port_client.hpp parser.hpp ${PROTOCOL} ${MSG})
target_link_libraries(optoforce Qt5::Core Qt5::SerialPort)
target_link_libraries(optoforce Aversive++)
target_link_libraries(optoforce zmq)
