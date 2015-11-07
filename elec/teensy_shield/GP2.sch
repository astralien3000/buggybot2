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
LIBS:teensy
LIBS:pololu
LIBS:teensy_shield-cache
EELAYER 24 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 34 34
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 4700 2800 0    60   Input ~ 0
GND
Text HLabel 4700 3200 0    60   Input ~ 0
Vin
Text HLabel 5250 3300 0    60   Input ~ 0
OUT
$Comp
L CONN_3 K9
U 1 1 55E84D77
P 5600 3200
F 0 "K9" V 5550 3200 50  0000 C CNN
F 1 "CONN_3" V 5650 3200 40  0000 C CNN
F 2 "" H 5600 3200 60  0000 C CNN
F 3 "" H 5600 3200 60  0000 C CNN
	1    5600 3200
	1    0    0    -1  
$EndComp
$Comp
L C C10
U 1 1 55E73165
P 4850 3000
F 0 "C10" H 4850 3100 40  0000 L CNN
F 1 "10uF" H 4856 2915 40  0000 L CNN
F 2 "" H 4888 2850 30  0000 C CNN
F 3 "" H 4850 3000 60  0000 C CNN
	1    4850 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 3200 5250 3200
Connection ~ 4850 3200
Wire Wire Line
	4700 2800 5250 2800
Wire Wire Line
	5250 2800 5250 3100
Connection ~ 4850 2800
$EndSCHEMATC
