cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(serial-controller)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5SerialPort REQUIRED)

include_directories("/usr/local/AversivePlusPlus/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../lib")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../lib/cereal/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../lib/nzmqt/include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE PROTOCOL "${CMAKE_CURRENT_SOURCE_DIR}/../../lib/protocol/*")
file(GLOB_RECURSE MSG "${CMAKE_CURRENT_SOURCE_DIR}/../../lib/messages/*.hpp")

add_executable(serial-controller main.cpp port_client.hpp ${PROTOCOL} ${MSG})
target_link_libraries(serial-controller Qt5::Core Qt5::SerialPort)
target_link_libraries(serial-controller zmq)
