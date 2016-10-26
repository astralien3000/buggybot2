#include <robot_armature_joint_forearm_rb_endpoint.hpp>
#include <math.h>

void robot_armature_joint_forearm_rb_endpoint::forward_kinematics(double q0, double q1, double q2, matrix<4, 1>& matrix_out) {
  double tmp0 = sin(q0);
  double tmp1 = cos(q0);
  double tmp2 = sin(q1);
  double tmp3 = -8.64589376997079*tmp0 - 6.90017899250355e-14*tmp1 + 1.05848594563834e-13;
  double tmp4 = tmp2*tmp3;
  double tmp5 = cos(q1);
  double tmp6 = tmp3*tmp5;
  double tmp7 = -5.02479315099866*tmp0 - 9.134832681132e-13*tmp1 - 1.82128001123844e-13;
  double tmp8 = tmp2*tmp7;
  double tmp9 = tmp5*tmp7;
  double tmp10 = 8.89999961853027*cos(q2);
  double tmp11 = 8.89999961853027*sin(q2);
  double tmp12 = -1.2294686774945e-7*tmp0 + 4.34438141703029*tmp1 - 4.34438250667868;
  double tmp13 = tmp12*tmp2;
  double tmp14 = tmp12*tmp5;
  double tmp15 = -7.14543099581207e-8*tmp0 + 2.52485382892848*tmp1 + 7.4751460358939;
  double tmp16 = tmp15*tmp2;
  double tmp17 = tmp15*tmp5;
  double tmp18 = 5.24993526716557e-9*tmp0 - 4.34438189548827*tmp1 + 4.34438097067571;
  double tmp19 = tmp18*tmp2;
  double tmp20 = tmp18*tmp5;
  double tmp21 = 9.03198452240611e-9*tmp0 - 7.47514638629668*tmp1 - 2.52485404308149;
  double tmp22 = tmp2*tmp21;
  double tmp23 = tmp21*tmp5;
  matrix_out[0] = 1.69736422700212e-7*tmp0 + 2.73152333634656e-6*tmp1 + tmp10*(-2.55252039812856e-33*tmp0 + 5.94826255241147e-20*tmp1 - 4.18571914906352e-8*tmp4 + 1.0*tmp6 + 1.0*tmp8 + 4.18571914906352e-8*tmp9 - 7.67902874431876e-47) - tmp11*(-4.29120382619812e-13*tmp0 + 10.0000011920976*tmp1 + 1.41952882825105e-13*tmp4 + 4.05864307006371e-17*tmp6 + 4.05864307006371e-17*tmp8 - 1.41952882825105e-13*tmp9 - 1.2909701937452e-26) - 3.66468626111782e-7*tmp4 + 7.0000009536743*tmp6 + 7.0000009536743*tmp8 + 3.66468626111782e-7*tmp9 - 89.9999999999982;
  matrix_out[1] = 1.37253354704556e-6*tmp0 - 8.52889758258442e-8*tmp1 + tmp10*(2.98887795569119e-20*tmp0 + 8.45859516091533e-28*tmp1 - 4.18571914906352e-8*tmp13 + 1.0*tmp14 + 1.0*tmp16 + 4.18571914906352e-8*tmp17 + 3.15173179980038e-33) - tmp11*(5.02479217361197*tmp0 + 1.42202804511937e-7*tmp1 + 1.41952882825105e-13*tmp13 + 4.05864307006371e-17*tmp14 + 4.05864307006371e-17*tmp16 - 1.41952882825105e-13*tmp17 + 5.29857609301366e-13) - 3.66468626111782e-7*tmp13 + 7.0000009536743*tmp14 + 7.0000009536743*tmp16 + 3.66468626111782e-7*tmp17 - 86.7499980675754;
  matrix_out[2] = -2.36164557899467e-6*tmp0 + 1.46752275225305e-7*tmp1 + tmp10*(-5.14280356738094e-20*tmp0 - 6.21406761657255e-29*tmp1 + 1.0*tmp19 + 4.18571914906352e-8*tmp20 - 4.18571914906352e-8*tmp22 + 1.0*tmp23 + 1.8317131986424e-33) - tmp11*(-8.64589304042811*tmp0 - 1.04468629328254e-8*tmp1 + 4.05864307006371e-17*tmp19 - 1.41952882825105e-13*tmp20 + 1.41952882825105e-13*tmp22 + 4.05864307006371e-17*tmp23 + 3.07940915664173e-13) + 7.0000009536743*tmp19 + 3.66468626111782e-7*tmp20 - 3.66468626111782e-7*tmp22 + 7.0000009536743*tmp23 - 45.9999950293924;
  matrix_out[3] = 1.00000000000000;
}

double robot_armature_joint_forearm_rb_endpoint::distance_from_target(const matrix<4, 1>& target, double q0_io, double q1_io, double q2_io, matrix<4, 1>& dist_out) {
  forward_kinematics(q0_io, q1_io, q2_io, dist_out);
  dist_out[0] = dist_out[0] - target[0];
  dist_out[1] = dist_out[1] - target[1];
  dist_out[2] = dist_out[2] - target[2];
  dist_out[3] = dist_out[3] - target[3];
  const double ret = sqrt(dist_out[0]*dist_out[0] + dist_out[1]*dist_out[1] + dist_out[2]*dist_out[2] + dist_out[3]*dist_out[3]);
  return ret;
}

void robot_armature_joint_forearm_rb_endpoint::inverse_kinematics_step(const matrix<4, 1>& target, double& q0_io, double& q1_io, double& q2_io, double coeff) {
  matrix<4, 1> dist;
  double dist_norm = distance_from_target(target, q0_io, q1_io, q2_io, dist);
  matrix<3, 1> delta;
  double tmp0 = sin(q0_io);
  double tmp1 = cos(q0_io);
  double tmp2 = sin(q1_io);
  double tmp3 = 6.90017899250355e-14*tmp0 - 8.64589376997079*tmp1;
  double tmp4 = tmp2*tmp3;
  double tmp5 = cos(q1_io);
  double tmp6 = tmp3*tmp5;
  double tmp7 = 9.134832681132e-13*tmp0 - 5.02479315099866*tmp1;
  double tmp8 = tmp2*tmp7;
  double tmp9 = tmp5*tmp7;
  double tmp10 = 8.89999961853027*cos(q2_io);
  double tmp11 = 8.89999961853027*sin(q2_io);
  double tmp12 = -4.34438141703029*tmp0 - 1.2294686774945e-7*tmp1;
  double tmp13 = tmp12*tmp2;
  double tmp14 = tmp12*tmp5;
  double tmp15 = -2.52485382892848*tmp0 - 7.14543099581207e-8*tmp1;
  double tmp16 = tmp15*tmp2;
  double tmp17 = tmp15*tmp5;
  double tmp18 = 4.34438189548827*tmp0 + 5.24993526716557e-9*tmp1;
  double tmp19 = tmp18*tmp2;
  double tmp20 = tmp18*tmp5;
  double tmp21 = 7.47514638629668*tmp0 + 9.03198452240611e-9*tmp1;
  double tmp22 = tmp2*tmp21;
  double tmp23 = tmp21*tmp5;
  double tmp24 = -8.64589376997079*tmp0 - 6.90017899250355e-14*tmp1 + 1.05848594563834e-13;
  double tmp25 = tmp2*tmp24;
  double tmp26 = tmp24*tmp5;
  double tmp27 = -5.02479315099866*tmp0 - 9.134832681132e-13*tmp1 - 1.82128001123844e-13;
  double tmp28 = tmp2*tmp27;
  double tmp29 = tmp27*tmp5;
  double tmp30 = -1.2294686774945e-7*tmp0 + 4.34438141703029*tmp1 - 4.34438250667868;
  double tmp31 = tmp2*tmp30;
  double tmp32 = tmp30*tmp5;
  double tmp33 = -7.14543099581207e-8*tmp0 + 2.52485382892848*tmp1 + 7.4751460358939;
  double tmp34 = tmp2*tmp33;
  double tmp35 = tmp33*tmp5;
  double tmp36 = 5.24993526716557e-9*tmp0 - 4.34438189548827*tmp1 + 4.34438097067571;
  double tmp37 = tmp2*tmp36;
  double tmp38 = tmp36*tmp5;
  double tmp39 = 9.03198452240611e-9*tmp0 - 7.47514638629668*tmp1 - 2.52485404308149;
  double tmp40 = tmp2*tmp39;
  double tmp41 = tmp39*tmp5;
  delta[0] = dist[0]*(-2.73152333634656e-6*tmp0 + 1.69736422700212e-7*tmp1 + tmp10*(-5.94826255241147e-20*tmp0 - 2.55252039812856e-33*tmp1 - 4.18571914906352e-8*tmp4 + 1.0*tmp6 + 1.0*tmp8 + 4.18571914906352e-8*tmp9) - tmp11*(-10.0000011920976*tmp0 - 4.29120382619812e-13*tmp1 + 1.41952882825105e-13*tmp4 + 4.05864307006371e-17*tmp6 + 4.05864307006371e-17*tmp8 - 1.41952882825105e-13*tmp9) - 3.66468626111782e-7*tmp4 + 7.0000009536743*tmp6 + 7.0000009536743*tmp8 + 3.66468626111782e-7*tmp9) + dist[1]*(8.52889758258442e-8*tmp0 + 1.37253354704556e-6*tmp1 + tmp10*(-8.45859516091533e-28*tmp0 + 2.98887795569119e-20*tmp1 - 4.18571914906352e-8*tmp13 + 1.0*tmp14 + 1.0*tmp16 + 4.18571914906352e-8*tmp17) - tmp11*(-1.42202804511937e-7*tmp0 + 5.02479217361197*tmp1 + 1.41952882825105e-13*tmp13 + 4.05864307006371e-17*tmp14 + 4.05864307006371e-17*tmp16 - 1.41952882825105e-13*tmp17) - 3.66468626111782e-7*tmp13 + 7.0000009536743*tmp14 + 7.0000009536743*tmp16 + 3.66468626111782e-7*tmp17) + dist[2]*(-1.46752275225305e-7*tmp0 - 2.36164557899467e-6*tmp1 + tmp10*(6.21406761657255e-29*tmp0 - 5.14280356738094e-20*tmp1 + 1.0*tmp19 + 4.18571914906352e-8*tmp20 - 4.18571914906352e-8*tmp22 + 1.0*tmp23) - tmp11*(1.04468629328254e-8*tmp0 - 8.64589304042811*tmp1 + 4.05864307006371e-17*tmp19 - 1.41952882825105e-13*tmp20 + 1.41952882825105e-13*tmp22 + 4.05864307006371e-17*tmp23) + 7.0000009536743*tmp19 + 3.66468626111782e-7*tmp20 - 3.66468626111782e-7*tmp22 + 7.0000009536743*tmp23);
  delta[1] = dist[0]*(tmp10*(-1.0*tmp25 - 4.18571914906352e-8*tmp26 - 4.18571914906352e-8*tmp28 + 1.0*tmp29) - tmp11*(-4.05864307006371e-17*tmp25 + 1.41952882825105e-13*tmp26 + 1.41952882825105e-13*tmp28 + 4.05864307006371e-17*tmp29) - 7.0000009536743*tmp25 - 3.66468626111782e-7*tmp26 - 3.66468626111782e-7*tmp28 + 7.0000009536743*tmp29) + dist[1]*(tmp10*(-1.0*tmp31 - 4.18571914906352e-8*tmp32 - 4.18571914906352e-8*tmp34 + 1.0*tmp35) - tmp11*(-4.05864307006371e-17*tmp31 + 1.41952882825105e-13*tmp32 + 1.41952882825105e-13*tmp34 + 4.05864307006371e-17*tmp35) - 7.0000009536743*tmp31 - 3.66468626111782e-7*tmp32 - 3.66468626111782e-7*tmp34 + 7.0000009536743*tmp35) + dist[2]*(tmp10*(-4.18571914906352e-8*tmp37 + 1.0*tmp38 - 1.0*tmp40 - 4.18571914906352e-8*tmp41) - tmp11*(1.41952882825105e-13*tmp37 + 4.05864307006371e-17*tmp38 - 4.05864307006371e-17*tmp40 + 1.41952882825105e-13*tmp41) - 3.66468626111782e-7*tmp37 + 7.0000009536743*tmp38 - 7.0000009536743*tmp40 - 3.66468626111782e-7*tmp41);
  delta[2] = dist[0]*(-tmp10*(-4.29120382619812e-13*tmp0 + 10.0000011920976*tmp1 + 1.41952882825105e-13*tmp25 + 4.05864307006371e-17*tmp26 + 4.05864307006371e-17*tmp28 - 1.41952882825105e-13*tmp29 - 1.2909701937452e-26) - tmp11*(-2.55252039812856e-33*tmp0 + 5.94826255241147e-20*tmp1 - 4.18571914906352e-8*tmp25 + 1.0*tmp26 + 1.0*tmp28 + 4.18571914906352e-8*tmp29 - 7.67902874431876e-47)) + dist[1]*(-tmp10*(5.02479217361197*tmp0 + 1.42202804511937e-7*tmp1 + 1.41952882825105e-13*tmp31 + 4.05864307006371e-17*tmp32 + 4.05864307006371e-17*tmp34 - 1.41952882825105e-13*tmp35 + 5.29857609301366e-13) - tmp11*(2.98887795569119e-20*tmp0 + 8.45859516091533e-28*tmp1 - 4.18571914906352e-8*tmp31 + 1.0*tmp32 + 1.0*tmp34 + 4.18571914906352e-8*tmp35 + 3.15173179980038e-33)) + dist[2]*(-tmp10*(-8.64589304042811*tmp0 - 1.04468629328254e-8*tmp1 + 4.05864307006371e-17*tmp37 - 1.41952882825105e-13*tmp38 + 1.41952882825105e-13*tmp40 + 4.05864307006371e-17*tmp41 + 3.07940915664173e-13) - tmp11*(-5.14280356738094e-20*tmp0 - 6.21406761657255e-29*tmp1 + 1.0*tmp37 + 4.18571914906352e-8*tmp38 - 4.18571914906352e-8*tmp40 + 1.0*tmp41 + 1.8317131986424e-33));
  const double delta_norm = sqrt(delta[0]*delta[0] + delta[1]*delta[1] + delta[2]*delta[2]);
  if(delta_norm != 0) {
    const double gain = coeff*dist_norm/delta_norm;
    q0_io = q0_io+(delta[0]*gain);
    q1_io = q1_io+(delta[1]*gain);
    q2_io = q2_io+(delta[2]*gain);
  }
}

bool robot_armature_joint_forearm_rb_endpoint::inverse_kinematics(const matrix<4, 1>& target, double& q0_io, double& q1_io, double& q2_io, double coeff, double stop_dist, int max_iter) {
  matrix<4, 1> tmp;
  if(stop_dist >= distance_from_target(target, q0_io, q1_io, q2_io, tmp)) {
    return true;
  }
  for(int i = 0 ; i < max_iter ; i++) {
    inverse_kinematics_step(target, q0_io, q1_io, q2_io, coeff);
    if(stop_dist >= distance_from_target(target, q0_io, q1_io, q2_io, tmp)) {
      return true;
    }
  }
  return false;
}
