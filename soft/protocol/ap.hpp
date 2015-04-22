#ifndef AP_HPP
#define AP_HPP

#include <base/integer.hpp>

#define PACKED __attribute__((packed))

namespace AP {
  constexpr u16 SYNC = 0xA572;
  
  struct Dummy {
  };

  struct Header {
    u8 cls;
    u8 id;
    u8 length;
  } PACKED;
  
  template<class Payload>
  struct Message {
    Header header;
    Payload payload;
  } PACKED;

  template<class Payload>
  struct PollRequest {
    Header header;
    typename Payload::Poll payload;
  } PACKED;
  
  template<template<class T> class MsgType, class Payload>
  struct Pack {
    u16 sync;
    MsgType<Payload> message;
    u16 check;
  } PACKED;

  namespace Buggybot {
    
    namespace Join {
      constexpr u8 SHOULDER = 0x01;
      constexpr u8 ARM      = 0x02;
      constexpr u8 FOREARM  = 0x04;
    }
    
    namespace Leg {
      constexpr u8 LF = 0x01;
      constexpr u8 RF = 0x02;
      constexpr u8 RB = 0x04;
      constexpr u8 LB = 0x08;
    }
    
    namespace Servo {
      using namespace Join;
      using namespace Leg;
    
      constexpr u8 LF0 = (LF << 4) | SHOULDER;
      constexpr u8 LF1 = (LF << 4) | ARM;
      constexpr u8 LF2 = (LF << 4) | FOREARM;

      constexpr u8 RF0 = (RF << 4) | SHOULDER;
      constexpr u8 RF1 = (RF << 4) | ARM;
      constexpr u8 RF2 = (RF << 4) | FOREARM;

      constexpr u8 RB0 = (RB << 4) | SHOULDER;
      constexpr u8 RB1 = (RB << 4) | ARM;
      constexpr u8 RB2 = (RB << 4) | FOREARM;

      constexpr u8 LB0 = (LB << 4) | SHOULDER;
      constexpr u8 LB1 = (LB << 4) | ARM;
      constexpr u8 LB2 = (LB << 4) | FOREARM;
    }
    
  }

  namespace Protocol {
    struct Protocol {
      static constexpr u8 CLS = 0;
    };
    
    struct Ack : Protocol {
      static constexpr u8 ID = 0;
    
      u8 cls;
      u8 id;
    } PACKED;
    
    struct Nak : Protocol {
      static constexpr u8 ID = 1;
    } PACKED;
    
    struct Ready : Protocol {
      static constexpr u8 ID = 2;
    } PACKED;
  }

  namespace Config {
    struct Config {
      static constexpr u8 CLS = 1;
    };
    
    struct Save : Config {
      static constexpr u8 ID = 0;
    } PACKED;
    
    struct Load : Config {
      static constexpr u8 ID = 1;
    } PACKED;
    
    struct Servo : Config {
      static constexpr u8 ID = 3;
      
      struct Poll {
        u8 id;
      } servo;
      
      u16 default_pwm;
      s16 angle1;
      u16 angle1_pwm;
      s16 angle2;
      u16 angle2_pwm;
    } PACKED;
    
  }
  
  namespace Actuator {
    struct Actuator {
      static constexpr u8 CLS = 2;
    };
    
    struct ServoAngle : Actuator {
      static constexpr u8 ID = 0;
      
      struct Poll {
        u8 id;
      } servo;
      
      s16 angle;
    } PACKED;
    
    struct ServoPWM : Actuator {
      static constexpr u8 ID = 1;
      
      struct Poll {
        u8 id;
      } servo;
      
      u16 pwm;
    } PACKED;
  }
  
  namespace Sensor {
    struct Sensor {
      static constexpr u8 CLS = 3;
    } PACKED;
    
    struct Bumper : Sensor {
      static constexpr u8 ID = 0;
      
      struct Poll {
	u8 id;
      } bumper;

      u16 mask;
    } PACKED;
    
    struct GP2 : Sensor {
      static constexpr u8 ID = 1;
      
      u8 gp2;
      
      u32 value;
    } PACKED;
    
  }
  
  namespace Buggybot {
    struct Buggybot {
      static constexpr u8 CLS = 4;
    };
    
    struct ServosCtrl : Buggybot {
      static constexpr u8 ID = 0;
      
      s16 angle_lf0;
      s16 angle_lf1;
      s16 angle_lf2;

      s16 angle_rf0;
      s16 angle_rf1;
      s16 angle_rf2;

      s16 angle_rb0;
      s16 angle_rb1;
      s16 angle_rb2;

      s16 angle_lb0;
      s16 angle_lb1;
      s16 angle_lb2;
    } PACKED;
  }
}

#endif//AP_HPP
