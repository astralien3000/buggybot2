#ifndef CMD_HPP
#define CMD_HPP

#include <device/stream/formatted_stream.hpp>

class Command {
public:
  static FormattedStream* io;

public:
  virtual const char* name(void) = 0;
  virtual void run(char* args[]) = 0;
};

#endif//CMD_HPP
