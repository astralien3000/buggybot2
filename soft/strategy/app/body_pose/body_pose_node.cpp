#include "body_pose_node.hpp"

#include <dds/DdsDcpsInfrastructureC.h>
#include <dds/DdsDcpsPublicationC.h>

#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/WaitSet.h>

#include <dds/DCPS/StaticIncludes.h>

#include <reader_node.hpp>
#include <writer_node.hpp>

#include <buggybot_2015_mgd.hpp>

DEFINE_MSG_TYPE(JointAngles, Buggybot::JointAngles)
DEFINE_MSG_TYPE(EntityPosition, Buggybot::EntityPosition)

struct BodyPoseNode::PrivateData {
  ReaderNode<JointAngles> ja_reader;
  WriterNode<EntityPosition> ep_writer;
  Buggybot::EntityPosition ep_msg;
  Buggybot2015MGD mgd;

  PrivateData(BodyPoseNode* n, int argc, char* argv[])
    : ja_reader("test", [n](Buggybot::JointAngles msg){n->onJointAngles(msg);}, argc, argv),
      ep_writer("test2", argc, argv) {

  }
};

BodyPoseNode::BodyPoseNode(int argc, char* argv[]) {
  _data = new PrivateData(this, argc, argv);
}

BodyPoseNode::~BodyPoseNode(void) {
  delete _data;
}

void BodyPoseNode::onJointAngles(Buggybot::JointAngles msg) {
  auto& mgd = _data->mgd;
  
  mgd.updateParam("lf0", msg.lf0);
  mgd.updateParam("lf1", msg.lf1);
  mgd.updateParam("lf2", msg.lf2);

  mgd.updateParam("lb0", msg.lb0);
  mgd.updateParam("lb1", msg.lb1);
  mgd.updateParam("lb2", msg.lb2);

  mgd.updateParam("rf0", msg.rf0);
  mgd.updateParam("rf1", msg.rf1);
  mgd.updateParam("rf2", msg.rf2);

  mgd.updateParam("rb0", msg.rb0);
  mgd.updateParam("rb1", msg.rb1);
  mgd.updateParam("rb2", msg.rb2);

  auto write_entity_pos =
    [this](std::string ext_name, std::string mgd_name) {
    _data->ep_msg.id++;
    _data->ep_msg.name = ext_name.c_str();
    MGD::Matrix m = _data->mgd.getFullMatrix(mgd_name);
    auto v = Eigen::Matrix<double, 4, 1>();
    v[3] = 1;
    v = m * v;
    _data->ep_msg.x = v[0];
    _data->ep_msg.y = v[1];
    _data->ep_msg.z = v[2];
    _data->ep_writer.write(_data->ep_msg);
  };

  write_entity_pos("lf", "lf.endpoint");
  write_entity_pos("lb", "lb.endpoint");
  write_entity_pos("rf", "rf.endpoint");
  write_entity_pos("rb", "rb.endpoint");
}
