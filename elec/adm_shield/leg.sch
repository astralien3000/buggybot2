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
Sheet 2 24
Title ""
Date "28 feb 2015"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 3550 4000 800  650 
U 54F06B67
F0 "SERVO1" 50
F1 "servo.sch" 50
F2 "GND" I R 4350 4500 60 
F3 "PWM" I R 4350 4100 60 
F4 "POW_5V" I R 4350 4300 60 
$EndSheet
$Sheet
S 3550 2950 800  650 
U 54F06B67
F0 "SERVO2" 50
F1 "servo.sch" 50
F2 "GND" I R 4350 3450 60 
F3 "PWM" I R 4350 3050 60 
F4 "POW_5V" I R 4350 3250 60 
$EndSheet
$Sheet
S 3550 1850 800  650 
U 54F06B67
F0 "SERVO0" 50
F1 "servo.sch" 50
F2 "GND" I R 4350 2350 60 
F3 "PWM" I R 4350 1950 60 
F4 "POW_5V" I R 4350 2150 60 
$EndSheet
Text HLabel 6200 2850 2    60   Input ~ 0
PWM0
Text HLabel 6200 3050 2    60   Input ~ 0
PWM1
Text HLabel 6200 3250 2    60   Input ~ 0
PWM2
Text HLabel 4350 3450 2    60   Input ~ 0
GND
Text HLabel 4350 3250 2    60   Input ~ 0
POW_5V
Wire Wire Line
	5250 1950 5250 2850
Wire Wire Line
	5250 1950 4350 1950
Wire Wire Line
	6200 3250 5250 3250
Wire Wire Line
	5250 3250 5250 4100
Wire Wire Line
	5250 4100 4350 4100
Wire Wire Line
	5250 2850 6200 2850
Wire Wire Line
	6200 3050 4350 3050
Text HLabel 4350 4500 2    60   Input ~ 0
GND
Text HLabel 4350 4300 2    60   Input ~ 0
POW_5V
Text HLabel 4350 2350 2    60   Input ~ 0
GND
Text HLabel 4350 2150 2    60   Input ~ 0
POW_5V
$EndSCHEMATC
