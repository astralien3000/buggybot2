#ifndef ANIM_STAND_HPP
#define ANIM_STAND_HPP

#include "anim_walk.hpp"

#include <map>
using namespace std;


class AnimStand : public Animation {
  struct timeval t1 = {0,0}, t2 = {0,0};

  double Kp2 = -0.0 / 50.0;
  double Kp1 = -8.0 / 10.0;

  WalkConfig cfg;

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

public:
  virtual void update(void) {

    gettimeofday(&t2, NULL);
    if(abs(t2.tv_usec - t1.tv_usec) > 1000000 / freq) {
        t1.tv_sec = t2.tv_sec;
        t1.tv_usec = t2.tv_usec;

        EndpointAction ea;
        vector<EndpointAction> eas;

        ea.label = "LF";
        ea.enable = true;
        ea.x = lf.default_x;
        ea.y = lf.default_y;
        ea.z = lf.default_z;
        //send(sock_ik_out, ea);
        eas.push_back(ea);

        ea.label = "RF";
        ea.enable = true;
        ea.x = rf.default_x;
        ea.y = rf.default_y;
        ea.z = rf.default_z;
        //send(sock_ik_out, ea);
        eas.push_back(ea);

        ea.label = "LB";
        ea.enable = true;
        ea.x = lb.default_x;
        ea.y = lb.default_y;
        ea.z = lb.default_z;
        //send(sock_ik_out, ea);
        eas.push_back(ea);

        ea.label = "RB";
        ea.enable = true;
        ea.x = rb.default_x;
        ea.y = rb.default_y;
        ea.z = rb.default_z;
        //send(sock_ik_out, ea);
        eas.push_back(ea);

        //cout << ea.x << " " << ea.y << " " << ea.z << endl;
        send(*sock_ik_out, eas);
      }
  }
};

#endif//ANIM_STAND_HPP
