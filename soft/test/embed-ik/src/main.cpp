#include "robot_armature_joint_forearm_lf_endpoint.hpp"
#include "trigo.hpp"

#include <math.h>
#include <stdio.h>

#include <base/integer.hpp>

using namespace Aversive::Base;

using namespace robot_armature_joint_forearm_lf_endpoint;

int main(int, char**) {
  matrix<4,1> target { 90,90,-160, 1 };
  real q0 = 0;
  real q1 = 0;
  real q2 = -3.1415/2;
  
  puts("BEGIN");
  if(0) {
    puts("FORWARD");
    for(int i = 0 ; i < 1000 ; i++) {
      forward_kinematics(q0,q1,q2, target);
      printf("%f %f %f\n", (double)target[0], (double)target[1], (double)target[2]);
    }
  }
  else {
    puts("INVERSE");
    //int iter = inverse_kinematics(target, q0,q1,q2, 0.006, 6, 100000);
    int iter = inverse_kinematics(target, q0,q1,q2, 0.006, -1, 1000);
    forward_kinematics(q0,q1,q2, target);
    printf("[%d] %f %f %f\n", iter, (double)target[0], (double)target[1], (double)target[2]);
  }
  puts("END");
  
  return 0;
}
