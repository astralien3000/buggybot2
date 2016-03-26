#ifndef BUGGYBOT_SERVOS_HPP
#define BUGGYBOT_SERVOS_HPP

#include "servo.hpp"
#include <board/adm2560.hpp>

#ifdef BUGGYBOT_SERVOS_INTERN
#define EXTERN
#else
#define EXTERN extern
#endif

EXTERN Servo<ADM2560::Pinmap::D11> lf0;
EXTERN Servo<ADM2560::Pinmap::D12> lf1;
EXTERN Servo<ADM2560::Pinmap::D13> lf2;
  
EXTERN Servo<ADM2560::Pinmap::D6>  rf0;
EXTERN Servo<ADM2560::Pinmap::D7>  rf1;
EXTERN Servo<ADM2560::Pinmap::D8>  rf2;

EXTERN Servo<ADM2560::Pinmap::D5>  rb0;
EXTERN Servo<ADM2560::Pinmap::D3>  rb1;
EXTERN Servo<ADM2560::Pinmap::D2>  rb2;

EXTERN Servo<ADM2560::Pinmap::D46> lb0;
EXTERN Servo<ADM2560::Pinmap::D45> lb1;
EXTERN Servo<ADM2560::Pinmap::D44> lb2;

#endif//BUGGYBOT_SERVOS_HPP
