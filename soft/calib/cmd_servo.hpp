#ifndef CMD_SERVO_HPP
#define CMD_SERVO_HPP

#include "cmd.hpp"

class SetServo : public Command {
public:
  SetServo(void);
  const char* name(void);
  void run(char* args[]);
};

class GetServo : public Command {
public:
  GetServo(void);
  const char* name(void);
  void run(char* args[]);
};

class CtrlServo : public Command {
public:
  CtrlServo(void);
  const char* name(void);
  void run(char* args[]);
};

class SetDefaultServo : public Command {
public:
  SetDefaultServo(void);
  const char* name(void);
  void run(char* args[]);
};

class SetMaxServo : public Command {
public:
  SetMaxServo(void);
  const char* name(void);
  void run(char* args[]);
};

class SetMinServo : public Command {
public:
  SetMinServo(void);
  const char* name(void);
  void run(char* args[]);
};


#endif//CMD_SERVO_HPP
