#include <aversive.hpp>
#include <hardware/interrupts.hpp>
#include <board/adm2560.hpp>

#include "servo_tester.hpp"

#include "shell.hpp"

void init_servos(void);

int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  
  init_servos();
  Shell sh;

  Interrupts::set();
  
  while(Aversive::sync()) {
    sh.run();
  }
  
  Aversive::setReturnCode(0);
  return Aversive::exit();
}
