avr-g++ -mmcu=atmega2560 -std=c++11 -I../servos -I../adc -I/home/astralien3000/aversive--/build/eirbot2014_atmega2560/include/ -L/home/astralien3000/aversive--/build/eirbot2014_atmega2560/lib/ arduino.cpp -laversive_eirbot2014_atmega2560 -o arduino.elf
avr-objcopy -O ihex arduino.elf arduino.hex

#g++ -std=c++11 -I. -I/home/astralien3000/aversive--/modules/{base,container,math}/include host.cpp -o host.elf
