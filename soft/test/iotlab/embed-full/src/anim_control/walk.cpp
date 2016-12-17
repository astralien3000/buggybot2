#include "walk.hpp"

double t = 0;

void AnimWalk::get_walk_pos_1(WalkConfig& cfg, LegConfig& leg, double t, double& x, double& y, double& z) {

  double t_step1_middle = cfg.period / 4.0;
  double t_step2_middle = cfg.period * 3.0 / 4.0;

  double dt_half_step = cfg.period / 4.0;

  y = leg.default_y;

  if(abs(t - t_step1_middle) < dt_half_step * cfg.move_ratio) {
      double t2 = (t - t_step1_middle) / (dt_half_step * cfg.move_ratio);
      x = leg.default_x + t2*cfg.step_size/2.0;
    }
  else if(abs(t - t_step2_middle) < dt_half_step * cfg.move_ratio) {
      double t2 = (t - t_step2_middle) / (dt_half_step * cfg.move_ratio);
      x = leg.default_x - t2*cfg.step_size/2.0;
    }
  else if(abs(t - cfg.period/2.0) < dt_half_step) {
      x = leg.default_x + cfg.step_size/2.0;
    }
  else if(abs(t - cfg.period/2.0) > dt_half_step) {
      x = leg.default_x - cfg.step_size/2.0;
    }
  else {
      x = leg.default_x;
    }

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

void AnimWalk::get_walk_pos_2(WalkConfig& cfg, LegConfig& leg, double t, double& x, double& y, double& z) {

  double t_step1_middle = cfg.period / 4.0;
  double t_step2_middle = cfg.period * 3.0 / 4.0;

  double dt_half_step = cfg.period / 4.0;

  y = leg.default_y;

  if(abs(t - t_step1_middle) < dt_half_step * cfg.move_ratio) {
      double t2 = (t - t_step1_middle) / (dt_half_step * cfg.move_ratio);
      x = leg.default_x - t2*cfg.step_size/2.0;
    }
  else if(abs(t - t_step2_middle) < dt_half_step * cfg.move_ratio) {
      double t2 = (t - t_step2_middle) / (dt_half_step * cfg.move_ratio);
      x = leg.default_x + t2*cfg.step_size/2.0;
    }
  else if(abs(t - cfg.period/2.0) < dt_half_step) {
      x = leg.default_x - cfg.step_size/2.0;
    }
  else if(abs(t - cfg.period/2.0) > dt_half_step) {
      x = leg.default_x + cfg.step_size/2.0;
    }
  else {
      x = leg.default_x;
    }

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

void AnimWalk::update(LegAction& lf, LegAction& rf, LegAction& rb, LegAction& lb) {
  t = add_mod(t, 1.0/freq, cfg.period);
  get_walk_pos_1(cfg, lfc, t, lf.x, lf.y, lf.z);
  get_walk_pos_2(cfg, rfc, t, rf.x, rf.y, rf.z);
  get_walk_pos_1(cfg, rbc, t, rb.x, rb.y, rb.z);
  get_walk_pos_2(cfg, lbc, t, lb.x, lb.y, lb.z);
}
