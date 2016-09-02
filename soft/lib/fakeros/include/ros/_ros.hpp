#ifndef FAKEROS__ROS_HPP
#define FAKEROS__ROS_HPP

#include <zmq.hpp>

namespace ros {

  namespace Private {

    zmq::context_t& get_zmq_context(void) {
      static zmq::context_t ctx(5);
      return ctx;
    }
    
  }
  
  void init(int& argc, char** argv, const std::string& name) {}

  struct Publisher {
    template<typename M> void publish(const M& msg) {}
  };
  
  struct Subscriber {};

  struct NodeHandle {

    template<typename M> Subscriber subscribe(const std::string& topic, uint32_t queue_size, void(*callback)(const M&)) {}

    template<typename M, class T> Subscriber subscribe(const std::string& topic, uint32_t queue_size, void(T::*callback)(const M&), T*) {}

    template<typename M> Publisher advertize(const std::string& topic, uint32_t queue_size) {}

    template<typename T> T param(const std::string& name, const T& param_default) {}

  };

  struct Rate {
    Rate(uint32_t freq) {}
    void sleep(void) {}
  };

  bool ok(void) { return true; }

  void spinOnce(void) {}
}

#endif//FAKEROS__ROS_HPP
