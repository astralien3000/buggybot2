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
Sheet 19 24
Title ""
Date "28 feb 2015"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ARDUINO_MEGA_SHIELD SHIELD1
U 1 1 54F159EE
P 5550 3650
F 0 "SHIELD1" H 5150 6150 60  0000 C CNN
F 1 "ARDUINO_MEGA_SHIELD" H 5450 950 60  0000 C CNN
F 2 "" H 5550 3650 60  0000 C CNN
F 3 "" H 5550 3650 60  0000 C CNN
	1    5550 3650
	1    0    0    -1  
$EndComp
Text HLabel 6450 1700 2    60   Input ~ 0
PWM_LF0
Text HLabel 6450 1600 2    60   Input ~ 0
PWM_LF1
Text HLabel 6450 1500 2    60   Input ~ 0
PWM_LF2
Text HLabel 6450 2400 2    60   Input ~ 0
PWM_RF0
Text HLabel 6450 2700 2    60   Input ~ 0
PWM_RF1
Text HLabel 6450 2600 2    60   Input ~ 0
PWM_RF2
Text HLabel 6450 2300 2    60   Input ~ 0
PWM_RB0
Text HLabel 6450 2200 2    60   Input ~ 0
PWM_RB1
Text HLabel 6450 2000 2    60   Input ~ 0
PWM_RB2
Text HLabel 4500 5250 0    60   Input ~ 0
PWM_LB0
Text HLabel 4550 5350 0    60   Input ~ 0
PWM_LB1
Text HLabel 4500 5450 0    60   Input ~ 0
PWM_LB2
Text HLabel 4550 1900 0    60   Input ~ 0
LOG_5V
Text HLabel 6450 4050 2    60   Input ~ 0
LOG_5V
Text HLabel 6450 4150 2    60   Input ~ 0
LOG_5V
Text HLabel 4550 2000 0    60   Input ~ 0
GND
Text HLabel 4550 2100 0    60   Input ~ 0
GND
Text HLabel 6450 1400 2    60   Input ~ 0
GND
Text HLabel 4550 4250 0    60   Input ~ 0
GND
Text HLabel 4550 4350 0    60   Input ~ 0
GND
Text HLabel 6450 3800 2    60   Input ~ 0
SCL
Text HLabel 6450 3700 2    60   Input ~ 0
SDA
Text HLabel 4550 3300 0    60   Input ~ 0
GP2_LF
Text HLabel 4550 3400 0    60   Input ~ 0
GP2_RF
Text HLabel 4550 3500 0    60   Input ~ 0
GP2_RB
Text HLabel 4550 3600 0    60   Input ~ 0
GP2_LB
Text HLabel 6450 3600 2    60   Input ~ 0
RX
Text HLabel 6450 3500 2    60   Input ~ 0
TX
Text HLabel 4550 4500 0    60   Input ~ 0
SS
Text HLabel 4550 4600 0    60   Input ~ 0
SCK
Text HLabel 4550 4700 0    60   Input ~ 0
MOSI
Text HLabel 4550 4800 0    60   Input ~ 0
MISO
Text HLabel 6450 5850 2    60   Input ~ 0
SS1
Text HLabel 6450 5750 2    60   Input ~ 0
SS2
Text HLabel 6450 5650 2    60   Input ~ 0
SS3
Text HLabel 6450 5550 2    60   Input ~ 0
SS4
Text HLabel 4550 3700 0    60   Input ~ 0
SENS_0
Text HLabel 4550 3800 0    60   Input ~ 0
SENS_1
Text HLabel 4550 3900 0    60   Input ~ 0
SENS_2
Text HLabel 4550 4000 0    60   Input ~ 0
SENS_3
Wire Wire Line
	4550 5250 4500 5250
Wire Wire Line
	4550 5150 4500 5150
Wire Wire Line
	4500 5150 4500 5250
Wire Wire Line
	4550 5450 4500 5450
Wire Wire Line
	4550 5550 4500 5550
Wire Wire Line
	4500 5550 4500 5450
$EndSCHEMATC
