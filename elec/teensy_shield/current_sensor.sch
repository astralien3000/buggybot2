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
Sheet 6 34
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 6500 3850 2    60   Input ~ 0
Vin
Text HLabel 6600 3950 2    60   Input ~ 0
GND
Text HLabel 6500 3750 2    60   Input ~ 0
OUT
Text HLabel 6500 3650 2    60   Input ~ 0
nFAULT
Text HLabel 5150 3750 0    60   Input ~ 0
IP+
Text HLabel 5150 3900 0    60   Input ~ 0
IP-
$Comp
L Pololu2197 U?
U 1 1 55E8283A
P 5800 3800
F 0 "U?" H 5800 3350 60  0000 C CNN
F 1 "Pololu2197" H 5800 3350 60  0000 C CNN
F 2 "" H 5800 3350 60  0000 C CNN
F 3 "" H 5800 3350 60  0000 C CNN
	1    5800 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 3950 6600 3950
Wire Wire Line
	6600 3950 6600 4050
Wire Wire Line
	6600 4050 6500 4050
$EndSCHEMATC
