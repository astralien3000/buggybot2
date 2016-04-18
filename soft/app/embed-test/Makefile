AVERSIVE_ROOT=/usr/local/AversivePlusPlus
MCU=atmega2560

NAME=embed-test

TOOLCHAIN=$(shell find $(AVERSIVE_ROOT) -name "$(MCU).cmake")

all:
	mkdir -p build && cd build && cmake .. -DAVERSIVE_ROOT=$(AVERSIVE_ROOT) -DCMAKE_TOOLCHAIN_FILE=$(TOOLCHAIN) -DNAME=$(NAME) && make
