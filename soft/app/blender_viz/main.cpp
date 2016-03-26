#include "blender_viz_node.hpp"

static BlenderVizNode* node;

extern "C" {

  void init(int argc, char* argv[]) {
    node = new BlenderVizNode(argc, argv);
  }

  void quit(void) {
    delete node;
  }

  void set_callback(void (*func)(const char*, unsigned int)) {
    node->callback = func;
  }
  
}
