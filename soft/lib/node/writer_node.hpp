#include "node.hpp"

template<typename MsgType>
class WriterNode {

  DDS::DomainParticipantFactory_var _dpf;
  DDS::DomainParticipant_var _participant;

  typename MsgType::TypeSupport_var _type_support;
  DDS::Topic_var _topic;
  DDS::Publisher_var _publisher;
  typename MsgType::DataWriter_var _writer;

public:

  WriterNode(const char* topic_name, int argc, char* argv[]) {
    try {
      // Initialize DomainParticipantFactory
      _dpf = TheParticipantFactoryWithArgs(argc, argv);

      // Create DomainParticipant
      _participant =
          _dpf->create_participant(42,
                                   PARTICIPANT_QOS_DEFAULT,
                                   0,
                                   OpenDDS::DCPS::DEFAULT_STATUS_MASK);


      if (!_participant) {
          std::cerr << "create_participant failed" << std::endl;
          exit(-1);
        }

      // Register TypeSupport
      _type_support =
          new typename MsgType::TypeSupportImpl;

      if(DDS::RETCODE_OK != _type_support->register_type(_participant, "")) {
          std::cerr << "register_type failed" << std::endl;
          exit(-1);
        }

      // Create topic
      {
        CORBA::String_var type_name =
            _type_support->get_type_name();

        _topic =
            _participant->create_topic(topic_name, type_name, TOPIC_QOS_DEFAULT, 0, OpenDDS::DCPS::DEFAULT_STATUS_MASK);

        if(!_topic) {
            std::cerr << "create_topic failed" << std::endl;
            exit(-1);
          }
      }

      // Create publisher
      _publisher =
          _participant->create_publisher(PUBLISHER_QOS_DEFAULT, 0, OpenDDS::DCPS::DEFAULT_STATUS_MASK);

      if(!_publisher) {
          std::cerr << "create_publisher failed" << std::endl;
          exit(-1);
        }

      // Create data writer
      {
        DDS::DataWriter_var writer =
            _publisher->create_datawriter(_topic, DATAWRITER_QOS_DEFAULT, 0, OpenDDS::DCPS::DEFAULT_STATUS_MASK);

        if(!writer) {
            std::cerr << "create_datawriter failed" << std::endl;
            exit(-1);
          }

        // Test Writer
        _writer =
            MsgType::DataWriter::_narrow(writer);
      }

    }
    catch (const CORBA::Exception& e) {
      e._tao_print_exception("Exception caught in BodyPodeNode constructor");
      exit(-1);
    }
  }

  void write(typename MsgType::Msg msg) {
    typename MsgType::DataWriter_var test_writer = MsgType::DataWriter::_narrow(_writer);

    if(test_writer->write(msg, DDS::HANDLE_NIL) != DDS::RETCODE_OK) {
      std::cerr << "write failed" << std::endl;
      return;
    }
    std::cout << "write" << std::endl;
  }
};
