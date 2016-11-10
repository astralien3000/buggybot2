#include "test.hpp"

Aversive::Stream::HAL::UARTStream<SCSettings2> scio2;
Aversive::Feetech::SC<decltype(scio2)> sc2(scio2);

#include <hdl/avr/m2560.hpp>

namespace HDL {
  namespace ATMegaxx0_1 {
    namespace Private {
      namespace UART {
        template<> constexpr decltype(UART_ModuleFields<_UART_Defs<(unsigned char)1>>::RXC) UART_ModuleFields<_UART_Defs<(unsigned char)1>>::RXC;
        template decltype(UART_ModuleFields<_UART_Defs<(unsigned char)1>>::RXC) UART_ModuleFields<_UART_Defs<(unsigned char)1>>::RXC;

      }
    }
  }
}

//template struct HDL::ATMegaxx0_1::Private::UART::UART_ModuleFields<HDL::ATMegaxx0_1::Private::UART::_UART_Defs<(unsigned char)0>>;
//DEF()
//template struct HDL::ATMegaxx0_1::Private::UART::UART_ModuleFields<HDL::ATMegaxx0_1::Private::UART::_UART_Defs<(unsigned char)2>>;
