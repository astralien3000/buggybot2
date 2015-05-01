#!/bin/bash

BIN=server

avr-objcopy -O ihex build/${BIN}.elf build/${BIN}.hex
sudo avrdude -cwiring -patmega2560 -P /dev/ttyACM0 -U flash:w:build/${BIN}.hex -D
