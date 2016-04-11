#ifndef FEETECH_SC_SWITCHER_HPP
#define FEETECH_SC_SWITCHER_HPP

#include "test.hpp"
#include <feetech/sc.hpp>

#include <base/array.hpp>

class SCSwitcher {
private:
  Array<uint8_t, 256> _channel;

public:
  inline bool ping(u8 id) {
    if(sc1.ping(id)) {
        _channel[id] = 1;
      }
    else if(sc2.ping(id)) {
        _channel[id] = 2;
      }
    else {
        _channel[id] = 0;
      }
    return _channel[id] != 0;
  }

  inline void enableTorque(u8 id) {
    if(_channel[id] == 0) {
        ping(id);
      }

    if(_channel[id] == 1) {
        sc1.enableTorque(id);
      }
    else if(_channel[id] == 2) {
        sc2.enableTorque(id);
      }
  }

  inline void disableTorque(u8 id) {
    if(_channel[id] == 0) {
        ping(id);
      }

    if(_channel[id] == 1) {
        sc1.disableTorque(id);
      }
    else if(_channel[id] == 2) {
        sc2.disableTorque(id);
      }
  }

  inline bool isTorqueEnabled(u8 id) {
    if(_channel[id] == 0) {
        ping(id);
      }

    if(_channel[id] == 1) {
        return sc1.isTorqueEnabled(id);
      }
    else if(_channel[id] == 2) {
        return sc2.isTorqueEnabled(id);
      }
    return false;
  }


  inline void setPosition(u8 id, u16 pos) {
    if(_channel[id] == 0) {
        ping(id);
      }

    if(_channel[id] == 1) {
        sc1.setPosition(id, pos);
      }
    else if(_channel[id] == 2) {
        sc2.setPosition(id, pos);
      }
  }

  inline u16 getPosition(u8 id) {
    if(_channel[id] == 0) {
        ping(id);
      }

    if(_channel[id] == 1) {
        return sc1.getPosition(id);
      }
    else if(_channel[id] == 2) {
        return sc2.getPosition(id);
      }
    return 0;
  }

  inline void setId(u8 id, u8 new_id) {
    if(_channel[id] == 0) {
        ping(id);
      }

    if(_channel[id] == 1) {
        sc1.setId(id, new_id);
      }
    else if(_channel[id] == 2) {
        sc2.setId(id, new_id);
      }
  }

  inline s16 getLoad(u8 id) {
    if(_channel[id] == 0) {
        ping(id);
      }

    if(_channel[id] == 1) {
        return sc1.getLoad(id);
      }
    else if(_channel[id] == 2) {
        return sc2.getLoad(id);
      }
    return 0;
  }

  inline s16 getSpeed(u8 id) {
    if(_channel[id] == 0) {
        ping(id);
      }

    if(_channel[id] == 1) {
        return sc1.getSpeed(id);
      }
    else if(_channel[id] == 2) {
        return sc2.getSpeed(id);
      }
    return 0;
  }

};

#endif//FEETECH_SC_SWITCHER_HPP
