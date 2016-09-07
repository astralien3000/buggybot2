#ifndef FAKEROS_FAKEROS_HPP
#define FAKEROS_FAKEROS_HPP

#include <string>

namespace ros {

  void init(int& argc, char** argv, const std::string& name);

  struct Publisher {
    template<typename M> void publish(const M& msg) {
      (void) msg;
    }
  };
  
  struct Subscriber {};
  
  struct NodeHandle {
    
    template<typename M> Subscriber subscribe(const std::string& topic, uint32_t queue_size, void(*callback)(const M&)) {
      (void) topic;
      (void) queue_size;
      (void) callback;
      return Subscriber();
    }

    template<typename M, class T> Subscriber subscribe(const std::string& topic, uint32_t queue_size, void(T::*callback)(const M&), T* obj) {
      (void) queue_size;
      (void) topic;
      (void) callback;
      (void) obj;
      return Subscriber();
    }

    template<typename M> Publisher advertize(const std::string& topic, uint32_t queue_size) {
      (void) topic;
      (void) queue_size;
      return Publisher();
    }
    
    template<typename T> bool getParam(const std::string& name, const T& param) {
      (void) name;
      (void) param;
      return false;
    }

    template<typename T> bool getCachedParam(const std::string& name, const T& param) {
      (void) name;
      (void) param;
      return false;
    }

    template<typename T> void setParam(const std::string& name, const T& param) {
      (void) name;
      (void) param;
    }

  };

  struct Rate {
    Rate(uint32_t freq) {
      (void) freq;
    }
    void sleep(void);
  };

  inline bool ok(void) { return true; }

  inline void spinOnce(void) {}
}

#include <impl/impl.hpp>

#endif//FAKEROS_FAKEROS_HPP
