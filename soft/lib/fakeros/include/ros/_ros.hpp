#ifndef FAKEROS__ROS_HPP
#define FAKEROS__ROS_HPP

#include <map>
#include <string>
#include <iostream>
using namespace std;

#include <cereal/archives/json.hpp>

namespace ros {

  void init(int& argc, char** argv, const std::string& name) {}

  struct Publisher {
    template<typename M> void publish(const M& msg) {}
  };
  
  struct Subscriber {};

  struct Callable {
    virtual void operator()(void*) { cout << "empty !" << endl; }
  };

  map<string, Callable*> _subs;
  
  struct NodeHandle {
    template<typename M, typename T>
    struct MethodCallable : public Callable {
      void(T::*method)(const M&);
      T* obj;

      MethodCallable(void(T::*m)(const M&), T* o) : method(m), obj(o) {}
      
      virtual void operator()(void* msg) { (obj->*method)(*(M*)msg); }
    };
    
    template<typename M> Subscriber subscribe(const std::string& topic, uint32_t queue_size, void(*callback)(const M&)) {}

    template<typename M, class T> Subscriber subscribe(const std::string& topic, uint32_t queue_size, void(T::*callback)(const M&), T* obj) {
      Callable* c = new MethodCallable<M, T>(callback, obj);
      _subs[topic] = c;
    }

    template<typename M> Publisher advertize(const std::string& topic, uint32_t queue_size) {}

    map<string, string> _p;
    
    template<typename T> T param(const std::string& name, const T& param_default) {
      if(_p.count(name) == 0) {
	stringstream ss;
	{
	  cereal::JSONOutputArchive ar(ss);
	  ar(param_default);
	}
	_p[name] = ss.str();
	cout << ss.str() << endl;
      }
      return param_default;
    }

  };

  struct Rate {
    Rate(uint32_t freq) {}
    void sleep(void) {}
  };

  bool ok(void) { return true; }

  void spinOnce(void) {
    HardwareServoAction hsa;
    (*(_subs.at("embed/in")))(&hsa);
  }
}

#endif//FAKEROS__ROS_HPP
