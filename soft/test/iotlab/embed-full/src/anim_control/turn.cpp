#include "turn.hpp"
#include <math.h>

void AnimTurn::get_walk_pos_1(WalkConfig& cfg, LegConfig& leg, double t, double& x, double& y, double& z) {

  double t_step1_middle = cfg.period / 4.0;
  double t_step2_middle = cfg.period * 3.0 / 4.0;

  double dt_half_step = cfg.period / 4.0;

  double side = (45.0*3.1415/180);
  if(leg.default_y < 0) {
    side = ((180+45.0)*3.1415/180);
  }

  if(abs(t - t_step1_middle) < dt_half_step * cfg.move_ratio) {
    double t2 = (t - t_step1_middle) / (dt_half_step * cfg.move_ratio);
    x = default_ray * cos(side + _way*t2*3.1415/round_divisor);
    y = default_ray * sin(side + _way*t2*3.1415/round_divisor);
  }
  else if(abs(t - t_step2_middle) < dt_half_step * cfg.move_ratio) {
    double t2 = (t - t_step2_middle) / (dt_half_step * cfg.move_ratio);
    x = default_ray * cos(side - _way*t2*3.1415/round_divisor);
    y = default_ray * sin(side - _way*t2*3.1415/round_divisor);
  }
  else if(abs(t - cfg.period/2.0) < dt_half_step) {
    x = default_ray * cos(side + _way*3.1415/round_divisor);
    y = default_ray * sin(side + _way*3.1415/round_divisor);
  }
  else if(abs(t - cfg.period/2.0) > dt_half_step) {
    x = default_ray * cos(side - _way*3.1415/round_divisor);
    y = default_ray * sin(side - _way*3.1415/round_divisor);
  }
  else {
    x = default_ray * cos(side);
    y = default_ray * sin(side);
  }

  x += cfg.offset_x;
  y += cfg.offset_y;

  if(abs(t - t_step1_middle) < dt_half_step * cfg.step_up_ratio) {
    z = leg.default_z+cfg.delta_z;
  }
  else if(abs(t - t_step2_middle) < dt_half_step * cfg.step_up_ratio) {
    z = leg.default_z;
  }
  else {
    z = leg.default_z;
  }

}

void AnimTurn::get_walk_pos_2(WalkConfig& cfg, LegConfig& leg, double t, double& x, double& y, double& z) {

  double t_step1_middle = cfg.period / 4.0;
  double t_step2_middle = cfg.period * 3.0 / 4.0;

  double dt_half_step = cfg.period / 4.0;
  double side = (135.0*3.1415/180);
  if(leg.default_y < 0) {
    side = ((180+135.0)*3.1415/180);
  }

  if(abs(t - t_step1_middle) < dt_half_step * cfg.move_ratio) {
    double t2 = (t - t_step1_middle) / (dt_half_step * cfg.move_ratio);
    x = default_ray * cos(side - _way*t2*3.1415/round_divisor);
    y = default_ray * sin(side - _way*t2*3.1415/round_divisor);
  }
  else if(abs(t - t_step2_middle) < dt_half_step * cfg.move_ratio) {
    double t2 = (t - t_step2_middle) / (dt_half_step * cfg.move_ratio);
    x = default_ray * cos(side + _way*t2*3.1415/round_divisor);
    y = default_ray * sin(side + _way*t2*3.1415/round_divisor);
  }
  else if(abs(t - cfg.period/2.0) < dt_half_step) {
    x = default_ray * cos(side - _way*3.1415/round_divisor);
    y = default_ray * sin(side - _way*3.1415/round_divisor);
  }
  else if(abs(t - cfg.period/2.0) > dt_half_step) {
    x = default_ray * cos(side + _way*3.1415/round_divisor);
    y = default_ray * sin(side + _way*3.1415/round_divisor);
  }
  else {
    x = default_ray * cos(side);
    y = default_ray * sin(side);
  }

  x += cfg.offset_x;
  y += cfg.offset_y;

  if(abs(t - t_step1_middle) < dt_half_step * cfg.step_up_ratio) {
    z = leg.default_z;
  }
  else if(abs(t - t_step2_middle) < dt_half_step * cfg.step_up_ratio) {
    z = leg.default_z+cfg.delta_z;
  }
  else {
    z = leg.default_z;
  }

}

void AnimTurn::update(LegAction& lf, LegAction& rf, LegAction& rb, LegAction& lb) {
  t = add_mod(t, 1.0/freq, cfg.period);
  get_walk_pos_1(cfg, lfc, t, lf.x, lf.y, lf.z);
  get_walk_pos_2(cfg, rfc, t, rf.x, rf.y, rf.z);
  get_walk_pos_1(cfg, rbc, t, rb.x, rb.y, rb.z);
  get_walk_pos_2(cfg, lbc, t, lb.x, lb.y, lb.z);
}
