#include "cmd_servo.hpp"

#include "servo_config.hpp"

#include <stdlib.h>
#include <string.h>

////////////////////////////////////////
// SET

SetServo::SetServo(void) {

}

const char*
SetServo::name(void) {
  static const char* name = "set";
  return name;
}

void
SetServo::run(char* args[]) {
  if(args[1] == 0 || args[2] == 0) {
    *io << args[0] << " : error\n";
    return;
  }

  for(u8 i = 0 ; servos[i].dev ; i++) {
    if(strcmp(servos[i].conf->name, args[1]) == 0) {
      servos[i].dev->setValue(atoi(args[2]));
      return;
    }
  }

  *io << args[0] << " : error\n";
}

////////////////////////////////////////
// SET ANGLE

SetAngleServo::SetAngleServo(void) {

}

const char*
SetAngleServo::name(void) {
  static const char* name = "set-angle";
  return name;
}

void
SetAngleServo::run(char* args[]) {
  if(args[1] == 0 || args[2] == 0) {
    *io << args[0] << " : error\n";
    return;
  }

  for(u8 i = 0 ; servos[i].dev ; i++) {
    if(strcmp(servos[i].conf->name, args[1]) == 0) {
      s32 angle = atoi(args[2]) - servos[i].conf->min.angle;
      s32 cmd = (angle - servos[i].conf->min.angle) * (servos[i].conf->max.pwm - servos[i].conf->min.pwm);

      if(servos[i].conf->max.angle != servos[i].conf->min.angle) {
        cmd = cmd / (servos[i].conf->max.angle - servos[i].conf->min.angle);
        cmd += servos[i].conf->min.pwm;
        servos[i].dev->setValue(cmd);
      }
      else {
        servos[i].dev->setValue(servos[i].conf->default_pwm);
      }
      return;
    }
  }

  *io << args[0] << " : error\n";
}

////////////////////////////////////////
// MAIN

MainServo::MainServo(void) {

}

const char*
MainServo::name(void) {
  static const char* name = "main";
  return name;
}

void
MainServo::run(char* args[]) {

  while(1) {
    for(u8 i = 0 ; servos[i].dev ; i++) {
      int a = 0;
      *io >> a;

      s32 angle = a - servos[i].conf->min.angle;
      s32 cmd = angle * (servos[i].conf->max.pwm - servos[i].conf->min.pwm);
      cmd = cmd / (servos[i].conf->max.angle - servos[i].conf->min.angle);
      cmd += servos[i].conf->min.pwm;
	
      servos[i].dev->setValue(cmd);

      //*io << cmd << "\n";
    }
  }
}


////////////////////////////////////////
// GET

GetServo::GetServo(void) {

}

const char*
GetServo::name(void) {
  static const char* name = "get";
  return name;
}

void
GetServo::run(char* args[]) {
  if(args[1] == 0) {
    *io << args[0] << " : error\n";
    return;
  }

  for(u8 i = 0 ; servos[i].dev ; i++) {
    if(strcmp(servos[i].conf->name, args[1]) == 0) {
      *io << "name : " << servos[i].conf->name << "\n";
      *io << "pin : " << servos[i].conf->pin << "\n";
      *io << "current : " << servos[i].dev->getValue() << "\n";
      *io << "default : " << servos[i].conf->default_pwm << "\n";
      *io << "min : " << servos[i].conf->min.pwm << "(" << servos[i].conf->min.angle << ")\n";
      *io << "max : " << servos[i].conf->max.pwm << "(" << servos[i].conf->max.angle << ")\n";
      return;
    }
  }

  *io << args[0] << " : error\n";
}

/////////////////////////////////
// CTRL

CtrlServo::CtrlServo(void) {

}

const char*
CtrlServo::name(void) {
  static const char* name = "ctrl";
  return name;
}

void
CtrlServo::run(char* args[]) {
  if(args[1] == 0) {
    *io << args[0] << " : error\n";
    return;
  }

  GenericServoTester* mydev = 0;

  for(u8 i = 0 ; servos[i].dev ; i++) {
    if(strcmp(servos[i].conf->name, args[1]) == 0) {
      mydev = servos[i].dev;
    }
  }

  if(mydev == 0) {
    *io << args[0] << " : error\n";
    return;
  }


  char cmd = '\0';
  while(cmd != 'q') {
    *io << mydev->getValue() << "\n";
    cmd = io->getValue();

    if(cmd == 'p') {
      mydev->setValue(mydev->getValue()+1);
    }
    else if(cmd == 'm') {
      mydev->setValue(mydev->getValue()-1);
    }

  }
}

////////////////////////////////////////
// SET DEFAULT

SetDefaultServo::SetDefaultServo(void) {

}

const char*
SetDefaultServo::name(void) {
  static const char* name = "set-default";
  return name;
}

void
SetDefaultServo::run(char* args[]) {
  if(args[1] == 0) {
    *io << args[0] << " : error\n";
    return;
  }

  for(u8 i = 0 ; servos[i].dev ; i++) {
    if(strcmp(servos[i].conf->name, args[1]) == 0) {
      servos[i].conf->default_pwm = servos[i].dev->getValue();
      return;
    }
  }

  *io << args[0] << " : error\n";
}

////////////////////////////////////////
// SET MAX

SetMaxServo::SetMaxServo(void) {

}

const char*
SetMaxServo::name(void) {
  static const char* name = "set-max";
  return name;
}

void
SetMaxServo::run(char* args[]) {
  if(args[1] == 0 || args[2] == 0) {
    *io << args[0] << " : error\n";
    return;
  }

  for(u8 i = 0 ; servos[i].dev ; i++) {
    if(strcmp(servos[i].conf->name, args[1]) == 0) {
      servos[i].conf->max.pwm = servos[i].dev->getValue();
      servos[i].conf->max.angle = atoi(args[2]);
      return;
    }
  }

  *io << args[0] << " : error\n";
}

////////////////////////////////////////
// SET MIN

SetMinServo::SetMinServo(void) {

}

const char*
SetMinServo::name(void) {
  static const char* name = "set-min";
  return name;
}

void
SetMinServo::run(char* args[]) {
  if(args[1] == 0 || args[2] == 0) {
    *io << args[0] << " : error\n";
    return;
  }

  for(u8 i = 0 ; servos[i].dev ; i++) {
    if(strcmp(servos[i].conf->name, args[1]) == 0) {
      servos[i].conf->min.pwm = servos[i].dev->getValue();
      servos[i].conf->min.angle = atoi(args[2]);
      return;
    }
  }

  *io << args[0] << " : error\n";
}
