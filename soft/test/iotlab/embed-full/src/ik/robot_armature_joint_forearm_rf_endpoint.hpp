#ifndef IK_ROBOT_ARMATURE_JOINT_FOREARM_RF_ENDPOINT_HPP
#define IK_ROBOT_ARMATURE_JOINT_FOREARM_RF_ENDPOINT_HPP

#include "trigo.hpp"

namespace robot_armature_joint_forearm_rf_endpoint {

template<int r, int c> using matrix = real[r*c];
void forward_kinematics(real q0, real q1, real q2, matrix<4, 1>& matrix_out);
real distance_from_target(const matrix<4, 1>& target, real q0_io, real q1_io, real q2_io, matrix<4, 1>& dist_out);
void inverse_kinematics_step(const matrix<4, 1>& target, real& q0_io, real& q1_io, real& q2_io, real coeff);
bool inverse_kinematics(const matrix<4, 1>& target, real& q0_io, real& q1_io, real& q2_io, real coeff, real stop_dist, int max_iter);

}

#endif//IK_ROBOT_ARMATURE_JOINT_FOREARM_RF_ENDPOINT_HPP
