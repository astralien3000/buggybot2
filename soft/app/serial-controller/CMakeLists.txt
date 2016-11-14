cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(serial-controller)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5SerialPort REQUIRED)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../lib/")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../lib/cereal/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../lib/nzmqt/include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

link_directories("${CONAN_LIB_DIRS}")
include_directories("${CONAN_INCLUDE_DIRS}")

add_executable(serial-controller main.cpp port_client.hpp)
target_link_libraries(serial-controller Qt5::Core Qt5::SerialPort)
target_link_libraries(serial-controller zmq)

if(CONAN_LIBS)
  target_link_libraries(${NAME} ${CONAN_LIBS})
endif()
