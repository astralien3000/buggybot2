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
Sheet 5 34
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 4100 3100 0    60   Input ~ 0
Vin
Text HLabel 4100 2700 0    60   Input ~ 0
GND
Text HLabel 4900 3200 0    60   Input ~ 0
PWM
$Comp
L CONN_3 K7
U 1 1 55E819AD
P 5250 3100
AR Path="/55E6307C/55E63155/55E819AD" Ref="K7"  Part="1" 
AR Path="/55E7381B/55E63155/55E819AD" Ref="K1"  Part="1" 
AR Path="/55E7381C/55E63155/55E819AD" Ref="K3"  Part="1" 
AR Path="/55E7381D/55E63155/55E819AD" Ref="K5"  Part="1" 
F 0 "K7" V 5200 3100 50  0000 C CNN
F 1 "CONN_3" V 5300 3100 40  0000 C CNN
F 2 "" H 5250 3100 60  0000 C CNN
F 3 "" H 5250 3100 60  0000 C CNN
	1    5250 3100
	1    0    0    -1  
$EndComp
$Comp
L C C8
U 1 1 55E74194
P 4200 2900
AR Path="/55E6307C/55E63155/55E74194" Ref="C8"  Part="1" 
AR Path="/55E7381B/55E63155/55E74194" Ref="C2"  Part="1" 
AR Path="/55E7381C/55E63155/55E74194" Ref="C4"  Part="1" 
AR Path="/55E7381D/55E63155/55E74194" Ref="C6"  Part="1" 
F 0 "C8" H 4200 3000 40  0000 L CNN
F 1 "100nF" H 4206 2815 40  0000 L CNN
F 2 "" H 4238 2750 30  0000 C CNN
F 3 "" H 4200 2900 60  0000 C CNN
	1    4200 2900
	1    0    0    -1  
$EndComp
$Comp
L CP1 C9
U 1 1 55E741A8
P 4550 2900
AR Path="/55E6307C/55E63155/55E741A8" Ref="C9"  Part="1" 
AR Path="/55E7381B/55E63155/55E741A8" Ref="C3"  Part="1" 
AR Path="/55E7381C/55E63155/55E741A8" Ref="C5"  Part="1" 
AR Path="/55E7381D/55E63155/55E741A8" Ref="C7"  Part="1" 
F 0 "C9" H 4600 3000 50  0000 L CNN
F 1 "200uF" H 4600 2800 50  0000 L CNN
F 2 "" H 4550 2900 60  0000 C CNN
F 3 "" H 4550 2900 60  0000 C CNN
	1    4550 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 3100 4900 3100
Connection ~ 4200 3100
Connection ~ 4550 3100
Wire Wire Line
	4100 2700 4900 2700
Connection ~ 4200 2700
Wire Wire Line
	4900 2700 4900 3000
Connection ~ 4550 2700
$EndSCHEMATC
