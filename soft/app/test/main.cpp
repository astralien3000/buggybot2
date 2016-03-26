#include <aversive.hpp>
#include <hardware/interrupts.hpp>
#include <board/adm2560.hpp>

#include <device/pin/output_digital_pin.hpp>

#include "servo_tester.hpp"
#include "servo_config.hpp"

#include "shell.hpp"

#include <avr/io.h>
#include <filter/pid_filter.hpp>
#include "adc_pin.hpp"

void init_servos(void);

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();


  io << "begin\n";
  init_servos();
  DDRD |= 1<<0;
  ADCPin<ADM2560::Pinmap::A8> pos;
  PidFilter pid;

  pid.setGains(160,1,0);
  pid.setOutShift(4);
  pid.setMaxIntegral(1000);

  Interrupts::set();
  char c = 0;
  s32 pwm = 10;
  bool _dir = false;
  s32 cmd = 300;
  
  while(Aversive::sync()) {
    io << cmd << " <--> " << pos.getValue() << "\n";
    pwm = pid.doFilter(cmd - pos.getValue());
    if(pwm < 0) {
      _dir = false;
      pwm = -pwm;
    }
    else {
      _dir = true;
    }
    
    if(_dir) {
      PORTD |= 1<<0;
    }
    else {
      PORTD &= ~(1<<0);
    }
    
    servos[0].dev->setValue(pwm);

    /*
    c = io.getValue();
    
    if(c == 'p') {
      cmd += 1;
    }
    else if(c == 'm') {
      cmd -= 1;
    }
    */


    /*
    c = io.getValue();
    
    if(c == 'p') {
      pwm += 10;
    }
    else if(c == 'm') {
      pwm -= 10;
    }
    else if(c == 'i') {
      _dir = !_dir;
    }
    servos[0].dev->setValue(pwm);
    if(_dir == true) {
      io << "-\n";
    }

    io << pwm << "\n";
    */
  }
  
  Aversive::setReturnCode(0);
  return Aversive::exit();
}
