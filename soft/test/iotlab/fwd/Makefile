AVERSIVEPLUSPLUS_ROOT ?= $(PWD)/../../../../../AversivePlusPlus
CONAN ?= $(AVERSIVEPLUSPLUS_ROOT)/tools/bin/conan

BIN=fwd

.PHONY: all samr21 compile clean

all: compile

compile: build build/install
	@cd build && $(CONAN) build ..

build/install: conanfile.py
	@cd build && $(CONAN) install $(SETTINGS) .. --build
	@touch build/install

build:
	@mkdir build

clean:
	@rm -rf build

flash: all
	@make -f Makefile.RIOT flash

term:
	@make -f Makefile.RIOT term
