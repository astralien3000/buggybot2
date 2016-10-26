#include "robot_model.hpp"
#include "robot_armature_joint_forearm_lf_endpoint.hpp"
#include "robot_armature_joint_forearm_rf_endpoint.hpp"
#include "robot_armature_joint_forearm_lb_endpoint.hpp"
#include "robot_armature_joint_forearm_rb_endpoint.hpp"

namespace LF = robot_armature_joint_forearm_lf_endpoint;
namespace RF = robot_armature_joint_forearm_rf_endpoint;
namespace LB = robot_armature_joint_forearm_lb_endpoint;
namespace RB = robot_armature_joint_forearm_rb_endpoint;

double RobotModel::getAngle(Leg leg, int id) {
  if(leg != Leg::NONE) {
    return _angles[((int)leg)*3+id];
  }
  return 0;
}
  
void RobotModel::setAngle(Leg leg, int id, double angle) {
  if(leg != Leg::NONE) {
    _angles[((int)leg)*3+id] = angle;
  }
}

Matrix<double, 3,1> RobotModel::getEndpoint(Leg leg) {
  LF::matrix<4,1> ret {0.0,0.0,0.0,1.0};

  if(leg == Leg::LF) {
    const double q0 = getAngle(Leg::LF, 0);
    const double q1 = getAngle(Leg::LF, 1);
    const double q2 = getAngle(Leg::LF, 2);
    LF::forward_kinematics(q0,q1,q2, ret);
  }
  else if(leg == Leg::RF) {
    const double q0 = getAngle(Leg::RF, 0);
    const double q1 = getAngle(Leg::RF, 1);
    const double q2 = getAngle(Leg::RF, 2);
    RF::forward_kinematics(q0,q1,q2, ret);
  }
  else if(leg == Leg::LB) {
    const double q0 = getAngle(Leg::LB, 0);
    const double q1 = getAngle(Leg::LB, 1);
    const double q2 = getAngle(Leg::LB, 2);
    LB::forward_kinematics(q0,q1,q2, ret);
  }
  else if(leg == Leg::RB) {
    const double q0 = getAngle(Leg::RB, 0);
    const double q1 = getAngle(Leg::RB, 1);
    const double q2 = getAngle(Leg::RB, 2);
    RB::forward_kinematics(q0,q1,q2, ret);
  }

  return Matrix<double, 3,1>(ret[0], ret[1], ret[2]);
}

bool RobotModel::setEndpoint(Leg leg, Matrix<double, 3,1> pos) {
  LF::matrix<4,1> hpos {pos(0,0),pos(1,0),pos(2,0),1.0};

  if(leg == Leg::LF) {
    double q0 = getAngle(Leg::LF, 0);
    double q1 = getAngle(Leg::LF, 1);
    double q2 = getAngle(Leg::LF, 2);
    LF::inverse_kinematics_step(hpos, q0,q1,q2, _gain);
    setAngle(Leg::LF, 0, q0);
    setAngle(Leg::LF, 1, q1);
    setAngle(Leg::LF, 2, q2);
  }
  else if(leg == Leg::RF) {
    double q0 = getAngle(Leg::RF, 0);
    double q1 = getAngle(Leg::RF, 1);
    double q2 = getAngle(Leg::RF, 2);
    RF::inverse_kinematics_step(hpos, q0,q1,q2, _gain);
    setAngle(Leg::RF, 0, q0);
    setAngle(Leg::RF, 1, q1);
    setAngle(Leg::RF, 2, q2);
  }
  else if(leg == Leg::LB) {
    double q0 = getAngle(Leg::LB, 0);
    double q1 = getAngle(Leg::LB, 1);
    double q2 = getAngle(Leg::LB, 2);
    LB::inverse_kinematics_step(hpos, q0,q1,q2, _gain);
    setAngle(Leg::LB, 0, q0);
    setAngle(Leg::LB, 1, q1);
    setAngle(Leg::LB, 2, q2);
  }
  else if(leg == Leg::RB) {
    double q0 = getAngle(Leg::RB, 0);
    double q1 = getAngle(Leg::RB, 1);
    double q2 = getAngle(Leg::RB, 2);
    RB::inverse_kinematics_step(hpos, q0,q1,q2, _gain);
    setAngle(Leg::RB, 0, q0);
    setAngle(Leg::RB, 1, q1);
    setAngle(Leg::RB, 2, q2);
  }

  return false;
}
