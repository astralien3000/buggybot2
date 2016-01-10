add_executable(
  body_pose_node.elf
  main.cpp
  body_pose_node.cpp
  )

add_executable(
  test.elf
  ${CMAKE_CURRENT_SOURCE_DIR}/test/test.cpp
  )

target_link_libraries(
  test.elf
  TAO
  TAO_AnyTypeCode
  ACE
  OpenDDS_Dcps
  )

target_link_libraries(
  test.elf
  messages
  )

target_link_libraries(
  body_pose_node.elf
  TAO
  TAO_AnyTypeCode
  ACE
  OpenDDS_Dcps
  )

target_link_libraries(
  body_pose_node.elf
  messages
  node
  buggybot_2015_mgd
  mgd
  )

include_directories(${CMAKE_BINARY_DIR}/lib/messages)

include_directories(${CMAKE_SOURCE_DIR}/lib/node)
include_directories(${CMAKE_SOURCE_DIR}/lib/buggybot_2015_mgd)
include_directories(${CMAKE_SOURCE_DIR}/lib/mgd)
include_directories(/usr/include/eigen3)
