AVERSIVE_ROOT=/home/astralien3000/aversive--

MCU=atmega2560
DISTRIB=eirbot2014_$MCU

BUILD_DIR=build
TARGET=server

SOURCES=main.cpp

mkdir $BUILD_DIR
avr-g++ -mmcu=$MCU -std=c++11 -I../../include/{adc,protocol,servos} -I$AVERSIVE_ROOT/build/$DISTRIB/include/ -L$AVERSIVE_ROOT/build/$DISTRIB/lib/ $SOURCES -laversive_$DISTRIB -o $BUILD_DIR/$TARGET.elf
avr-objcopy -O ihex $BUILD_DIR/$TARGET.elf $BUILD_DIR/$TARGET.hex
