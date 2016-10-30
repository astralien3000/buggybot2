#include <math.h>
#include "devices.hpp"
#include "robot_armature_joint_forearm_lf_endpoint.hpp"
#include "trigo.hpp"

using namespace robot_armature_joint_forearm_lf_endpoint;

#ifdef AVERSIVE_TOOLCHAIN_AVR
Stream::HAL::UARTStream<Settings> io;
Stream::FormattedStreamDecorator<decltype(io)> cout(io);

Stream::FormattedStreamDecorator<decltype(io)>& operator<<(Stream::FormattedStreamDecorator<decltype(io)>& stream, double val) {
  stream << (val<0?"-":"") << (int)fabs(val) << "." << (int)fabs((val-(double)((int)val))*1000);
  return stream;
}
#endif

int main(int, char**) {
  matrix<4,1> target { 90,90,-160, 1 };
  double q0 = 0;
  double q1 = 0;
  double q2 = -3.1415/2;

  cout << "BEGIN" << endl;
  if(0) {
    cout << "FORWARD" << endl;
    for(int i = 0 ; i < 1000 ; i++) {
      forward_kinematics(q0,q1,q2, target);
      //cout << target[0] << " " << target[1] << " " << target[2] << endl;
    }
  }
  else if(1) {
    cout << "INVERSE" << endl;
    inverse_kinematics(target, q0,q1,q2, 0.003, -1, 5000);
    forward_kinematics(q0,q1,q2, target);
    cout << target[0] << " " << target[1] << " " << target[2] << endl;
  }
  else {
    cout << "COS" << endl;
    const int max = 20;
    for(int i = 0 ; i < max ; i++) {
      const double val = ((2*PI)*i)/max - PI;
      cout << val << " => \t" << cos(val) << "\t" << MyCos::cos(val) << endl;
    }
  }
  cout << "END" << endl;
  
  while(1) {}
  return 0;
}
