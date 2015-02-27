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
Sheet 20 20
Title ""
Date "27 feb 2015"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_5 ALIM_BOARD
U 1 1 54F28D93
P 6100 3400
F 0 "ALIM_BOARD" V 6050 3400 50  0000 C CNN
F 1 "CONN_5" V 6150 3400 50  0000 C CNN
F 2 "~" H 6100 3400 60  0000 C CNN
F 3 "~" H 6100 3400 60  0000 C CNN
	1    6100 3400
	1    0    0    -1  
$EndComp
Text HLabel 4500 3750 3    60   Input ~ 0
GND
Text HLabel 5700 3600 0    60   Input ~ 0
POW_5V
Text HLabel 4550 3200 0    60   Input ~ 0
EN
Text HLabel 4550 2900 0    60   Input ~ 0
GND
$Comp
L R PULL_DOWN_2.7kOhm
U 1 1 54F28DA2
P 4800 2900
F 0 "PULL_DOWN_2.7kOhm" V 4880 2900 40  0000 C CNN
F 1 "R" V 4807 2901 40  0000 C CNN
F 2 "~" V 4730 2900 30  0000 C CNN
F 3 "~" H 4800 2900 30  0000 C CNN
	1    4800 2900
	0    -1   -1   0   
$EndComp
$Comp
L SW_PUSH SECURITY_SWITCH
U 1 1 54F28DC0
P 4850 3200
F 0 "SECURITY_SWITCH" H 5000 3310 50  0000 C CNN
F 1 "SW_PUSH" H 4850 3120 50  0000 C CNN
F 2 "~" H 4850 3200 60  0000 C CNN
F 3 "~" H 4850 3200 60  0000 C CNN
	1    4850 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 2900 5150 2900
Wire Wire Line
	5150 2900 5150 3200
Wire Wire Line
	5150 3200 5700 3200
$Comp
L CONN_2 POW_BATTERY
U 1 1 54F28DD3
P 4150 3650
F 0 "POW_BATTERY" V 4100 3650 40  0000 C CNN
F 1 "CONN_2" V 4200 3650 40  0000 C CNN
F 2 "~" H 4150 3650 60  0000 C CNN
F 3 "~" H 4150 3650 60  0000 C CNN
	1    4150 3650
	-1   0    0    1   
$EndComp
Wire Wire Line
	4500 3550 5150 3550
Wire Wire Line
	5150 3550 5150 3300
Wire Wire Line
	5150 3300 5700 3300
Wire Wire Line
	4500 3750 5250 3750
Wire Wire Line
	5600 3400 5600 3500
Wire Wire Line
	5600 3500 5700 3500
Connection ~ 5600 3400
Wire Wire Line
	5250 3750 5250 3400
Connection ~ 5250 3400
Wire Wire Line
	5250 3400 5700 3400
$EndSCHEMATC
