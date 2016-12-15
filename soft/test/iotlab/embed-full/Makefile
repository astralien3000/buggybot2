AVERSIVEPLUSPLUS_ROOT ?= $(PWD)/../../../../../AversivePlusPlus
CONAN ?= $(AVERSIVEPLUSPLUS_ROOT)/tools/bin/conan

BIN=embed-io

SETTINGS_ARM_CC=-s compiler=arm-none-eabi-gcc -s compiler.version=5.2
SETTINGS_SAMR21=$(SETTINGS_ARM_CC) -s target=samr21-xpro

.PHONY: all samr21 compile clean

all: samr21

samr21: export SETTINGS=$(SETTINGS_SAMR21)
samr21: compile

compile: build build/install
	@cd build && $(CONAN) build ..

build/install: conanfile.py
	@cd build && $(CONAN) install $(SETTINGS) .. --build=coap--
	@touch build/install

build:
	@mkdir build

clean:
	@rm -rf build

flash: all
	@make -f Makefile.RIOT flash

term:
	@make -f Makefile.RIOT term
