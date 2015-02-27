EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:arduino_shieldsNCL
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 5
Title "noname.sch"
Date "27 feb 2015"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ARDUINO_MEGA_SHIELD SHIELD?
U 1 1 54F06AEB
P 5650 3750
F 0 "SHIELD?" H 5250 6250 60  0000 C CNN
F 1 "ARDUINO_MEGA_SHIELD" H 5550 1050 60  0000 C CNN
F 2 "" H 5650 3750 60  0000 C CNN
F 3 "" H 5650 3750 60  0000 C CNN
	1    5650 3750
	1    0    0    -1  
$EndComp
$Sheet
S 1550 3500 800  650 
U 54F06B67
F0 "SERVO1" 50
F1 "sch/servo.sch" 50
F2 "GND" I R 2350 4000 60 
F3 "PWM" I R 2350 3600 60 
F4 "POW_5V" I R 2350 3800 60 
$EndSheet
$Sheet
S 1550 2450 800  650 
U 54F06B67
F0 "SERVO2" 50
F1 "sch/servo.sch" 50
F2 "GND" I R 2350 2950 60 
F3 "PWM" I R 2350 2550 60 
F4 "POW_5V" I R 2350 2750 60 
$EndSheet
$Sheet
S 1550 1350 800  650 
U 54F06B67
F0 "SERVO3" 50
F1 "sch/servo.sch" 50
F2 "GND" I R 2350 1850 60 
F3 "PWM" I R 2350 1450 60 
F4 "POW_5V" I R 2350 1650 60 
$EndSheet
$Sheet
S 3100 1300 850  700 
U 54F0889F
F0 "I2C_1" 50
F1 "sch/i2c.sch" 50
F2 "GND" I R 3950 1900 60 
F3 "LOG_5V" I R 3950 1750 60 
F4 "SCL" I R 3950 1600 60 
F5 "SDA" I R 3950 1450 60 
$EndSheet
$EndSCHEMATC
