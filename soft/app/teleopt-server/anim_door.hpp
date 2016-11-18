#ifndef ANIM_DOOR_HPP
#define ANIM_DOOR_HPP

#include "anim_walk.hpp"

#include <filter/average.hpp>
#include <filter/integral.hpp>

#include <map>
using namespace std;

class AnimDoor : public Animation {
  struct timeval t1 = {0,0}, t2 = {0,0};

  double Kp2 = -0.0 / 50.0;
  double Kp1 = -8.0 / 10.0;

  struct WalkConfig {
    double offset_x = -10;
    double half_esp_x = 120;

    double offset_y = 10;
    double half_esp_y = 120;

    double default_z = -130;
    double delta_z = 40;

    double period = 6;

    double step_up_ratio = 0.25;
    double move_ratio = 0.2;

    double step_size = 40;
  } cfg;

  LegConfig lf = {
    cfg.half_esp_x+cfg.offset_x,
    cfg.half_esp_y+cfg.offset_y,
    cfg.default_z
  };

  LegConfig rf = {
    cfg.half_esp_x+cfg.offset_x,
    -cfg.half_esp_y+cfg.offset_y,
    cfg.default_z
  };

  LegConfig lb = {
    -cfg.half_esp_x+cfg.offset_x,
    cfg.half_esp_y+cfg.offset_y,
    cfg.default_z
  };

  LegConfig rb = {
    -cfg.half_esp_x+cfg.offset_x,
    -cfg.half_esp_y+cfg.offset_y,
    cfg.default_z
  };

  LegConfig _leg[4] = {
    lf,
    rf,
    lb,
    rb
  };

  double _t_step_middle[4] = {
    cfg.period * 1.0 / 8.0,
    cfg.period * 3.0 / 8.0,
    cfg.period * 5.0 / 8.0,
    cfg.period * 7.0 / 8.0
  };

  double dt_half_step = cfg.period / 8.0;

  double up_ratio = 0.7;
  double delta_y = 15;
  double delta_x = 15;
  Aversive::Filter::Average<double, 30> avg_y {0};
  Aversive::Filter::Average<double, 30> avg_x {0};

  void get_pos(int id, double t, double& x, double& y, double& z) {

    LegConfig& leg = _leg[id];
    double t_step_middle = _t_step_middle[id];

    x = leg.default_x + cfg.offset_x;
    y = leg.default_y + cfg.offset_y;
    z = leg.default_z;

    if(abs(t - _t_step_middle[0]) < dt_half_step * 0.6) {
        y += avg_y(delta_y);
        x += avg_x(delta_x);
      }
    else if(abs(t - _t_step_middle[1]) < dt_half_step * 0.6) {
        y += avg_y(-delta_y);
        x += avg_x(delta_x);
      }
    else if(abs(t - _t_step_middle[2]) < dt_half_step * 0.6) {
        y += avg_y(delta_y);
        x += avg_x(-delta_x);
      }
    else if(abs(t - _t_step_middle[3]) < dt_half_step * 0.6) {
        y += avg_y(-delta_y);
        x += avg_x(-delta_x);
      }
    else {
        y += avg_y(0);
        x += avg_x(0);
      }

    if(abs(t - t_step_middle) < dt_half_step * up_ratio) {
        z += 40;
        x *= 1.4;
        y *= 1.4;
      }

  }

public:
  virtual void update(void) {
    gettimeofday(&t2, NULL);
    if(abs(t2.tv_usec - t1.tv_usec) > 1000000 / freq) {
        t1.tv_sec = t2.tv_sec;
        t1.tv_usec = t2.tv_usec;

        //t = 7.5;
        t = add_mod(t, 1.0/freq, cfg.period);
        EndpointAction ea;
        vector<EndpointAction> eas;

        ea.label = "LF";
        ea.enable = true;
        get_pos(0, t, ea.x, ea.y, ea.z);
        //send(sock_ik_out, ea);
        eas.push_back(ea);

        ea.label = "RF";
        ea.enable = true;
        get_pos(1, t, ea.x, ea.y, ea.z);
        //send(sock_ik_out, ea);
        eas.push_back(ea);

        ea.label = "LB";
        ea.enable = true;
        get_pos(2, t, ea.x, ea.y, ea.z);
        //send(sock_ik_out, ea);
        eas.push_back(ea);

        ea.label = "RB";
        ea.enable = true;
        get_pos(3, t, ea.x, ea.y, ea.z);
        //send(sock_ik_out, ea);
        eas.push_back(ea);

        //cout << ea.x << " " << ea.y << " " << ea.z << endl;
        send(*sock_ik_out, eas);
      }
  }
};

#endif//ANIM_DOOR_HPP
