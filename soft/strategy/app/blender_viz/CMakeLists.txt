add_custom_command(
  OUTPUT test.py
  COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/test.py .
  MAIN_DEPENDENCY ${CMAKE_CURRENT_SOURCE_DIR}/test.py
  COMMENT "cp test.py"
  )

add_custom_command(
  OUTPUT buggybot2.blend
  COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/buggybot2.blend .
  MAIN_DEPENDENCY ${CMAKE_CURRENT_SOURCE_DIR}/buggybot2.blend
  COMMENT "cp buggybot2.blend"
  )

add_custom_target(
  test_py
  ALL 
  DEPENDS test.py
  )

add_custom_target(
  buggybot2_blend
  ALL 
  DEPENDS buggybot2.blend
  )

add_library(
  blender_viz
  SHARED
  main.cpp
  blender_viz_node.cpp
  )

target_link_libraries(
  blender_viz
  TAO
  TAO_AnyTypeCode
  ACE
  OpenDDS_Dcps
  )

target_link_libraries(
  blender_viz
  messages
  buggybot_2015_mgd
  mgd
  )

include_directories(${CMAKE_BINARY_DIR}/lib/messages)
include_directories(${CMAKE_SOURCE_DIR}/lib/buggybot_2015_mgd)
include_directories(${CMAKE_SOURCE_DIR}/lib/mgd)
include_directories(/usr/include/eigen3)
