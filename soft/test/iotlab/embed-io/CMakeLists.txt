cmake_minimum_required(VERSION 2.8)

set(NAME embed-io)
project(${NAME} CXX C ASM)

set(CMAKE_CXX_STANDARD 11)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

link_directories("${CONAN_LIB_DIRS}")
include_directories("${CONAN_INCLUDE_DIRS}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(${NAME} main.cpp server.cpp servo_handler.cpp anim_handler.cpp)

if(CONAN_LIBS)
  target_link_libraries(${NAME} ${CONAN_LIBS})
endif()
