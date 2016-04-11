#include "test.hpp"

Stream::HAL::UARTStream<SCSettings> scio1;
Feetech::SC<decltype(scio1)> sc1(scio1);
