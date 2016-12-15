#include "model.hpp"

static RIOT::UARTStream<> _sc_uart(1, 1000000);
Aversive::Feetech::SC<RIOT::UARTStream<>> sc(_sc_uart);

uint8_t map[12] = {2,3,4,5,6,7,8,9,10,11,12,13};
