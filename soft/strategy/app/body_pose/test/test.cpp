#include <iostream>
#include <unistd.h>
#include <cmath>

#include <dds/DdsDcpsInfrastructureC.h>
#include <dds/DdsDcpsPublicationC.h>

#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/WaitSet.h>

#include <dds/DCPS/StaticIncludes.h>

#include "buggybotTypeSupportImpl.h"
#include <writer_node.hpp>

DEFINE_MSG_TYPE(JointAngles, Buggybot::JointAngles)

int main(int argc, char* argv[]) {

  WriterNode<JointAngles> node("test", argc, argv);

  // Publish
  int i = 0;
  while(1) {
      i++;
      Buggybot::JointAngles msg;
      msg.id = i;
      msg.lf0 = i*3.14/180.0;
      //msg.value = 42;
      //msg.text = "test";
      node.write(msg);
      usleep(1000000);
    }

  return 0;
}
