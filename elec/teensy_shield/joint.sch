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
EELAYER 24 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 26
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 3550 3000 0    60   Input ~ 0
GND
Text HLabel 4100 4900 0    60   Input ~ 0
Vin_log
Text HLabel 4800 1900 0    60   Input ~ 0
Vin_pow
Text HLabel 4300 3550 0    60   Input ~ 0
PWM
Text HLabel 4800 3650 0    60   Input ~ 0
DIR
Text HLabel 4800 5000 0    60   Output ~ 0
ANGLE
Text HLabel 4800 4250 0    60   Output ~ 0
CURRENT
$Sheet
S 4800 2400 550  450 
U 55E63155
F0 "servo" 50
F1 "servo.sch" 50
F2 "Vin" I L 4800 2600 60 
F3 "GND" I L 4800 2500 60 
F4 "PWM" I L 4800 2700 60 
$EndSheet
$Sheet
S 4800 3950 700  550 
U 55E63158
F0 "current_sensor" 50
F1 "current_sensor.sch" 50
F2 "Vin" I L 4800 4150 60 
F3 "GND" I L 4800 4050 60 
F4 "OUT" I L 4800 4250 60 
F5 "nFAULT" I L 4800 4350 60 
F6 "IP+" I R 5500 4050 60 
F7 "IP-" I R 5500 4150 60 
$EndSheet
$Sheet
S 6350 3050 550  400 
U 55E6315B
F0 "motor" 50
F1 "motor.sch" 50
F2 "GND" I L 6350 3150 60 
F3 "M+" I L 6350 3350 60 
F4 "M-" I L 6350 3250 60 
$EndSheet
$Sheet
S 4800 4700 550  450 
U 55E6315E
F0 "angle_sensor" 50
F1 "angle_sensor.sch" 50
F2 "Vin" I L 4800 4900 60 
F3 "GND" I L 4800 4800 60 
F4 "OUT" I L 4800 5000 60 
$EndSheet
$Sheet
S 4800 1700 550  500 
U 55E63161
F0 "regulator" 50
F1 "regulator.sch" 50
F2 "GND" I L 4800 1800 60 
F3 "Vin" I L 4800 1900 60 
F4 "Vout" O L 4800 2000 60 
F5 "EN" I L 4800 2100 60 
$EndSheet
$Sheet
S 4800 3050 600  700 
U 55E6553A
F0 "motor_driver" 50
F1 "motor_driver.sch" 50
F2 "Vin" I L 4800 3250 60 
F3 "GND" I L 4800 3150 60 
F4 "M2" O R 5400 3250 60 
F5 "nEN" I L 4800 3350 60 
F6 "nFAULT" I L 4800 3450 60 
F7 "M1" O R 5400 3350 60 
F8 "DIR" I L 4800 3650 60 
F9 "PWM" I L 4800 3550 60 
$EndSheet
Wire Wire Line
	5400 3350 5700 3350
Wire Wire Line
	5700 3350 5700 4050
Wire Wire Line
	5700 4050 5500 4050
Wire Wire Line
	5500 4150 6250 4150
Wire Wire Line
	6250 4150 6250 3350
Wire Wire Line
	6250 3350 6350 3350
Wire Wire Line
	6350 3250 5400 3250
Text Label 4800 3250 2    60   ~ 0
Vmot
Text Label 4800 2000 2    60   ~ 0
Vmot
Text HLabel 4800 2100 0    60   Input ~ 0
EN
Wire Wire Line
	4300 3550 4400 3550
Wire Wire Line
	4400 3550 4800 3550
Wire Wire Line
	4800 2700 4400 2700
Wire Wire Line
	4400 2700 4400 3550
Connection ~ 4400 3550
Text Label 4800 2600 2    60   ~ 0
Vmot
Text Label 3550 3000 0    60   ~ 0
GND
Text Label 4800 1800 2    60   ~ 0
GND
Text Label 4800 2500 2    60   ~ 0
GND
Text Label 4800 3150 2    60   ~ 0
GND
Text Label 4800 4050 2    60   ~ 0
GND
Text Label 6350 3150 2    60   ~ 0
GND
Text Label 4800 4800 2    60   ~ 0
GND
Wire Wire Line
	4800 4900 4200 4900
Wire Wire Line
	4200 4900 4100 4900
Wire Wire Line
	4800 4150 4200 4150
Wire Wire Line
	4200 4150 4200 4900
Connection ~ 4200 4900
$EndSCHEMATC
