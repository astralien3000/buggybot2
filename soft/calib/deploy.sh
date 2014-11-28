#!/bin/bash

BIN=calib

avr-objcopy -O ihex build/${BIN} ${BIN}.hex
sudo avrdude -cwiring -patmega2560 -P /dev/ttyACM0 -U flash:w:${BIN}.hex -D
