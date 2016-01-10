#include "node.hpp"

#include <functional>


template<typename MsgType>
class ReaderNode : public DDS::DataReaderListener {
  DDS::DomainParticipantFactory_var _dpf;
  DDS::DomainParticipant_var _participant;

  typename MsgType::TypeSupport_var _type_support;
  DDS::Topic_var _topic;
  DDS::Subscriber_var _subscriber;
  DDS::DataReaderListener_var _listener;
  DDS::DataReader_var _reader;

  std::function<void (typename MsgType::Msg msg)> _on_data;

  void on_data_available(DDS::DataReader_ptr reader) {
    std::cout << "data available" << std::endl;

    typename MsgType::DataReader_var test_reader =
        MsgType::DataReader::_narrow(reader);

    if(!test_reader) {
        std::cerr << "_narrow failed" << std::endl;
        return;
      }

    typename MsgType::Msg msg;
    DDS::SampleInfo si;
    DDS::ReturnCode_t status = test_reader->take_next_sample(msg, si);

    if(status == DDS::RETCODE_OK) {
        if(_on_data) _on_data(msg);
        else std::cerr << "no data handler" << std::endl;
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

public:
  ReaderNode(const char* topic_name, std::function<void (typename MsgType::Msg msg)> on_data, int argc, char* argv[]) {
    _on_data = on_data;

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

      // Register TypeSupport (Test)
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

      // Create subscriber
      _subscriber =
          _participant->create_subscriber(SUBSCRIBER_QOS_DEFAULT, 0, OpenDDS::DCPS::DEFAULT_STATUS_MASK);

      if(!_subscriber) {
          std::cerr << "create_subscriber failed" << std::endl;
          exit(-1);
        }

      // Create listener
      _listener = this;

      // Create DataReader
      _reader =
          _subscriber->create_datareader(_topic,
                                        DATAREADER_QOS_DEFAULT,
                                        _listener,
                                        OpenDDS::DCPS::DEFAULT_STATUS_MASK
                                        );

      if(!_reader) {
          std::cerr << "create_datareader failed" << std::endl;
          exit(-1);
        }
    }
    catch (const CORBA::Exception& e) {
      e._tao_print_exception("Exception caught in ReaderNode constructor");
      exit(-1);
    }
  }
};
