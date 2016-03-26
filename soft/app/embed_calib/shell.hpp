#ifndef SHELL_HPP
#define SHELL_HPP

#include <device/stream/uart_stream.hpp>

class Shell {
public:
  Shell(void);

  void run(void);

private:
  UartStream<0> io;
};

#endif//SHELL_HPP
