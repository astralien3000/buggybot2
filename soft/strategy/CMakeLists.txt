cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/messages)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/mgd)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/buggybot_2015_mgd)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/app/body_pose)