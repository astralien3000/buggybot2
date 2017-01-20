#include "model.hpp"
#include "anim_control/walk.hpp"
#include "anim_control/turn.hpp"
#include "ik/robot_armature_joint_forearm_lf_endpoint.hpp"
#include "ik/robot_armature_joint_forearm_rf_endpoint.hpp"
#include "ik/robot_armature_joint_forearm_rb_endpoint.hpp"
#include "ik/robot_armature_joint_forearm_lb_endpoint.hpp"

#include <stdio.h>
#include <xtimer.h>

namespace LF { using namespace robot_armature_joint_forearm_lf_endpoint; }
namespace RF { using namespace robot_armature_joint_forearm_rf_endpoint; }
namespace RB { using namespace robot_armature_joint_forearm_rb_endpoint; }
namespace LB { using namespace robot_armature_joint_forearm_lb_endpoint; }

template<int r, int c> using matrix = real[r*c];

AnimWalk walk;
AnimTurn turn;
LegAction legs[4];
real ik_angles[12] = {0,0,1.57,0,0,1.57,0,0,1.57,0,0,1.57};
double angles[12] = {0,0,1.57,0,0,1.57,0,0,1.57,0,0,1.57};
uint16_t cmds[12] = {512,512,512,512,512,512,512,512,512,512,512,512};

static constexpr real coeff = 0.006;
static constexpr real stop_dist = -1.0;
static constexpr int max_iter = 10;

void control_loop(void) {
  for(int i = 0 ; i < 12 ; i++) {
    ik_angles[i] = convert[i].angle2ik((double)ik_angles[i]);
  }

  while(1) {
    thread_yield();
    puts("ANIM");
    if(command == 'f') {
      walk.update(legs[0], legs[1], legs[2], legs[3]);
    }
    else {
      turn.update(legs[0], legs[1], legs[2], legs[3]);
    }
    puts("I");
    LF::inverse_kinematics(matrix<4,1>{legs[0].x, legs[0].y, legs[0].z, 1}, ik_angles[0],  ik_angles[1],  ik_angles[2], coeff, stop_dist, max_iter);
    RF::inverse_kinematics(matrix<4,1>{legs[1].x, legs[1].y, legs[1].z, 1}, ik_angles[3],  ik_angles[4],  ik_angles[5], coeff, stop_dist, max_iter);
    RB::inverse_kinematics(matrix<4,1>{legs[2].x, legs[2].y, legs[2].z, 1}, ik_angles[6],  ik_angles[7],  ik_angles[8], coeff, stop_dist, max_iter);
    LB::inverse_kinematics(matrix<4,1>{legs[3].x, legs[3].y, legs[3].z, 1}, ik_angles[9], ik_angles[10], ik_angles[11], coeff, stop_dist, max_iter);
    puts("S");
    for(int i = 0 ; i < 12 ; i++) {
      angles[i] = convert[i].ik2angle((double)ik_angles[i]);
      cmds[i] = config[i].angle2pos(angles[i]);
      if(cmds[i] < 1024) {
        sc.enableTorque(map[i]);
        xtimer_usleep(200);
        sc.setPosition(map[i], cmds[i]);
        xtimer_usleep(200);
      }
      else {
        printf("ERROR %s : %d \n", labels[i], (int)(angles[i]*180.0/3.1415));
      }
    }
    puts("END");
  }
}
