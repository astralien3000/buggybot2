PACKAGE_NAME = device-buggybot-adm2560

AVERSIVE_ROOT ?= $(PWD)/../../../../AversivePlusPlus
CONAN ?= $(AVERSIVE_ROOT)/tools/bin/conan

################################
.PHONY: all export

################################
all:
	@echo "Usage: make {export,clean,mrpoper}"

################################
clean:
	@rm -rf build

mrproper: clean
	@rm -f *~
	@rm -f *.pyc

################################
SOURCES = $(wildcard *.hpp)

export: build/exported
	@touch build/exported

build/exported: build $(SOURCES) conanfile.py
	@$(CONAN) export AversivePlusPlus/dev

################################
build:
	@mkdir $@
