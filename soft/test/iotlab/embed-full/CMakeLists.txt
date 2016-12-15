cmake_minimum_required(VERSION 2.8)

set(NAME embed-io)
project(${NAME} CXX C ASM)

set(CMAKE_CXX_STANDARD 11)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

link_directories("${CONAN_LIB_DIRS}")
include_directories("${CONAN_INCLUDE_DIRS}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE SOURCE_CPP "src/*.cpp")
file(GLOB_RECURSE SOURCE_HPP "src/*.hpp")
file(GLOB_RECURSE SOURCE_C "src/*.c")
file(GLOB_RECURSE SOURCE_H "src/*.h")
file(GLOB_RECURSE SOURCE_S "src/*.s")

set(SOURCE
  ${SOURCE_CPP}
  ${SOURCE_HPP}
  ${SOURCE_C}
  ${SOURCE_H}
  ${SOURCE_S}
  )

add_executable(${NAME} ${SOURCE})

if(CONAN_LIBS)
  target_link_libraries(${NAME} ${CONAN_LIBS})
endif()
