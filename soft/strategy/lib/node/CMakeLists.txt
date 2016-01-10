add_library(
  node
  node.hpp
  reader_node.hpp
  writer_node.hpp
  )

set_target_properties(node PROPERTIES LINKER_LANGUAGE CXX)
