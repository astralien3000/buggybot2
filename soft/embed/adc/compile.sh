avr-g++ -mmcu=atmega2560 -std=c++11 -I/home/astralien3000/aversive--/build/eirbot2014_atmega2560/include/ -L /home/astralien3000/aversive--/build/eirbot2014_atmega2560/lib/ main.cpp -laversive_eirbot2014_atmega2560
avr-objcopy -O ihex a.out test.hex


avr-g++ -mmcu=atmega128 -std=c++11 -I/home/astralien3000/aversive--/build/eirbot2014_atmega128/include/ -L /home/astralien3000/aversive--/build/eirbot2014_atmega128/lib/ test.cpp -laversive_eirbot2014_atmega128 -o testUNIOC.elf
avr-objcopy -O ihex testUNIOC.elf testUNIOC.hex

