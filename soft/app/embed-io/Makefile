AVERSIVE_ROOT ?= $(PWD)/../../../../AversivePlusPlus
CONAN ?= $(AVERSIVE_ROOT)/tools/bin/conan
BIN= embed-io

TARGET ?= "atmega2560"

all:
	@mkdir -p build && cd build && $(CONAN) install -s compiler=avr-gcc -s compiler.version=4.9 -s target=$(TARGET) .. --build
	@cd build && $(CONAN) build ..

flash:
	@avr-objcopy -O ihex build/bin/${BIN} ${BIN}.hex
	@sudo avrdude -cwiring -p$(MCU) -P /dev/ttyACM0 -U flash:w:${BIN}.hex -D
