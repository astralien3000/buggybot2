#include <messages/servo_action.hpp>
#include <messages/servo_config.hpp>

#include <ros/ros.h>

#include <sstream>

ServoConfig default_config;

class Embed2ServoManager {
private:
  ros::NodeHandle& n;
  ros::Subscriber sub_embed_in;
  ros::Publisher  pub_servo_in;

  void callback(const HardwareServoAction& hsa) {
    std::stringstream ss;
    ss << "embed/" << hsa.id;
    ServoConfig config = n.param(ss.str(), default_config);

    ServoAction sa;
    sa.label = config.label;
    sa.enable = false;
    sa.angle = config.pos2angle(hsa.position);

    pub_servo_in.publish(sa);
  }

public:
  Embed2ServoManager(ros::NodeHandle& n)
    : n(n),
      sub_embed_in(n.subscribe("embed/in", 1, &Embed2ServoManager::callback, this)),
      pub_servo_in(n.advertize<ServoAction>("servo/in", 1)) {
  }
};

class Servo2EmbedManager {
private:
  ros::NodeHandle& n;
  ros::Subscriber sub_servo_out;
  ros::Publisher  pub_embed_out;

  void callback(const ServoAction& sa) {
    std::stringstream ss;
    ss << "servo/" << sa.label;
    ServoConfig config = n.param(ss.str(), default_config);

    HardwareServoAction hsa;
    hsa.id = config.id;
    hsa.enable= sa.enable;
    hsa.position = config.angle2pos(sa.angle);

    pub_embed_out.publish(hsa);
  }

public:
  Servo2EmbedManager(ros::NodeHandle& n)
    : n(n),
      sub_servo_out(n.subscribe("servo/out", 1, &Servo2EmbedManager::callback, this)),
      pub_embed_out(n.advertize<HardwareServoAction>("embed/out", 1)) {
  }
};

int main(int argc, char* argv[]) {
  ros::init(argc, argv, "servo-mapper");

  ros::NodeHandle n;

  Embed2ServoManager e2s(n);
  Servo2EmbedManager s2e(n);
  
  ros::Rate loop_rate(30);

  while(ros::ok()) {
    ros::spinOnce();
    loop_rate.sleep();
  }
  
  return 0;
}

