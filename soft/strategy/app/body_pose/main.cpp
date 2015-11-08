#include <iostream>
#include <unistd.h>

#include "body_pose_node.hpp"

int main(int argc, char** argv) {
  BodyPoseNode node(argc, argv);
  while(true) sleep(1);
  return 0;
}
