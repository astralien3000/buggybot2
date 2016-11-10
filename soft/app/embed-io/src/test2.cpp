#include "test.hpp"

Aversive::Stream::HAL::UARTStream<SCSettings> scio1;
Aversive::Feetech::SC<decltype(scio1)> sc1(scio1);
