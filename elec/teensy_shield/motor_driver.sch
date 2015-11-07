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
Sheet 24 34
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 6450 3250 2    60   Input ~ 0
Vin
Text HLabel 5250 3350 0    60   Input ~ 0
GND
Text HLabel 6450 3050 2    60   Output ~ 0
M1
Text HLabel 6450 3150 2    60   Output ~ 0
M2
Text HLabel 5250 3050 0    60   Input ~ 0
DIR
Text HLabel 5250 2950 0    60   Input ~ 0
PWM
$Comp
L Pololu2961 U13
U 1 1 55E82F97
P 5850 3150
AR Path="/55E6307C/55E6553A/55E82F97" Ref="U13"  Part="1" 
AR Path="/55E7381B/55E6553A/55E82F97" Ref="U4"  Part="1" 
AR Path="/55E7381C/55E6553A/55E82F97" Ref="U7"  Part="1" 
AR Path="/55E7381D/55E6553A/55E82F97" Ref="U10"  Part="1" 
F 0 "U10" H 5850 2800 60  0000 C CNN
F 1 "Pololu2961" H 5850 2800 60  0000 C CNN
F 2 "" H 5850 2800 60  0000 C CNN
F 3 "" H 5850 2800 60  0000 C CNN
	1    5850 3150
	1    0    0    -1  
$EndComp
Text HLabel 6450 3350 2    60   Input ~ 0
GND
$EndSCHEMATC
