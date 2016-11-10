#!/bin/bash

BIN=embed-io

avr-objcopy -O ihex build/bin/${BIN} ${BIN}.hex
sudo avrdude -cwiring -patmega2560 -P /dev/ttyACM0 -U flash:w:${BIN}.hex -D
