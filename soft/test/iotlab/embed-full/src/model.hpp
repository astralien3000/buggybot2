#ifndef MODEL_HPP
#define MODEL_HPP

#include <stream/riot/uart_stream.hpp>
#include <feetech/sc.hpp>


extern Aversive::Feetech::SC<RIOT::UARTStream<>> sc;

extern uint8_t map[12];



#endif//MODEL_HPP
