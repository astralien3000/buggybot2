cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(ik-test)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5SerialPort REQUIRED)

link_directories("/usr/local/AversivePlusPlus/lib/native")
include_directories("/usr/local/AversivePlusPlus/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../lib")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../lib/cereal/include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")

file(GLOB_RECURSE MSG "${CMAKE_CURRENT_SOURCE_DIR}/../../lib/messages/*.hpp")

file(GLOB SOURCE_CPP "*.cpp")
file(GLOB SOURCE_HPP "*.hpp")

add_executable(ik-test ${SOURCE_CPP} ${SOURCE_HPP} ${MSG})
target_link_libraries(ik-test Qt5::Core Qt5::SerialPort Qt5::Widgets)
target_link_libraries(ik-test Aversive++)
target_link_libraries(ik-test zmq)
