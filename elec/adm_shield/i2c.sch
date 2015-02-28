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
LIBS:adm_shield-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 23 24
Title ""
Date "28 feb 2015"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 4350 2500 3    60   Input ~ 0
GND
Text HLabel 4550 2500 3    60   Input ~ 0
SCL
Text HLabel 4650 2500 3    60   Input ~ 0
SDA
Text HLabel 3550 2250 2    60   Input ~ 0
LOG_5V
Text HLabel 3050 2450 0    60   Input ~ 0
SCL
Text HLabel 3050 2250 0    60   Input ~ 0
SDA
Text HLabel 3550 2450 2    60   Input ~ 0
LOG_5V
$Comp
L R R_SDA1
U 1 1 54F0E4E0
P 3300 2250
F 0 "R_SDA1" V 3380 2250 40  0000 C CNN
F 1 "R" V 3307 2251 40  0000 C CNN
F 2 "~" V 3230 2250 30  0000 C CNN
F 3 "~" H 3300 2250 30  0000 C CNN
	1    3300 2250
	0    -1   -1   0   
$EndComp
$Comp
L R R_SCL1
U 1 1 54F0E4EF
P 3300 2450
F 0 "R_SCL1" V 3380 2450 40  0000 C CNN
F 1 "R" V 3307 2451 40  0000 C CNN
F 2 "~" V 3230 2450 30  0000 C CNN
F 3 "~" H 3300 2450 30  0000 C CNN
	1    3300 2450
	0    -1   -1   0   
$EndComp
Text HLabel 4450 2500 3    60   Input ~ 0
LOG_5V
$Comp
L CONN_4 I2C0
U 1 1 54F1D6BD
P 4500 2150
F 0 "I2C0" V 4450 2150 50  0000 C CNN
F 1 "CONN_4" V 4550 2150 50  0000 C CNN
F 2 "~" H 4500 2150 60  0000 C CNN
F 3 "~" H 4500 2150 60  0000 C CNN
	1    4500 2150
	0    -1   -1   0   
$EndComp
Text HLabel 4850 2500 3    60   Input ~ 0
GND
Text HLabel 5050 2500 3    60   Input ~ 0
SCL
Text HLabel 5150 2500 3    60   Input ~ 0
SDA
Text HLabel 4950 2500 3    60   Input ~ 0
LOG_5V
$Comp
L CONN_4 I2C1
U 1 1 54F1D6D7
P 5000 2150
F 0 "I2C1" V 4950 2150 50  0000 C CNN
F 1 "CONN_4" V 5050 2150 50  0000 C CNN
F 2 "~" H 5000 2150 60  0000 C CNN
F 3 "~" H 5000 2150 60  0000 C CNN
	1    5000 2150
	0    -1   -1   0   
$EndComp
Text HLabel 5350 2500 3    60   Input ~ 0
GND
Text HLabel 5550 2500 3    60   Input ~ 0
SCL
Text HLabel 5650 2500 3    60   Input ~ 0
SDA
Text HLabel 5450 2500 3    60   Input ~ 0
LOG_5V
$Comp
L CONN_4 I2C2
U 1 1 54F1D6E1
P 5500 2150
F 0 "I2C2" V 5450 2150 50  0000 C CNN
F 1 "CONN_4" V 5550 2150 50  0000 C CNN
F 2 "~" H 5500 2150 60  0000 C CNN
F 3 "~" H 5500 2150 60  0000 C CNN
	1    5500 2150
	0    -1   -1   0   
$EndComp
Text HLabel 5850 2500 3    60   Input ~ 0
GND
Text HLabel 6050 2500 3    60   Input ~ 0
SCL
Text HLabel 6150 2500 3    60   Input ~ 0
SDA
Text HLabel 5950 2500 3    60   Input ~ 0
LOG_5V
$Comp
L CONN_4 I2C3
U 1 1 54F1D6EB
P 6000 2150
F 0 "I2C3" V 5950 2150 50  0000 C CNN
F 1 "CONN_4" V 6050 2150 50  0000 C CNN
F 2 "~" H 6000 2150 60  0000 C CNN
F 3 "~" H 6000 2150 60  0000 C CNN
	1    6000 2150
	0    -1   -1   0   
$EndComp
Text HLabel 6350 2500 3    60   Input ~ 0
GND
Text HLabel 6550 2500 3    60   Input ~ 0
SCL
Text HLabel 6650 2500 3    60   Input ~ 0
SDA
Text HLabel 6450 2500 3    60   Input ~ 0
LOG_5V
$Comp
L CONN_4 I2C4
U 1 1 54F1D6F5
P 6500 2150
F 0 "I2C4" V 6450 2150 50  0000 C CNN
F 1 "CONN_4" V 6550 2150 50  0000 C CNN
F 2 "~" H 6500 2150 60  0000 C CNN
F 3 "~" H 6500 2150 60  0000 C CNN
	1    6500 2150
	0    -1   -1   0   
$EndComp
$EndSCHEMATC
