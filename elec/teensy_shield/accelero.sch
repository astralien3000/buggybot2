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
Sheet 3 34
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 5300 3600 0    60   Input ~ 0
GND
Text HLabel 5300 4000 0    60   Input ~ 0
Vin
Text HLabel 5700 4100 0    60   Input ~ 0
SDA
Text HLabel 5700 4200 0    60   Input ~ 0
SCL
$Comp
L CONN_4 P1
U 1 1 55E8494D
P 6050 4050
F 0 "P1" V 6000 4050 50  0000 C CNN
F 1 "CONN_4" V 6100 4050 50  0000 C CNN
F 2 "" H 6050 4050 60  0000 C CNN
F 3 "" H 6050 4050 60  0000 C CNN
	1    6050 4050
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 55E734BE
P 5450 3800
F 0 "C1" H 5450 3900 40  0000 L CNN
F 1 "100nF" H 5456 3715 40  0000 L CNN
F 2 "" H 5488 3650 30  0000 C CNN
F 3 "" H 5450 3800 60  0000 C CNN
	1    5450 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 3600 5700 3600
Wire Wire Line
	5700 3600 5700 3900
Connection ~ 5450 3600
Wire Wire Line
	5300 4000 5700 4000
Connection ~ 5450 4000
Text HLabel 6750 3750 0    60   Input ~ 0
Vin
Text HLabel 7250 3750 2    60   Input ~ 0
SDA
Text HLabel 7250 3950 2    60   Input ~ 0
SCL
Text HLabel 6750 3950 0    60   Input ~ 0
Vin
$Comp
L R R1
U 1 1 55E734F8
P 7000 3750
F 0 "R1" V 7080 3750 40  0000 C CNN
F 1 "10k" V 7007 3751 40  0000 C CNN
F 2 "" V 6930 3750 30  0000 C CNN
F 3 "" H 7000 3750 30  0000 C CNN
	1    7000 3750
	0    1    1    0   
$EndComp
$Comp
L R R2
U 1 1 55E7350C
P 7000 3950
F 0 "R2" V 7080 3950 40  0000 C CNN
F 1 "10k" V 7007 3951 40  0000 C CNN
F 2 "" V 6930 3950 30  0000 C CNN
F 3 "" H 7000 3950 30  0000 C CNN
	1    7000 3950
	0    1    1    0   
$EndComp
$EndSCHEMATC
