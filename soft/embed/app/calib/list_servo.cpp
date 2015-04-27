#include "list_servo.hpp"

#include "servo_config.hpp"

#include <string.h>


ListServo::ListServo(void) {

}

const char*
ListServo::name(void) {
  static const char* name = "ls";
  return name;
}

void
ListServo::run(char* args[]) {
  (void) args;

  for(u8 i = 0 ; servos[i].conf != 0 ; i++) {
    *io << servos[i].conf->name;
    *io << "\n";
  }
}

////////////////////////////////////////

PrintServo::PrintServo(void) {

}

const char*
PrintServo::name(void) {
  static const char* name = "print";
  return name;
}

void
PrintServo::run(char* args[]) {
  if(args[1] == 0) {
    *io << args[0] << " : error\n";
    return;
  }

  for(u8 i = 0 ; servos[i].dev ; i++) {
    if(strcmp(servos[i].conf->name, args[1]) == 0) {
      *io << servos[i].conf->name << " ; ";
      *io << servos[i].conf->pin << " ; ";
      *io << servos[i].conf->default_pwm << " ; ";
      *io << servos[i].conf->max.angle << " ; ";
      *io << servos[i].conf->max.pwm << " ; ";
      *io << servos[i].conf->min.angle << " ; ";
      *io << servos[i].conf->min.pwm << "\n";
      return;
    }
  }

  *io << args[0] << " : error\n";
}
