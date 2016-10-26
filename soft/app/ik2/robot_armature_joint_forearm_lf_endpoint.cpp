#include <robot_armature_joint_forearm_lf_endpoint.hpp>
#include <math.h>

void robot_armature_joint_forearm_lf_endpoint::forward_kinematics(double q0, double q1, double q2, matrix<4, 1>& matrix_out) {
  double tmp0 = sin(q0);
  double tmp1 = cos(q0);
  double tmp2 = sin(q1);
  double tmp3 = -5.02479284853976*tmp0 - 3.83954612269856e-15*tmp1 + 3.83954665209412e-15;
  double tmp4 = tmp2*tmp3;
  double tmp5 = cos(q1);
  double tmp6 = tmp3*tmp5;
  double tmp7 = 8.64589103186777*tmp0 - 2.23145522697715e-15*tmp1 + 2.23145655046605e-15;
  double tmp8 = tmp2*tmp7;
  double tmp9 = tmp5*tmp7;
  double tmp10 = sin(q2);
  double tmp11 = 8.89999961853027*tmp10;
  double tmp12 = 8.88178366760567e-15*tmp0 + 9.99999940395355*tmp1 + 8.11379212921999e-16*tmp4 + 5.29617938182592e-17*tmp6 - 5.29617938182592e-17*tmp8 + 8.11379212921999e-16*tmp9 - 3.94430429100619e-30;
  double tmp13 = cos(q2);
  double tmp14 = 9.5367431640625e-7*tmp13;
  double tmp15 = 9.5367431640625e-7*tmp10;
  double tmp16 = -1.88079107341953e-36*tmp0 - 2.11758249435348e-21*tmp1 + 1.0*tmp4 - 1.20548691029398e-8*tmp6 + 1.20548691029398e-8*tmp8 + 1.0*tmp9 + 8.35239021687927e-52;
  double tmp17 = 8.89999961853027*tmp13;
  double tmp18 = -2.18436356423173e-7*tmp0 - 4.34438096715341*tmp1 + 4.3443824730815;
  double tmp19 = tmp18*tmp2;
  double tmp20 = tmp18*tmp5;
  double tmp21 = 1.26950179600468e-7*tmp0 + 2.52485421509747*tmp1 + 7.47514406070451;
  double tmp22 = tmp2*tmp21;
  double tmp23 = tmp21*tmp5;
  double tmp24 = 5.02479234609277*tmp0 - 2.52647581765194e-7*tmp1 - 5.29617938182592e-17*tmp19 + 8.11379212921999e-16*tmp20 + 8.11379212921999e-16*tmp22 + 5.29617938182592e-17*tmp23 - 7.67909481668761e-15;
  double tmp25 = -1.06404129440654e-21*tmp0 + 5.35002128275327e-29*tmp1 + 1.20548691029398e-8*tmp19 + 1.0*tmp20 + 1.0*tmp22 - 1.20548691029398e-8*tmp23 + 1.62611177255364e-36;
  double tmp26 = -7.71076405526893e-8*tmp0 + 4.34438228994113*tmp1 - 4.34438029523934;
  double tmp27 = tmp2*tmp26;
  double tmp28 = tmp26*tmp5;
  double tmp29 = 1.32674965842872e-7*tmp0 - 7.47514514762986*tmp1 - 2.52485429816046;
  double tmp30 = tmp2*tmp29;
  double tmp31 = tmp29*tmp5;
  double tmp32 = 8.64589279985598*tmp0 + 1.53454343497776e-7*tmp1 + 8.11379212921999e-16*tmp27 + 5.29617938182592e-17*tmp28 - 5.29617938182592e-17*tmp30 + 8.11379212921999e-16*tmp31 + 4.46291174269999e-15;
  double tmp33 = -1.8308392332297e-21*tmp0 - 3.2495225084206e-29*tmp1 + 1.0*tmp27 - 1.20548691029398e-8*tmp28 + 1.20548691029398e-8*tmp30 + 1.0*tmp31 - 9.4505843434848e-37;
  matrix_out[0] = 5.41594171869367e-6*tmp0 - 3.55271154291324e-14*tmp1 - tmp11*tmp12 + tmp12*tmp14 + tmp15*tmp16 + tmp16*tmp17 + 7.00000095367433*tmp4 + 1.64364342936096e-6*tmp6 - 1.64364342936096e-6*tmp8 + 7.00000095367433*tmp9 + 89.999994635582;
  matrix_out[1] = -1.54684102392428e-13*tmp0 - 2.72139841170563e-6*tmp1 - tmp11*tmp24 + tmp14*tmp24 + tmp15*tmp25 + tmp17*tmp25 - 1.64364342936096e-6*tmp19 + 7.00000095367433*tmp20 + 7.00000095367433*tmp22 + 1.64364342936096e-6*tmp23 + 86.7499875822184;
  matrix_out[2] = 5.23936222194532e-14*tmp0 - 4.68256543011197e-6*tmp1 - tmp11*tmp32 + tmp14*tmp32 + tmp15*tmp33 + tmp17*tmp33 + 7.00000095367433*tmp27 + 1.64364342936096e-6*tmp28 - 1.64364342936096e-6*tmp30 + 7.00000095367433*tmp31 - 45.9999935831059;
  matrix_out[3] = 1.00000000000000;
}

double robot_armature_joint_forearm_lf_endpoint::distance_from_target(const matrix<4, 1>& target, double q0_io, double q1_io, double q2_io, matrix<4, 1>& dist_out) {
  forward_kinematics(q0_io, q1_io, q2_io, dist_out);
  dist_out[0] = dist_out[0] - target[0];
  dist_out[1] = dist_out[1] - target[1];
  dist_out[2] = dist_out[2] - target[2];
  dist_out[3] = dist_out[3] - target[3];
  const double ret = sqrt(dist_out[0]*dist_out[0] + dist_out[1]*dist_out[1] + dist_out[2]*dist_out[2] + dist_out[3]*dist_out[3]);
  return ret;
}

void robot_armature_joint_forearm_lf_endpoint::inverse_kinematics_step(const matrix<4, 1>& target, double& q0_io, double& q1_io, double& q2_io, double coeff) {
  matrix<4, 1> dist;
  double dist_norm = distance_from_target(target, q0_io, q1_io, q2_io, dist);
  matrix<3, 1> delta;
  double tmp0 = sin(q0_io);
  double tmp1 = cos(q0_io);
  double tmp2 = sin(q1_io);
  double tmp3 = 2.23145522697715e-15*tmp0 + 8.64589103186777*tmp1;
  double tmp4 = tmp2*tmp3;
  double tmp5 = cos(q1_io);
  double tmp6 = tmp3*tmp5;
  double tmp7 = 3.83954612269856e-15*tmp0 - 5.02479284853976*tmp1;
  double tmp8 = tmp2*tmp7;
  double tmp9 = tmp5*tmp7;
  double tmp10 = sin(q2_io);
  double tmp11 = 8.89999961853027*tmp10;
  double tmp12 = -9.99999940395355*tmp0 + 8.88178366760567e-15*tmp1 - 5.29617938182592e-17*tmp4 + 8.11379212921999e-16*tmp6 + 8.11379212921999e-16*tmp8 + 5.29617938182592e-17*tmp9;
  double tmp13 = cos(q2_io);
  double tmp14 = 9.5367431640625e-7*tmp13;
  double tmp15 = 9.5367431640625e-7*tmp10;
  double tmp16 = 2.11758249435348e-21*tmp0 - 1.88079107341953e-36*tmp1 + 1.20548691029398e-8*tmp4 + 1.0*tmp6 + 1.0*tmp8 - 1.20548691029398e-8*tmp9;
  double tmp17 = 8.89999961853027*tmp13;
  double tmp18 = -2.52485421509747*tmp0 + 1.26950179600468e-7*tmp1;
  double tmp19 = tmp18*tmp2;
  double tmp20 = tmp18*tmp5;
  double tmp21 = 4.34438096715341*tmp0 - 2.18436356423173e-7*tmp1;
  double tmp22 = tmp2*tmp21;
  double tmp23 = tmp21*tmp5;
  double tmp24 = 2.52647581765194e-7*tmp0 + 5.02479234609277*tmp1 + 8.11379212921999e-16*tmp19 + 5.29617938182592e-17*tmp20 - 5.29617938182592e-17*tmp22 + 8.11379212921999e-16*tmp23;
  double tmp25 = -5.35002128275327e-29*tmp0 - 1.06404129440654e-21*tmp1 + 1.0*tmp19 - 1.20548691029398e-8*tmp20 + 1.20548691029398e-8*tmp22 + 1.0*tmp23;
  double tmp26 = -4.34438228994113*tmp0 - 7.71076405526893e-8*tmp1;
  double tmp27 = tmp2*tmp26;
  double tmp28 = tmp26*tmp5;
  double tmp29 = 7.47514514762986*tmp0 + 1.32674965842872e-7*tmp1;
  double tmp30 = tmp2*tmp29;
  double tmp31 = tmp29*tmp5;
  double tmp32 = -1.53454343497776e-7*tmp0 + 8.64589279985598*tmp1 + 8.11379212921999e-16*tmp27 + 5.29617938182592e-17*tmp28 - 5.29617938182592e-17*tmp30 + 8.11379212921999e-16*tmp31;
  double tmp33 = 3.2495225084206e-29*tmp0 - 1.8308392332297e-21*tmp1 + 1.0*tmp27 - 1.20548691029398e-8*tmp28 + 1.20548691029398e-8*tmp30 + 1.0*tmp31;
  double tmp34 = -5.02479284853976*tmp0 - 3.83954612269856e-15*tmp1 + 3.83954665209412e-15;
  double tmp35 = tmp2*tmp34;
  double tmp36 = tmp34*tmp5;
  double tmp37 = 8.64589103186777*tmp0 - 2.23145522697715e-15*tmp1 + 2.23145655046605e-15;
  double tmp38 = tmp2*tmp37;
  double tmp39 = tmp37*tmp5;
  double tmp40 = -5.29617938182592e-17*tmp35 + 8.11379212921999e-16*tmp36 - 8.11379212921999e-16*tmp38 - 5.29617938182592e-17*tmp39;
  double tmp41 = 1.20548691029398e-8*tmp35 + 1.0*tmp36 - 1.0*tmp38 + 1.20548691029398e-8*tmp39;
  double tmp42 = -2.18436356423173e-7*tmp0 - 4.34438096715341*tmp1 + 4.3443824730815;
  double tmp43 = tmp2*tmp42;
  double tmp44 = tmp42*tmp5;
  double tmp45 = 1.26950179600468e-7*tmp0 + 2.52485421509747*tmp1 + 7.47514406070451;
  double tmp46 = tmp2*tmp45;
  double tmp47 = tmp45*tmp5;
  double tmp48 = -1.0*tmp43 + 1.20548691029398e-8*tmp44 + 1.20548691029398e-8*tmp46 + 1.0*tmp47;
  double tmp49 = -8.11379212921999e-16*tmp43 - 5.29617938182592e-17*tmp44 - 5.29617938182592e-17*tmp46 + 8.11379212921999e-16*tmp47;
  double tmp50 = -7.71076405526893e-8*tmp0 + 4.34438228994113*tmp1 - 4.34438029523934;
  double tmp51 = tmp2*tmp50;
  double tmp52 = tmp5*tmp50;
  double tmp53 = 1.32674965842872e-7*tmp0 - 7.47514514762986*tmp1 - 2.52485429816046;
  double tmp54 = tmp2*tmp53;
  double tmp55 = tmp5*tmp53;
  double tmp56 = -5.29617938182592e-17*tmp51 + 8.11379212921999e-16*tmp52 - 8.11379212921999e-16*tmp54 - 5.29617938182592e-17*tmp55;
  double tmp57 = 1.20548691029398e-8*tmp51 + 1.0*tmp52 - 1.0*tmp54 + 1.20548691029398e-8*tmp55;
  double tmp58 = 8.88178366760567e-15*tmp0 + 9.99999940395355*tmp1 + 8.11379212921999e-16*tmp35 + 5.29617938182592e-17*tmp36 - 5.29617938182592e-17*tmp38 + 8.11379212921999e-16*tmp39 - 3.94430429100619e-30;
  double tmp59 = -1.88079107341953e-36*tmp0 - 2.11758249435348e-21*tmp1 + 1.0*tmp35 - 1.20548691029398e-8*tmp36 + 1.20548691029398e-8*tmp38 + 1.0*tmp39 + 8.35239021687927e-52;
  double tmp60 = 5.02479234609277*tmp0 - 2.52647581765194e-7*tmp1 - 5.29617938182592e-17*tmp43 + 8.11379212921999e-16*tmp44 + 8.11379212921999e-16*tmp46 + 5.29617938182592e-17*tmp47 - 7.67909481668761e-15;
  double tmp61 = -1.06404129440654e-21*tmp0 + 5.35002128275327e-29*tmp1 + 1.20548691029398e-8*tmp43 + 1.0*tmp44 + 1.0*tmp46 - 1.20548691029398e-8*tmp47 + 1.62611177255364e-36;
  double tmp62 = 8.64589279985598*tmp0 + 1.53454343497776e-7*tmp1 + 8.11379212921999e-16*tmp51 + 5.29617938182592e-17*tmp52 - 5.29617938182592e-17*tmp54 + 8.11379212921999e-16*tmp55 + 4.46291174269999e-15;
  double tmp63 = -1.8308392332297e-21*tmp0 - 3.2495225084206e-29*tmp1 + 1.0*tmp51 - 1.20548691029398e-8*tmp52 + 1.20548691029398e-8*tmp54 + 1.0*tmp55 - 9.4505843434848e-37;
  delta[0] = dist[0]*(3.55271154291324e-14*tmp0 + 5.41594171869367e-6*tmp1 - tmp11*tmp12 + tmp12*tmp14 + tmp15*tmp16 + tmp16*tmp17 - 1.64364342936096e-6*tmp4 + 7.00000095367433*tmp6 + 7.00000095367433*tmp8 + 1.64364342936096e-6*tmp9) + dist[1]*(2.72139841170563e-6*tmp0 - 1.54684102392428e-13*tmp1 - tmp11*tmp24 + tmp14*tmp24 + tmp15*tmp25 + tmp17*tmp25 + 7.00000095367433*tmp19 + 1.64364342936096e-6*tmp20 - 1.64364342936096e-6*tmp22 + 7.00000095367433*tmp23) + dist[2]*(4.68256543011197e-6*tmp0 + 5.23936222194532e-14*tmp1 - tmp11*tmp32 + tmp14*tmp32 + tmp15*tmp33 + tmp17*tmp33 + 7.00000095367433*tmp27 + 1.64364342936096e-6*tmp28 - 1.64364342936096e-6*tmp30 + 7.00000095367433*tmp31);
  delta[1] = dist[0]*(-tmp11*tmp40 + tmp14*tmp40 + tmp15*tmp41 + tmp17*tmp41 - 1.64364342936096e-6*tmp35 + 7.00000095367433*tmp36 - 7.00000095367433*tmp38 - 1.64364342936096e-6*tmp39) + dist[1]*(-tmp11*tmp49 + tmp14*tmp49 + tmp15*tmp48 + tmp17*tmp48 - 7.00000095367433*tmp43 - 1.64364342936096e-6*tmp44 - 1.64364342936096e-6*tmp46 + 7.00000095367433*tmp47) + dist[2]*(-tmp11*tmp56 + tmp14*tmp56 + tmp15*tmp57 + tmp17*tmp57 - 1.64364342936096e-6*tmp51 + 7.00000095367433*tmp52 - 7.00000095367433*tmp54 - 1.64364342936096e-6*tmp55);
  delta[2] = dist[0]*(-tmp11*tmp59 + tmp14*tmp59 - tmp15*tmp58 - tmp17*tmp58) + dist[1]*(-tmp11*tmp61 + tmp14*tmp61 - tmp15*tmp60 - tmp17*tmp60) + dist[2]*(-tmp11*tmp63 + tmp14*tmp63 - tmp15*tmp62 - tmp17*tmp62);
  const double delta_norm = sqrt(delta[0]*delta[0] + delta[1]*delta[1] + delta[2]*delta[2]);
  if(delta_norm != 0) {
    const double gain = coeff*dist_norm/delta_norm;
    q0_io = q0_io+(delta[0]*gain);
    q1_io = q1_io+(delta[1]*gain);
    q2_io = q2_io+(delta[2]*gain);
  }
}

bool robot_armature_joint_forearm_lf_endpoint::inverse_kinematics(const matrix<4, 1>& target, double& q0_io, double& q1_io, double& q2_io, double coeff, double stop_dist, int max_iter) {
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
