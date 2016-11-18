cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(teleopt-client)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../lib/cereal/include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(teleopt-client ${HEADERS} ${SOURCES})
target_link_libraries(teleopt-client zmq)
