#include <aversive.hpp>
#include <hardware/interrupts.hpp>
#include <board/adm2560.hpp>

#include "servo_tester.hpp"


int main(int argc, char** argv) {
  (void) argc;
  (void) argv;
  
  Aversive::init();
  
  ServoTester<ADM2560::Pinmap::D10> test1; // D10
  ServoTester<ADM2560::Pinmap::D11> test2; // D11
  ServoTester<ADM2560::Pinmap::D12> test3; // D12

  ServoTester<ADM2560::Pinmap::D2> test4; // D2
  ServoTester<ADM2560::Pinmap::D3> test5; // D3
  ServoTester<ADM2560::Pinmap::D4> test6; // D4

  Interrupts::set();
  
  while(Aversive::sync()) {
    test1.update(800); // Right arm
    test2.update(400); // Left shoulder
    test3.update(1200); // Left forarm

    test4.update(800); // Left arm
    test5.update(450); // Right forarm
    test6.update(1200); // Right shoulder
    for(volatile u32 t = 0 ; t < 2 ; t++) {
    }
  }
  
  Aversive::setReturnCode(0);
  return Aversive::exit();
}
