sudo avrdude -cwiring -patmega2560 -P /dev/ttyACM0 -U flash:w:test.hex -D
