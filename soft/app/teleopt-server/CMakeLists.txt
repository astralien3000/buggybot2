cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(NAME teleopt)
project(${NAME})

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../lib/")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../lib/cereal/include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

link_directories("${CONAN_LIB_DIRS}")
include_directories("${CONAN_INCLUDE_DIRS}")

add_executable(${NAME} main.cpp)
target_link_libraries(${NAME} zmq)

if(CONAN_LIBS)
  target_link_libraries(${NAME} ${CONAN_LIBS})
endif()
