set(MSG_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_command(
  OUTPUT buggybot.idl
  COMMAND cp ${MSG_DIR}/buggybot.idl .
  MAIN_DEPENDENCY ${MSG_DIR}/buggybot.idl
  COMMENT "cp buggybot.idl"
  )

add_custom_command(
  OUTPUT buggybotC.cpp buggybotC.h buggybotS.cpp buggybotS.h
  COMMAND tao_idl buggybot.idl
  MAIN_DEPENDENCY buggybot.idl
  COMMENT "tao_idl buggybot.idl"
  )

add_custom_command(
  OUTPUT buggybotTypeSupport.idl buggybotTypeSupportImpl.cpp buggybotTypeSupportImpl.h
  COMMAND opendds_idl ${MSG_DIR}/buggybot.idl
  MAIN_DEPENDENCY ${MSG_DIR}/buggybot.idl
  COMMENT "opendds_idl buggybot.idl"
  )

add_custom_command(
  OUTPUT buggybotTypeSupportC.cpp buggybotTypeSupportC.h buggybotTypeSupportC.inl buggybotTypeSupportS.cpp buggybotTypeSupportS.h
  COMMAND tao_idl buggybotTypeSupport.idl
  MAIN_DEPENDENCY buggybotTypeSupport.idl
  COMMENT "tao_idl buggybotTypeSupport.idl"
  )

add_library(
  messages
  # Buggybot
  buggybotC.cpp buggybotC.h buggybotS.cpp buggybotS.h
  buggybotTypeSupportImpl.cpp buggybotTypeSupportImpl.h
  buggybotTypeSupportC.cpp buggybotTypeSupportC.h buggybotTypeSupportS.cpp buggybotTypeSupportS.h
  )

