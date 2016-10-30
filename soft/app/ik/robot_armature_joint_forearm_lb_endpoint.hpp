#ifndef IK_ROBOT_ARMATURE_JOINT_FOREARM_LB_ENDPOINT_HPP
#define IK_ROBOT_ARMATURE_JOINT_FOREARM_LB_ENDPOINT_HPP

namespace robot_armature_joint_forearm_lb_endpoint {

template<int r, int c> using matrix = double[r*c];
void forward_kinematics(double q0, double q1, double q2, matrix<4, 1>& matrix_out);
double distance_from_target(const matrix<4, 1>& target, double q0_io, double q1_io, double q2_io, matrix<4, 1>& dist_out);
void inverse_kinematics_step(const matrix<4, 1>& target, double& q0_io, double& q1_io, double& q2_io, double coeff);
bool inverse_kinematics(const matrix<4, 1>& target, double& q0_io, double& q1_io, double& q2_io, double coeff, double stop_dist, int max_iter);

}

#endif//IK_ROBOT_ARMATURE_JOINT_FOREARM_LB_ENDPOINT_HPP
