cmake_minimum_required(VERSION 3.1.3 FATAL_ERROR)

project(embed-controller)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5SerialPort REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(embed-controller main.cpp port_client.hpp)
target_link_libraries(embed-controller Qt5::Core Qt5::SerialPort Qt5::Widgets)
