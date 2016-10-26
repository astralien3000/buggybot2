#include <robot_armature_joint_forearm_rf_endpoint.hpp>
#include <math.h>

void robot_armature_joint_forearm_rf_endpoint::forward_kinematics(double q0, double q1, double q2, matrix<4, 1>& matrix_out) {
  double tmp0 = sin(q0);
  double tmp1 = cos(q0);
  double tmp2 = sin(q1);
  double tmp3 = -8.64589162791634*tmp0 + 5.28860971942685e-13*tmp1 - 8.92582514307307e-15;
  double tmp4 = tmp2*tmp3;
  double tmp5 = cos(q1);
  double tmp6 = tmp3*tmp5;
  double tmp7 = -5.02479284854102*tmp0 - 1.49390289076273e-13*tmp1 + 1.53581876671676e-14;
  double tmp8 = tmp2*tmp7;
  double tmp9 = tmp5*tmp7;
  double tmp10 = sin(q2);
  double tmp11 = 1.9073486328125e-6*tmp10;
  double tmp12 = 1.64833373129797e-33*tmp0 + 1.18965316613364e-20*tmp1 - 4.18571772797804e-8*tmp4 + 1.0*tmp6 + 1.0*tmp8 + 4.18571772797804e-8*tmp9 + 7.13237863886592e-49;
  double tmp13 = cos(q2);
  double tmp14 = 8.90000057220459*tmp13;
  double tmp15 = 8.90000057220459*tmp10;
  double tmp16 = 1.38555814414978e-12*tmp0 + 9.99999940395605*tmp1 + 2.68908498441724e-14*tmp4 + 1.61017363383017e-16*tmp6 + 1.61017363383017e-16*tmp8 - 2.68908498441724e-14*tmp9 + 5.99534252232941e-28;
  double tmp17 = 1.9073486328125e-6*tmp13;
  double tmp18 = -1.63993236047964e-7*tmp0 + 4.3443808557294*tmp1 - 4.34438241676528;
  double tmp19 = tmp18*tmp2;
  double tmp20 = tmp18*tmp5;
  double tmp21 = -9.53093167796901e-8*tmp0 + 2.52485397627735*tmp1 + 7.47514536584936;
  double tmp22 = tmp2*tmp21;
  double tmp23 = tmp21*tmp5;
  double tmp24 = 5.97775991457159e-21*tmp0 + 2.25650147985282e-28*tmp1 - 4.18571772797804e-8*tmp19 + 1.0*tmp20 + 1.0*tmp22 + 4.18571772797804e-8*tmp23 + 3.47147516915543e-34;
  double tmp25 = 5.02479187080928*tmp0 + 1.89677244561036e-7*tmp1 + 2.68908498441724e-14*tmp19 + 1.61017363383017e-16*tmp20 + 1.61017363383017e-16*tmp22 - 2.68908498441724e-14*tmp23 + 2.91805633865753e-13;
  double tmp26 = -1.17310803092139e-7*tmp0 - 7.47514588118663*tmp1 - 2.52485397627674;
  double tmp27 = tmp2*tmp26;
  double tmp28 = tmp26*tmp5;
  double tmp29 = -6.81779387844959e-8*tmp0 - 4.34438241676638*tmp1 + 4.34438055622743;
  double tmp30 = tmp2*tmp29;
  double tmp31 = tmp29*tmp5;
  double tmp32 = -1.02856146567357e-20*tmp0 + 1.61417540855031e-28*tmp1 - 4.18571772797804e-8*tmp27 + 1.0*tmp28 + 1.0*tmp30 + 4.18571772797804e-8*tmp31 + 2.01754059462248e-34;
  double tmp33 = -8.64589305225492*tmp0 + 1.35684530440449e-7*tmp1 + 2.68908498441724e-14*tmp27 + 1.61017363383017e-16*tmp28 + 1.61017363383017e-16*tmp30 - 2.68908498441724e-14*tmp31 + 1.69590644719182e-13;
  matrix_out[0] = -2.58223633502868e-6*tmp0 + 1.82102665757542e-6*tmp1 + tmp11*tmp12 + tmp12*tmp14 - tmp15*tmp16 + tmp16*tmp17 + 2.13826501749281e-6*tmp4 + 7.00000143051151*tmp6 + 7.00000143051151*tmp8 - 2.13826501749281e-6*tmp9 + 89.9999946355818;
  matrix_out[1] = 9.15028000111558e-7*tmp0 + 1.29752012635481e-6*tmp1 + tmp11*tmp24 + tmp14*tmp24 - tmp15*tmp25 + tmp17*tmp25 + 2.13826501749281e-6*tmp19 + 7.00000143051151*tmp20 + 7.00000143051151*tmp22 - 2.13826501749281e-6*tmp23 - 86.7500038038882;
  matrix_out[2] = -1.57444030155043e-6*tmp0 - 2.2325740271934e-6*tmp1 + tmp11*tmp32 + tmp14*tmp32 - tmp15*tmp33 + tmp17*tmp33 + 2.13826501749281e-6*tmp27 + 7.00000143051151*tmp28 + 7.00000143051151*tmp30 - 2.13826501749281e-6*tmp31 - 45.9999987585374;
  matrix_out[3] = 1.00000000000000;
}

double robot_armature_joint_forearm_rf_endpoint::distance_from_target(const matrix<4, 1>& target, double q0_io, double q1_io, double q2_io, matrix<4, 1>& dist_out) {
  forward_kinematics(q0_io, q1_io, q2_io, dist_out);
  dist_out[0] = dist_out[0] - target[0];
  dist_out[1] = dist_out[1] - target[1];
  dist_out[2] = dist_out[2] - target[2];
  dist_out[3] = dist_out[3] - target[3];
  const double ret = sqrt(dist_out[0]*dist_out[0] + dist_out[1]*dist_out[1] + dist_out[2]*dist_out[2] + dist_out[3]*dist_out[3]);
  return ret;
}

void robot_armature_joint_forearm_rf_endpoint::inverse_kinematics_step(const matrix<4, 1>& target, double& q0_io, double& q1_io, double& q2_io, double coeff) {
  matrix<4, 1> dist;
  double dist_norm = distance_from_target(target, q0_io, q1_io, q2_io, dist);
  matrix<3, 1> delta;
  double tmp0 = sin(q0_io);
  double tmp1 = cos(q0_io);
  double tmp2 = sin(q1_io);
  double tmp3 = -5.28860971942685e-13*tmp0 - 8.64589162791634*tmp1;
  double tmp4 = tmp2*tmp3;
  double tmp5 = cos(q1_io);
  double tmp6 = tmp3*tmp5;
  double tmp7 = 1.49390289076273e-13*tmp0 - 5.02479284854102*tmp1;
  double tmp8 = tmp2*tmp7;
  double tmp9 = tmp5*tmp7;
  double tmp10 = sin(q2_io);
  double tmp11 = 1.9073486328125e-6*tmp10;
  double tmp12 = -1.18965316613364e-20*tmp0 + 1.64833373129797e-33*tmp1 - 4.18571772797804e-8*tmp4 + 1.0*tmp6 + 1.0*tmp8 + 4.18571772797804e-8*tmp9;
  double tmp13 = cos(q2_io);
  double tmp14 = 8.90000057220459*tmp13;
  double tmp15 = 8.90000057220459*tmp10;
  double tmp16 = -9.99999940395605*tmp0 + 1.38555814414978e-12*tmp1 + 2.68908498441724e-14*tmp4 + 1.61017363383017e-16*tmp6 + 1.61017363383017e-16*tmp8 - 2.68908498441724e-14*tmp9;
  double tmp17 = 1.9073486328125e-6*tmp13;
  double tmp18 = -4.3443808557294*tmp0 - 1.63993236047964e-7*tmp1;
  double tmp19 = tmp18*tmp2;
  double tmp20 = tmp18*tmp5;
  double tmp21 = -2.52485397627735*tmp0 - 9.53093167796901e-8*tmp1;
  double tmp22 = tmp2*tmp21;
  double tmp23 = tmp21*tmp5;
  double tmp24 = -2.25650147985282e-28*tmp0 + 5.97775991457159e-21*tmp1 - 4.18571772797804e-8*tmp19 + 1.0*tmp20 + 1.0*tmp22 + 4.18571772797804e-8*tmp23;
  double tmp25 = -1.89677244561036e-7*tmp0 + 5.02479187080928*tmp1 + 2.68908498441724e-14*tmp19 + 1.61017363383017e-16*tmp20 + 1.61017363383017e-16*tmp22 - 2.68908498441724e-14*tmp23;
  double tmp26 = 4.34438241676638*tmp0 - 6.81779387844959e-8*tmp1;
  double tmp27 = tmp2*tmp26;
  double tmp28 = tmp26*tmp5;
  double tmp29 = 7.47514588118663*tmp0 - 1.17310803092139e-7*tmp1;
  double tmp30 = tmp2*tmp29;
  double tmp31 = tmp29*tmp5;
  double tmp32 = -1.35684530440449e-7*tmp0 - 8.64589305225492*tmp1 + 1.61017363383017e-16*tmp27 - 2.68908498441724e-14*tmp28 + 2.68908498441724e-14*tmp30 + 1.61017363383017e-16*tmp31;
  double tmp33 = -1.61417540855031e-28*tmp0 - 1.02856146567357e-20*tmp1 + 1.0*tmp27 + 4.18571772797804e-8*tmp28 - 4.18571772797804e-8*tmp30 + 1.0*tmp31;
  double tmp34 = -8.64589162791634*tmp0 + 5.28860971942685e-13*tmp1 - 8.92582514307307e-15;
  double tmp35 = tmp2*tmp34;
  double tmp36 = tmp34*tmp5;
  double tmp37 = -5.02479284854102*tmp0 - 1.49390289076273e-13*tmp1 + 1.53581876671676e-14;
  double tmp38 = tmp2*tmp37;
  double tmp39 = tmp37*tmp5;
  double tmp40 = -1.0*tmp35 - 4.18571772797804e-8*tmp36 - 4.18571772797804e-8*tmp38 + 1.0*tmp39;
  double tmp41 = -1.61017363383017e-16*tmp35 + 2.68908498441724e-14*tmp36 + 2.68908498441724e-14*tmp38 + 1.61017363383017e-16*tmp39;
  double tmp42 = -1.63993236047964e-7*tmp0 + 4.3443808557294*tmp1 - 4.34438241676528;
  double tmp43 = tmp2*tmp42;
  double tmp44 = tmp42*tmp5;
  double tmp45 = -9.53093167796901e-8*tmp0 + 2.52485397627735*tmp1 + 7.47514536584936;
  double tmp46 = tmp2*tmp45;
  double tmp47 = tmp45*tmp5;
  double tmp48 = -1.0*tmp43 - 4.18571772797804e-8*tmp44 - 4.18571772797804e-8*tmp46 + 1.0*tmp47;
  double tmp49 = -1.61017363383017e-16*tmp43 + 2.68908498441724e-14*tmp44 + 2.68908498441724e-14*tmp46 + 1.61017363383017e-16*tmp47;
  double tmp50 = -1.17310803092139e-7*tmp0 - 7.47514588118663*tmp1 - 2.52485397627674;
  double tmp51 = tmp2*tmp50;
  double tmp52 = tmp5*tmp50;
  double tmp53 = -6.81779387844959e-8*tmp0 - 4.34438241676638*tmp1 + 4.34438055622743;
  double tmp54 = tmp2*tmp53;
  double tmp55 = tmp5*tmp53;
  double tmp56 = -1.0*tmp51 - 4.18571772797804e-8*tmp52 - 4.18571772797804e-8*tmp54 + 1.0*tmp55;
  double tmp57 = -1.61017363383017e-16*tmp51 + 2.68908498441724e-14*tmp52 + 2.68908498441724e-14*tmp54 + 1.61017363383017e-16*tmp55;
  double tmp58 = 1.64833373129797e-33*tmp0 + 1.18965316613364e-20*tmp1 - 4.18571772797804e-8*tmp35 + 1.0*tmp36 + 1.0*tmp38 + 4.18571772797804e-8*tmp39 + 7.13237863886592e-49;
  double tmp59 = 1.38555814414978e-12*tmp0 + 9.99999940395605*tmp1 + 2.68908498441724e-14*tmp35 + 1.61017363383017e-16*tmp36 + 1.61017363383017e-16*tmp38 - 2.68908498441724e-14*tmp39 + 5.99534252232941e-28;
  double tmp60 = 5.97775991457159e-21*tmp0 + 2.25650147985282e-28*tmp1 - 4.18571772797804e-8*tmp43 + 1.0*tmp44 + 1.0*tmp46 + 4.18571772797804e-8*tmp47 + 3.47147516915543e-34;
  double tmp61 = 5.02479187080928*tmp0 + 1.89677244561036e-7*tmp1 + 2.68908498441724e-14*tmp43 + 1.61017363383017e-16*tmp44 + 1.61017363383017e-16*tmp46 - 2.68908498441724e-14*tmp47 + 2.91805633865753e-13;
  double tmp62 = -1.02856146567357e-20*tmp0 + 1.61417540855031e-28*tmp1 - 4.18571772797804e-8*tmp51 + 1.0*tmp52 + 1.0*tmp54 + 4.18571772797804e-8*tmp55 + 2.01754059462248e-34;
  double tmp63 = -8.64589305225492*tmp0 + 1.35684530440449e-7*tmp1 + 2.68908498441724e-14*tmp51 + 1.61017363383017e-16*tmp52 + 1.61017363383017e-16*tmp54 - 2.68908498441724e-14*tmp55 + 1.69590644719182e-13;
  delta[0] = dist[0]*(-1.82102665757542e-6*tmp0 - 2.58223633502868e-6*tmp1 + tmp11*tmp12 + tmp12*tmp14 - tmp15*tmp16 + tmp16*tmp17 + 2.13826501749281e-6*tmp4 + 7.00000143051151*tmp6 + 7.00000143051151*tmp8 - 2.13826501749281e-6*tmp9) + dist[1]*(-1.29752012635481e-6*tmp0 + 9.15028000111558e-7*tmp1 + tmp11*tmp24 + tmp14*tmp24 - tmp15*tmp25 + tmp17*tmp25 + 2.13826501749281e-6*tmp19 + 7.00000143051151*tmp20 + 7.00000143051151*tmp22 - 2.13826501749281e-6*tmp23) + dist[2]*(2.2325740271934e-6*tmp0 - 1.57444030155043e-6*tmp1 + tmp11*tmp33 + tmp14*tmp33 - tmp15*tmp32 + tmp17*tmp32 + 7.00000143051151*tmp27 - 2.13826501749281e-6*tmp28 + 2.13826501749281e-6*tmp30 + 7.00000143051151*tmp31);
  delta[1] = dist[0]*(tmp11*tmp40 + tmp14*tmp40 - tmp15*tmp41 + tmp17*tmp41 - 7.00000143051151*tmp35 + 2.13826501749281e-6*tmp36 + 2.13826501749281e-6*tmp38 + 7.00000143051151*tmp39) + dist[1]*(tmp11*tmp48 + tmp14*tmp48 - tmp15*tmp49 + tmp17*tmp49 - 7.00000143051151*tmp43 + 2.13826501749281e-6*tmp44 + 2.13826501749281e-6*tmp46 + 7.00000143051151*tmp47) + dist[2]*(tmp11*tmp56 + tmp14*tmp56 - tmp15*tmp57 + tmp17*tmp57 - 7.00000143051151*tmp51 + 2.13826501749281e-6*tmp52 + 2.13826501749281e-6*tmp54 + 7.00000143051151*tmp55);
  delta[2] = dist[0]*(-tmp11*tmp59 - tmp14*tmp59 - tmp15*tmp58 + tmp17*tmp58) + dist[1]*(-tmp11*tmp61 - tmp14*tmp61 - tmp15*tmp60 + tmp17*tmp60) + dist[2]*(-tmp11*tmp63 - tmp14*tmp63 - tmp15*tmp62 + tmp17*tmp62);
  const double delta_norm = sqrt(delta[0]*delta[0] + delta[1]*delta[1] + delta[2]*delta[2]);
  if(delta_norm != 0) {
    const double gain = coeff*dist_norm/delta_norm;
    q0_io = q0_io+(delta[0]*gain);
    q1_io = q1_io+(delta[1]*gain);
    q2_io = q2_io+(delta[2]*gain);
  }
}

bool robot_armature_joint_forearm_rf_endpoint::inverse_kinematics(const matrix<4, 1>& target, double& q0_io, double& q1_io, double& q2_io, double coeff, double stop_dist, int max_iter) {
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
