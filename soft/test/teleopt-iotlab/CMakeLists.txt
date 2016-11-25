cmake_minimum_required(VERSION 3.1)

set(NAME teleopt-iotlab)
project(${NAME} CXX C ASM)

set(CMAKE_CXX_STANDARD 11)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

link_directories("${CONAN_LIB_DIRS}")
include_directories("${CONAN_INCLUDE_DIRS}")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../../lib/cereal/include")

add_executable(${NAME} main.cpp)

if(CONAN_LIBS)
  target_link_libraries(${NAME} ${CONAN_LIBS})
endif()
target_link_libraries(${NAME} zmq)
