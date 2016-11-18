AVERSIVE_ROOT ?= $(PWD)/../../../../AversivePlusPlus
CONAN ?= $(AVERSIVE_ROOT)/tools/bin/conan

all:
	@mkdir -p build && cd build && $(CONAN) install -s target=native .. --build
	@cd build && $(CONAN) build ..
