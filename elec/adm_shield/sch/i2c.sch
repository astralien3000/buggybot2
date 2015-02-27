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
Sheet 5 5
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
L CONN_4 P?
U 1 1 54F08957
P 5400 3500
F 0 "P?" V 5350 3500 50  0000 C CNN
F 1 "CONN_4" V 5450 3500 50  0000 C CNN
F 2 "" H 5400 3500 60  0000 C CNN
F 3 "" H 5400 3500 60  0000 C CNN
	1    5400 3500
	1    0    0    -1  
$EndComp
Text HLabel 4350 3200 0    60   Input ~ 0
GND
Text HLabel 4350 3400 0    60   Input ~ 0
LOG_5V
Text HLabel 4350 3600 0    60   Input ~ 0
SCL
Text HLabel 4350 3800 0    60   Input ~ 0
SDA
Wire Wire Line
	4350 3200 5050 3200
Wire Wire Line
	5050 3200 5050 3350
Wire Wire Line
	4350 3400 4750 3400
Wire Wire Line
	4750 3400 4750 3450
Wire Wire Line
	4750 3450 5050 3450
Wire Wire Line
	4350 3600 4750 3600
Wire Wire Line
	4750 3600 4750 3550
Wire Wire Line
	4750 3550 5050 3550
Wire Wire Line
	4350 3800 5050 3800
Wire Wire Line
	5050 3800 5050 3650
$EndSCHEMATC
