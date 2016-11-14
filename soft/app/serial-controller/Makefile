AVERSIVE_ROOT ?= $(PWD)/../../../../AversivePlusPlus
CONAN ?= $(AVERSIVE_ROOT)/tools/bin/conan

all:
	@mkdir -p build && cd build && $(CONAN) install -s compiler=avr-gcc -s compiler.version=4.9 -s target=native .. --build
	@cd build && $(CONAN) build ..
