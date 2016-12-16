#include "robot_armature_joint_forearm_lb_endpoint.hpp"

void robot_armature_joint_forearm_lb_endpoint::forward_kinematics(real q0, real q1, real q2, matrix<4, 1>& matrix_out) {
  real tmp0 = my_sin(q0);
  real tmp1 = my_cos(q0);
  real tmp2 = my_sin(q1);
  real tmp3 = -5.02479255494976*tmp0 - 3.86787227338021e-15*tmp1 - 6.32414170921508e-15;
  real tmp4 = tmp2*tmp3;
  real tmp5 = my_cos(q1);
  real tmp6 = tmp3*tmp5;
  real tmp7 = 8.64589436601321*tmp0 + 2.43311717378904e-14*tmp1 - 3.67544413688128e-15;
  real tmp8 = tmp2*tmp7;
  real tmp9 = tmp5*tmp7;
  real tmp10 = 8.89999771118164*my_sin(q2);
  real tmp11 = 8.89999771118164*my_cos(q2);
  real tmp12 = -1.93172773921057e-8*tmp0 + 2.52485342885838*tmp1 + 7.47514806688696;
  real tmp13 = tmp12*tmp2;
  real tmp14 = tmp12*tmp5;
  real tmp15 = 3.32382247772058e-8*tmp0 - 4.34438154348724*tmp1 + 4.34438227320638;
  real tmp16 = tmp15*tmp2;
  real tmp17 = tmp15*tmp5;
  real tmp18 = -1.05553902348754e-7*tmp0 + 4.34438172640051*tmp1 - 4.34438296174479;
  real tmp19 = tmp18*tmp2;
  real tmp20 = tmp18*tmp5;
  real tmp21 = 1.81621023443008e-7*tmp0 - 7.47514749740201*tmp1 - 2.52485437855465;
  real tmp22 = tmp2*tmp21;
  real tmp23 = tmp21*tmp5;
  matrix_out[0] = 7.72830027286878e-6*tmp0 + 8.8817870317553e-14*tmp1 - tmp10*(-3.18617806444721e-14*tmp0 + 10.0000011920929*tmp1 - 2.1200722214842e-15*tmp4 + 1.01780961249734e-16*tmp6 - 1.01780961249734e-16*tmp8 - 2.1200722214842e-15*tmp9 + 9.74502966464453e-30) + tmp11*(1.68674812006332e-36*tmp0 - 5.29395497370611e-22*tmp1 + 0.99999988079071*tmp4 + 1.77474888118923e-8*tmp6 - 1.77474888118923e-8*tmp8 + 0.99999988079071*tmp9 - 5.15897421120819e-52) + 7.0*tmp4 - 3.03564384296351e-7*tmp6 + 3.03564384296351e-7*tmp8 + 7.0*tmp9 - 89.9999904632555;
  matrix_out[1] = 7.4339747452371e-14*tmp0 - 3.88330965503809e-6*tmp1 - tmp10*(5.02479197346608*tmp0 + 3.84439468590261e-8*tmp1 - 2.1200722214842e-15*tmp13 + 1.01780961249734e-16*tmp14 - 1.01780961249734e-16*tmp16 - 2.1200722214842e-15*tmp17 - 1.1518644427793e-14) + tmp11*(-2.66010192886806e-22*tmp0 - 2.035204994217e-30*tmp1 + 0.99999988079071*tmp13 + 1.77474888118923e-8*tmp14 - 1.77474888118923e-8*tmp16 + 0.99999988079071*tmp17 + 6.09791776895824e-37) + 7.0*tmp13 - 3.03564384296351e-7*tmp14 + 3.03564384296351e-7*tmp16 + 7.0*tmp17 + 86.7500041742945;
  matrix_out[2] = 2.39136431230696e-13*tmp0 - 6.68180549036077e-6*tmp1 - tmp10*(8.64589372950664*tmp0 + 2.10066235123746e-7*tmp1 - 2.1200722214842e-15*tmp19 + 1.01780961249734e-16*tmp20 - 1.01780961249734e-16*tmp22 - 2.1200722214842e-15*tmp23 + 6.69436941539277e-15) + tmp11*(-4.57709666551316e-22*tmp0 - 1.11208105767068e-29*tmp1 + 0.99999988079071*tmp19 + 1.77474888118923e-8*tmp20 - 1.77474888118923e-8*tmp22 + 0.99999988079071*tmp23 - 3.54396860377048e-37) + 7.0*tmp19 - 3.03564384296351e-7*tmp20 + 3.03564384296351e-7*tmp22 + 7.0*tmp23 - 46.0000061185517;
  matrix_out[3] = 1.00000000000000;
}

real robot_armature_joint_forearm_lb_endpoint::distance_from_target(const matrix<4, 1>& target, real q0_io, real q1_io, real q2_io, matrix<4, 1>& dist_out) {
  forward_kinematics(q0_io, q1_io, q2_io, dist_out);
  dist_out[0] = target[0] - dist_out[0];
  dist_out[1] = target[1] - dist_out[1];
  dist_out[2] = target[2] - dist_out[2];
  dist_out[3] = target[3] - dist_out[3];
  const real ret = sqrt(dist_out[0]*dist_out[0] + dist_out[1]*dist_out[1] + dist_out[2]*dist_out[2] + dist_out[3]*dist_out[3]);
  return ret;
}

void robot_armature_joint_forearm_lb_endpoint::inverse_kinematics_step(const matrix<4, 1>& target, real& q0_io, real& q1_io, real& q2_io, real coeff) {
  matrix<4, 1> dist;
  real dist_norm = distance_from_target(target, q0_io, q1_io, q2_io, dist);
  matrix<3, 1> delta;
  real tmp0 = my_sin(q0_io);
  real tmp1 = my_cos(q0_io);
  real tmp2 = my_sin(q1_io);
  real tmp3 = -2.43311717378904e-14*tmp0 + 8.64589436601321*tmp1;
  real tmp4 = tmp2*tmp3;
  real tmp5 = my_cos(q1_io);
  real tmp6 = tmp3*tmp5;
  real tmp7 = 3.86787227338021e-15*tmp0 - 5.02479255494976*tmp1;
  real tmp8 = tmp2*tmp7;
  real tmp9 = tmp5*tmp7;
  real tmp10 = 8.89999771118164*my_cos(q2_io);
  real tmp11 = 8.89999771118164*my_sin(q2_io);
  real tmp12 = -2.52485342885838*tmp0 - 1.93172773921057e-8*tmp1;
  real tmp13 = tmp12*tmp2;
  real tmp14 = tmp12*tmp5;
  real tmp15 = 4.34438154348724*tmp0 + 3.32382247772058e-8*tmp1;
  real tmp16 = tmp15*tmp2;
  real tmp17 = tmp15*tmp5;
  real tmp18 = -4.34438172640051*tmp0 - 1.05553902348754e-7*tmp1;
  real tmp19 = tmp18*tmp2;
  real tmp20 = tmp18*tmp5;
  real tmp21 = 7.47514749740201*tmp0 + 1.81621023443008e-7*tmp1;
  real tmp22 = tmp2*tmp21;
  real tmp23 = tmp21*tmp5;
  real tmp24 = -5.02479255494976*tmp0 - 3.86787227338021e-15*tmp1 - 6.32414170921508e-15;
  real tmp25 = tmp2*tmp24;
  real tmp26 = tmp24*tmp5;
  real tmp27 = 8.64589436601321*tmp0 + 2.43311717378904e-14*tmp1 - 3.67544413688128e-15;
  real tmp28 = tmp2*tmp27;
  real tmp29 = tmp27*tmp5;
  real tmp30 = -1.93172773921057e-8*tmp0 + 2.52485342885838*tmp1 + 7.47514806688696;
  real tmp31 = tmp2*tmp30;
  real tmp32 = tmp30*tmp5;
  real tmp33 = 3.32382247772058e-8*tmp0 - 4.34438154348724*tmp1 + 4.34438227320638;
  real tmp34 = tmp2*tmp33;
  real tmp35 = tmp33*tmp5;
  real tmp36 = -1.05553902348754e-7*tmp0 + 4.34438172640051*tmp1 - 4.34438296174479;
  real tmp37 = tmp2*tmp36;
  real tmp38 = tmp36*tmp5;
  real tmp39 = 1.81621023443008e-7*tmp0 - 7.47514749740201*tmp1 - 2.52485437855465;
  real tmp40 = tmp2*tmp39;
  real tmp41 = tmp39*tmp5;
  delta[0] = dist[0]*(-8.8817870317553e-14*tmp0 + 7.72830027286878e-6*tmp1 + tmp10*(5.29395497370611e-22*tmp0 + 1.68674812006332e-36*tmp1 - 1.77474888118923e-8*tmp4 + 0.99999988079071*tmp6 + 0.99999988079071*tmp8 + 1.77474888118923e-8*tmp9) - tmp11*(-10.0000011920929*tmp0 - 3.18617806444721e-14*tmp1 - 1.01780961249734e-16*tmp4 - 2.1200722214842e-15*tmp6 - 2.1200722214842e-15*tmp8 + 1.01780961249734e-16*tmp9) + 3.03564384296351e-7*tmp4 + 7.0*tmp6 + 7.0*tmp8 - 3.03564384296351e-7*tmp9) + dist[1]*(3.88330965503809e-6*tmp0 + 7.4339747452371e-14*tmp1 + tmp10*(2.035204994217e-30*tmp0 - 2.66010192886806e-22*tmp1 + 0.99999988079071*tmp13 + 1.77474888118923e-8*tmp14 - 1.77474888118923e-8*tmp16 + 0.99999988079071*tmp17) - tmp11*(-3.84439468590261e-8*tmp0 + 5.02479197346608*tmp1 - 2.1200722214842e-15*tmp13 + 1.01780961249734e-16*tmp14 - 1.01780961249734e-16*tmp16 - 2.1200722214842e-15*tmp17) + 7.0*tmp13 - 3.03564384296351e-7*tmp14 + 3.03564384296351e-7*tmp16 + 7.0*tmp17) + dist[2]*(6.68180549036077e-6*tmp0 + 2.39136431230696e-13*tmp1 + tmp10*(1.11208105767068e-29*tmp0 - 4.57709666551316e-22*tmp1 + 0.99999988079071*tmp19 + 1.77474888118923e-8*tmp20 - 1.77474888118923e-8*tmp22 + 0.99999988079071*tmp23) - tmp11*(-2.10066235123746e-7*tmp0 + 8.64589372950664*tmp1 - 2.1200722214842e-15*tmp19 + 1.01780961249734e-16*tmp20 - 1.01780961249734e-16*tmp22 - 2.1200722214842e-15*tmp23) + 7.0*tmp19 - 3.03564384296351e-7*tmp20 + 3.03564384296351e-7*tmp22 + 7.0*tmp23);
  delta[1] = dist[0]*(tmp10*(-1.77474888118923e-8*tmp25 + 0.99999988079071*tmp26 - 0.99999988079071*tmp28 - 1.77474888118923e-8*tmp29) - tmp11*(-1.01780961249734e-16*tmp25 - 2.1200722214842e-15*tmp26 + 2.1200722214842e-15*tmp28 - 1.01780961249734e-16*tmp29) + 3.03564384296351e-7*tmp25 + 7.0*tmp26 - 7.0*tmp28 + 3.03564384296351e-7*tmp29) + dist[1]*(tmp10*(-1.77474888118923e-8*tmp31 + 0.99999988079071*tmp32 - 0.99999988079071*tmp34 - 1.77474888118923e-8*tmp35) - tmp11*(-1.01780961249734e-16*tmp31 - 2.1200722214842e-15*tmp32 + 2.1200722214842e-15*tmp34 - 1.01780961249734e-16*tmp35) + 3.03564384296351e-7*tmp31 + 7.0*tmp32 - 7.0*tmp34 + 3.03564384296351e-7*tmp35) + dist[2]*(tmp10*(-1.77474888118923e-8*tmp37 + 0.99999988079071*tmp38 - 0.99999988079071*tmp40 - 1.77474888118923e-8*tmp41) - tmp11*(-1.01780961249734e-16*tmp37 - 2.1200722214842e-15*tmp38 + 2.1200722214842e-15*tmp40 - 1.01780961249734e-16*tmp41) + 3.03564384296351e-7*tmp37 + 7.0*tmp38 - 7.0*tmp40 + 3.03564384296351e-7*tmp41);
  delta[2] = dist[0]*(-tmp10*(-3.18617806444721e-14*tmp0 + 10.0000011920929*tmp1 - 2.1200722214842e-15*tmp25 + 1.01780961249734e-16*tmp26 - 1.01780961249734e-16*tmp28 - 2.1200722214842e-15*tmp29 + 9.74502966464453e-30) - tmp11*(1.68674812006332e-36*tmp0 - 5.29395497370611e-22*tmp1 + 0.99999988079071*tmp25 + 1.77474888118923e-8*tmp26 - 1.77474888118923e-8*tmp28 + 0.99999988079071*tmp29 - 5.15897421120819e-52)) + dist[1]*(-tmp10*(5.02479197346608*tmp0 + 3.84439468590261e-8*tmp1 - 2.1200722214842e-15*tmp31 + 1.01780961249734e-16*tmp32 - 1.01780961249734e-16*tmp34 - 2.1200722214842e-15*tmp35 - 1.1518644427793e-14) - tmp11*(-2.66010192886806e-22*tmp0 - 2.035204994217e-30*tmp1 + 0.99999988079071*tmp31 + 1.77474888118923e-8*tmp32 - 1.77474888118923e-8*tmp34 + 0.99999988079071*tmp35 + 6.09791776895824e-37)) + dist[2]*(-tmp10*(8.64589372950664*tmp0 + 2.10066235123746e-7*tmp1 - 2.1200722214842e-15*tmp37 + 1.01780961249734e-16*tmp38 - 1.01780961249734e-16*tmp40 - 2.1200722214842e-15*tmp41 + 6.69436941539277e-15) - tmp11*(-4.57709666551316e-22*tmp0 - 1.11208105767068e-29*tmp1 + 0.99999988079071*tmp37 + 1.77474888118923e-8*tmp38 - 1.77474888118923e-8*tmp40 + 0.99999988079071*tmp41 - 3.54396860377048e-37));
  const real delta_norm = sqrt(delta[0]*delta[0] + delta[1]*delta[1] + delta[2]*delta[2]);
  if(delta_norm != 0) {
    const real gain = coeff*dist_norm/delta_norm;
    q0_io = q0_io+(delta[0]*gain);
    q1_io = q1_io+(delta[1]*gain);
    q2_io = q2_io+(delta[2]*gain);
  }
}

bool robot_armature_joint_forearm_lb_endpoint::inverse_kinematics(const matrix<4, 1>& target, real& q0_io, real& q1_io, real& q2_io, real coeff, real stop_dist, int max_iter) {
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
