#ifndef LIST_SERVO_HPP
#define LIST_SERVO_HPP

#include "cmd.hpp"

class ListServo : public Command {
public:
  ListServo(void);

  const char* name(void);

  void run(char* args[]);
};

class PrintServo : public Command {
public:
  PrintServo(void);

  const char* name(void);

  void run(char* args[]);
};

#endif//LIST_SERVO_HPP
