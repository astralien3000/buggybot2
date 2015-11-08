#include <iostream>
#include <unistd.h>

#include <dds/DdsDcpsInfrastructureC.h>
#include <dds/DdsDcpsPublicationC.h>

#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/WaitSet.h>

#include <dds/DCPS/StaticIncludes.h>

#include "buggybotTypeSupportImpl.h"


int main(int argc, char* argv[]) {
  try {
    // Initialize DomainParticipantFactory
    DDS::DomainParticipantFactory_var dpf =
      TheParticipantFactoryWithArgs(argc, argv);

    // Create DomainParticipant
    DDS::DomainParticipant_var participant =
      dpf->create_participant(42,
                              PARTICIPANT_QOS_DEFAULT,
                              0,
                              OpenDDS::DCPS::DEFAULT_STATUS_MASK);

    
    if (!participant) {
      std::cerr << "create_participant failed" << std::endl;
      return -1;
    }

    // Register TypeSupport (Test)
    Buggybot::JointAnglesTypeSupport_var ts =
      new Buggybot::JointAnglesTypeSupportImpl;

    if(DDS::RETCODE_OK != ts->register_type(participant, "")) {
      std::cerr << "register_type failed" << std::endl;
      return -1;
    }

    // Create topic
    CORBA::String_var type_name = ts->get_type_name();

    DDS::Topic_var topic = participant->create_topic("test_topic", type_name, TOPIC_QOS_DEFAULT, 0, OpenDDS::DCPS::DEFAULT_STATUS_MASK);

    if(!topic) {
      std::cerr << "create_topic failed" << std::endl;
      return -1;
    }
    
    // Create publisher
    DDS::Publisher_var pub = participant->create_publisher(PUBLISHER_QOS_DEFAULT, 0, OpenDDS::DCPS::DEFAULT_STATUS_MASK);
    if(!pub) {
      std::cerr << "create_publisher failed" << std::endl;
      return -1;
    }

    // Create data writer
    DDS::DataWriter_var writer = pub->create_datawriter(topic, DATAWRITER_QOS_DEFAULT, 0, OpenDDS::DCPS::DEFAULT_STATUS_MASK);
    if(!writer) {
      std::cerr << "create_datawriter failed" << std::endl;
      return -1;
    }

    // Test Writer
    Buggybot::JointAnglesDataWriter_var test_writer = Buggybot::JointAnglesDataWriter::_narrow(writer);

    /*
    // Block until Subscriber is available
    DDS::StatusCondition_var condition = 
      writer->get_statuscondition();
    condition->set_enabled_statuses(
				   DDS::PUBLICATION_MATCHED_STATUS);
    DDS::WaitSet_var ws = new DDS::WaitSet;
    ws->attach_condition(condition);
    while (true) {
      DDS::PublicationMatchedStatus matches;
      if (writer->get_publication_matched_status(matches) 
          != DDS::RETCODE_OK) {
        std::cerr << "get_publication_matched_status failed!" 
                  << std::endl;
        return 1;
      }
      if (matches.current_count >= 1) {
        break;
      }
      DDS::ConditionSeq conditions;
      DDS::Duration_t timeout = { 60, 0 };
      if (ws->wait(conditions, timeout) != DDS::RETCODE_OK) {
        std::cerr << "wait failed!" << std::endl;
        return 1;
      }
    }
    ws->detach_condition(condition);
    */
    
    // Publish
    int i = 0;
    while(1) {
      i++;
      Buggybot::JointAngles msg;
      msg.id = i;
      //msg.value = 42;
      //msg.text = "test";
      if(test_writer->write(msg, DDS::HANDLE_NIL) != DDS::RETCODE_OK) {
	std::cerr << "write failed" << std::endl;
	//return -1;
      }
      std::cout << "write" << std::endl;
      sleep(1);
    }
  }
  catch (const CORBA::Exception& e) {
    e._tao_print_exception("Exception caught in main():");
    return -1;
  }
  
  return 0;
}
