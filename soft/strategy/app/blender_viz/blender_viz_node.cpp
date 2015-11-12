#include "blender_viz_node.hpp"

#include <dds/DdsDcpsInfrastructureC.h>
#include <dds/DdsDcpsPublicationC.h>

#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/WaitSet.h>

#include <dds/DCPS/StaticIncludes.h>

#include <buggybot_2015_mgd.hpp>

#include <sstream>

struct BlenderVizNode::PrivateData {
  DDS::DomainParticipantFactory_var dpf;
  DDS::DomainParticipant_var participant;
  
  Buggybot::JointAnglesTypeSupport_var type_support;
  DDS::Topic_var joint_angles_topic;
  DDS::Subscriber_var subscriber;
  DDS::DataReaderListener_var listener;
  DDS::DataReader_var reader;

  Buggybot2015MGD mgd;
};

class DataReaderListenerImpl : public DDS::DataReaderListener {
private:
  BlenderVizNode& _node;
  
public:
  DataReaderListenerImpl(BlenderVizNode& node)
    : _node(node) {
    
  }
  
  void on_data_available(DDS::DataReader_ptr reader) {
    std::cout << "data available" << std::endl;

    Buggybot::JointAnglesDataReader_var test_reader =
      Buggybot::JointAnglesDataReader::_narrow(reader);

    if(!test_reader) {
      std::cerr << "_narrow failed" << std::endl;
      return;
    }

    Buggybot::JointAngles msg;
    DDS::SampleInfo si;
    DDS::ReturnCode_t status = test_reader->take_next_sample(msg, si);

    if(status == DDS::RETCODE_OK) {
      _node.onJointAngles(msg);
    }
    else {
      std::cerr << "take_next_sample failed" << std::endl;
      return;
    }
  }

  void on_requested_deadline_missed(DDS::DataReader_ptr reader, const DDS::RequestedDeadlineMissedStatus& status) {}
  void on_requested_incompatible_qos(DDS::DataReader_ptr reader, const DDS::RequestedIncompatibleQosStatus& status) {}
  void on_sample_rejected(DDS::DataReader_ptr reader, const DDS::SampleRejectedStatus& status) {}
  void on_liveliness_changed(DDS::DataReader_ptr reader, const DDS::LivelinessChangedStatus& status) {}
  
  void on_subscription_matched(DDS::DataReader_ptr reader, const DDS::SubscriptionMatchedStatus& status) {
    std::cout << "match" << std::endl;
  }
  
  void on_sample_lost(DDS::DataReader_ptr reader, const DDS::SampleLostStatus& status) {}
};


BlenderVizNode::BlenderVizNode(int argc, char* argv[]) {
  _data = new PrivateData();

  try {
    // Initialize DomainParticipantFactory
    _data->dpf = TheParticipantFactoryWithArgs(argc, argv);

    // Create DomainParticipant
    _data->participant =
      _data->dpf->create_participant(42,
                              PARTICIPANT_QOS_DEFAULT,
                              0,
                              OpenDDS::DCPS::DEFAULT_STATUS_MASK);

    
    if (!_data->participant) {
      std::cerr << "create_participant failed" << std::endl;
      exit(-1);
    }

    // Register TypeSupport (Test)
    _data->type_support =
      new Buggybot::JointAnglesTypeSupportImpl;
    
    if(DDS::RETCODE_OK != _data->type_support->register_type(_data->participant, "")) {
      std::cerr << "register_type failed" << std::endl;
      exit(-1);
    }

    // Create topic
    {
      CORBA::String_var type_name =
	_data->type_support->get_type_name();
      
      _data->joint_angles_topic =
	_data->participant->create_topic("joint_angles", type_name, TOPIC_QOS_DEFAULT, 0, OpenDDS::DCPS::DEFAULT_STATUS_MASK);
      
      if(!_data->joint_angles_topic) {
	std::cerr << "create_topic failed" << std::endl;
	exit(-1);
      }
    }
      
    // Create _data->subscriber
    _data->subscriber =
      _data->participant->create_subscriber(SUBSCRIBER_QOS_DEFAULT, 0, OpenDDS::DCPS::DEFAULT_STATUS_MASK);

    if(!_data->subscriber) {
      std::cerr << "create_subscriber failed" << std::endl;
      exit(-1);
    }

    // Create listener
    _data->listener = new DataReaderListenerImpl(*this);

    // Create DataReader
    _data->reader =
      _data->subscriber->create_datareader(_data->joint_angles_topic,
					   DATAREADER_QOS_DEFAULT,
					   _data->listener,
					   OpenDDS::DCPS::DEFAULT_STATUS_MASK
					   );

    if(!_data->reader) {
      std::cerr << "create_datareader failed" << std::endl;
      exit(-1);
    }
    
  }
  catch (const CORBA::Exception& e) {
    e._tao_print_exception("Exception caught in BodyPodeNode constructor");
    exit(-1);
  }
}

BlenderVizNode::~BlenderVizNode(void) {
  delete _data;
}

void BlenderVizNode::onJointAngles(Buggybot::JointAngles msg) {
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

  auto keys = mgd.getMatrixList();
  for(int i = 0 ; i < keys.size() ; i++) {
    MGD::Matrix m =  mgd.getFullMatrix(keys[i]);
    std::ostringstream oss;
    oss << keys[i] << "#";
    for(int i = 0 ; i < 4 ; i++) {
      for(int j = 0 ; j < 4 ; j++) {
	oss << m(i,j) << ",";
      }
    }
    callback(oss.str().c_str());
  }
}
