cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(ik)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5SerialPort REQUIRED)

link_directories("/usr/local/AversivePlusPlus/lib/native")
include_directories("/usr/local/AversivePlusPlus/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../lib")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../lib/cereal/include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(ik main.cpp ik_export.hpp)
target_link_libraries(ik Qt5::Core Qt5::SerialPort Qt5::Widgets)
target_link_libraries(ik Aversive++)
target_link_libraries(ik zmq)
