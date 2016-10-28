AVERSIVE_ROOT=/usr/local/AversivePlusPlus
MCU ?= native

NAME=embed

TOOLCHAIN=$(shell find $(AVERSIVE_ROOT) -name "$(MCU).cmake")

all:
	mkdir -p build && cd build && cmake .. -DAVERSIVE_ROOT=$(AVERSIVE_ROOT) -DCMAKE_TOOLCHAIN_FILE=$(TOOLCHAIN) -DNAME=$(NAME) && make
