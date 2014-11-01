#!/bin/bash

BIN=calib

avr-objcopy -O ihex ${BIN}_atmega2560.elf ${BIN}_atmega2560.hex
sudo avrdude -cwiring -patmega2560 -P /dev/ttyACM0 -U flash:w:${BIN}_atmega2560.hex -D
