#include "body_pose_node.hpp"

#include <dds/DdsDcpsInfrastructureC.h>
#include <dds/DdsDcpsPublicationC.h>

#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/WaitSet.h>

#include <dds/DCPS/StaticIncludes.h>

#include <buggybot_2015_mgd.hpp>

struct BodyPoseNode::PrivateData {
  DDS::DomainParticipantFactory_var dpf;
  DDS::DomainParticipant_var participant;
  
  Buggybot::JointAnglesTypeSupport_var type_support;
  DDS::Topic_var joint_angles_topic;
  DDS::Subscriber_var subscriber;
  DDS::DataReaderListener_var listener;
  DDS::DataReader_var reader;

  Buggybot::EntityPositionTypeSupport_var ep_type_support;
  DDS::Topic_var ep_topic;
  DDS::Publisher_var ep_publisher;
  Buggybot::EntityPositionDataWriter_var ep_writer;
  Buggybot::EntityPosition ep_msg;

  Buggybot2015MGD mgd;
};

class DataReaderListenerImpl : public DDS::DataReaderListener {
private:
  BodyPoseNode& _node;
  
public:
  DataReaderListenerImpl(BodyPoseNode& node)
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


BodyPoseNode::BodyPoseNode(int argc, char* argv[]) {
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

    // Register TypeSupport
    _data->ep_type_support = 
      new Buggybot::EntityPositionTypeSupportImpl;

    if(DDS::RETCODE_OK != _data->ep_type_support->register_type(_data->participant, "")) {
      std::cerr << "register_type failed" << std::endl;
      exit(-1);
    }

    // Create topic
    {
      CORBA::String_var type_name =
	_data->ep_type_support->get_type_name();
      
      _data->ep_topic =
	_data->participant->create_topic("endpoint_position", type_name, TOPIC_QOS_DEFAULT, 0, OpenDDS::DCPS::DEFAULT_STATUS_MASK);
      
      if(!_data->ep_topic) {
	std::cerr << "create_topic failed" << std::endl;
	exit(-1);
      }
    }
      
    // Create publisher
    _data->ep_publisher =
      _data->participant->create_publisher(PUBLISHER_QOS_DEFAULT, 0, OpenDDS::DCPS::DEFAULT_STATUS_MASK);
    
    if(!_data->ep_publisher) {
      std::cerr << "create_publisher failed" << std::endl;
      exit(-1);
    }

    // Create data writer
    {
      DDS::DataWriter_var writer =
	_data->ep_publisher->create_datawriter(_data->ep_topic, DATAWRITER_QOS_DEFAULT, 0, OpenDDS::DCPS::DEFAULT_STATUS_MASK);
      
      if(!writer) {
	std::cerr << "create_datawriter failed" << std::endl;
	exit(-1);
      }
      
      // Test Writer
      _data->ep_writer =
	Buggybot::EntityPositionDataWriter::_narrow(writer);
    }
    
  }
  catch (const CORBA::Exception& e) {
    e._tao_print_exception("Exception caught in BodyPodeNode constructor");
    exit(-1);
  }
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
    _data->ep_writer->write(_data->ep_msg, DDS::HANDLE_NIL);
  };

  write_entity_pos("lf", "lf.endpoint");
  write_entity_pos("lb", "lb.endpoint");
  write_entity_pos("rf", "rf.endpoint");
  write_entity_pos("rb", "rb.endpoint");
}
