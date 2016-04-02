cmake_minimum_required(VERSION 3.1.3 FATAL_ERROR)

project(embed-controller)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5SerialPort REQUIRED)

link_directories("/usr/local/AversivePlusPlus/lib/native")
include_directories("/usr/local/AversivePlusPlus/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../lib")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../lib/cereal/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../lib/nzmqt/include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE PROTOCOL "${CMAKE_CURRENT_SOURCE_DIR}/../../lib/protocol/*")

add_executable(embed-controller main.cpp port_client.hpp ${PROTOCOL})
target_link_libraries(embed-controller Qt5::Core Qt5::SerialPort Qt5::Widgets)
target_link_libraries(embed-controller Aversive++)
target_link_libraries(embed-controller zmq)
