add_executable(
  node.elf
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
  node.elf
  TAO
  TAO_AnyTypeCode
  ACE
  OpenDDS_Dcps
  )

target_link_libraries(
  node.elf
  messages
  )

include_directories(${CMAKE_BINARY_DIR}/lib/messages)
include_directories(/usr/include/eigen3)
