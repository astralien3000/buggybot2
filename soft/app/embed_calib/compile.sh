avr-gcc -std=c++11 -mmcu=atmega2560 -c -I/home/astralien3000/aversive--/modules/{avr,avr.system,base,device,math,stream,container,multipwm}/include/ *.cpp
avr-gcc -std=c++11 -mmcu=atmega2560 *.o /home/astralien3000/aversive--/build/libaversive_atmega2560.a -o calib.elf
