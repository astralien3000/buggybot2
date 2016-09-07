#include <messages/servo_action.hpp>
#include <messages/servo_config.hpp>

#include <ros/ros.h>

#include <sstream>
#include <vector>

class ServoConfigManager {
private:
  ros::NodeHandle& n;
  std::vector<int> index;

  void addToIndex(int id) {
    for(uint32_t i = 0 ; i < index.size() ; i++) {
      if(index[i] == id) {
	return;
      }
    }

    index.push_back(id);
    n.setParam("configs", index);
  }

  std::string paramName(int id) {
    std::stringstream ss;
    ss << "configs/" << id;
    return ss.str();
  }
  
public:
  ServoConfigManager(ros::NodeHandle& n)
    : n(n) {
    n.getCachedParam("configs", index);
  }
  
  ServoConfig get(int id) {
    ServoConfig ret;
    std::string pname = paramName(id);
    n.getCachedParam(pname, ret);
    if(ret.id != id) {
      ret.id = id;
      n.setParam(pname, ret);
      addToIndex(id);
    }
    return ret;
  }
  
  ServoConfig get(std::string label) {
    for(uint32_t i = 0 ; i < index.size() ; i++) {
      ServoConfig tmp;
      n.getCachedParam(paramName(index[i]), tmp);
      if(tmp.label == label) {
	return tmp;
      }
    }
    return ServoConfig();
  }
};

class Embed2ServoManager {
private:
  ros::NodeHandle& n;
  ServoConfigManager& configs;
  ros::Subscriber sub_embed_in;
  ros::Publisher  pub_servo_in;

  void callback(const HardwareServoAction& hsa) {
    ServoConfig config = configs.get(hsa.id);

    if(config.ok()) {
      ServoAction sa;
      sa.label = config.label;
      sa.enable = false;
      sa.angle = config.pos2angle(hsa.position);

      pub_servo_in.publish(sa);
    }
  }

public:
  Embed2ServoManager(ros::NodeHandle& n, ServoConfigManager& configs)
    : n(n), configs(configs),
      sub_embed_in(n.subscribe("embed/in", 1, &Embed2ServoManager::callback, this)),
      pub_servo_in(n.advertize<ServoAction>("servo/in", 1)) {
  }
};

class Servo2EmbedManager {
private:
  ros::NodeHandle& n;
  ServoConfigManager& configs;
  ros::Subscriber sub_servo_out;
  ros::Publisher  pub_embed_out;

  void callback(const ServoAction& sa) {
    ServoConfig config = configs.get(sa.label);

    if(config.ok()) {
      HardwareServoAction hsa;
      hsa.id = config.id;
      hsa.enable= sa.enable;
      hsa.position = config.angle2pos(sa.angle);
      
      pub_embed_out.publish(hsa);
    }
  }
  
public:
  Servo2EmbedManager(ros::NodeHandle& n, ServoConfigManager& configs)
    : n(n), configs(configs),
      sub_servo_out(n.subscribe("servo/out", 1, &Servo2EmbedManager::callback, this)),
      pub_embed_out(n.advertize<HardwareServoAction>("embed/out", 1)) {
  }
};

int main(int argc, char* argv[]) {
  ros::init(argc, argv, "servo-mapper");

  ros::NodeHandle n;
  ServoConfigManager configs(n);

  Embed2ServoManager e2s(n, configs);
  Servo2EmbedManager s2e(n, configs);
  
  ros::Rate loop_rate(30);

  while(ros::ok()) {
    ros::spinOnce();
    loop_rate.sleep();
  }
  
  return 0;
}

