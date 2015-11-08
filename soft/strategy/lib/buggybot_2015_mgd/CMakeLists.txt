add_library(
  buggybot_2015_mgd
  buggybot_2015_mgd.hpp buggybot_2015_mgd.cpp
  )

target_link_libraries(
  buggybot_2015_mgd
  mgd
  )

include_directories(/usr/include/eigen3)
include_directories(${CMAKE_SOURCE_DIR}/lib/mgd)