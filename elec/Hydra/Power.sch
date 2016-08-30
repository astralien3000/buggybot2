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
LIBS:embed-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 16 17
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_01X02 P19
U 1 1 55E7E300
P 5350 4550
F 0 "P19" H 5350 4700 50  0000 C CNN
F 1 "Bat5V" V 5450 4550 50  0000 C CNN
F 2 "Footprints:Conn_01x02" H 5350 4550 60  0001 C CNN
F 3 "" H 5350 4550 60  0000 C CNN
	1    5350 4550
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X02 P18
U 1 1 55E7E313
P 4250 3250
F 0 "P18" H 4250 3400 50  0000 C CNN
F 1 "Bat7.5V" V 4350 3250 50  0000 C CNN
F 2 "Footprints:Power_Conn_01x02" H 4250 3250 60  0001 C CNN
F 3 "" H 4250 3250 60  0000 C CNN
	1    4250 3250
	-1   0    0    1   
$EndComp
Text HLabel 6700 4500 2    60   Output ~ 0
+5Vlog
Text HLabel 6700 4750 2    60   Output ~ 0
GND
Text HLabel 6700 3200 2    60   Output ~ 0
+7.5V
$Comp
L FUSE F1
U 1 1 560397C6
P 4800 3200
F 0 "F1" H 4900 3250 50  0000 C CNN
F 1 "FUSE 20A" H 4700 3150 50  0000 C CNN
F 2 "Footprints:Fuse" H 4800 3200 60  0001 C CNN
F 3 "" H 4800 3200 60  0000 C CNN
	1    4800 3200
	-1   0    0    1   
$EndComp
Text HLabel 5550 4250 0    60   Input ~ 0
+5VADM
$Comp
L CONN_01X04 P20
U 1 1 56ECA836
P 6000 3700
F 0 "P20" V 5965 3456 50  0000 R CNN
F 1 "Jumper5V" V 5874 3456 50  0000 R CNN
F 2 "Footprints:3-state_jumper" H 6000 3700 50  0001 C CNN
F 3 "" H 6000 3700 50  0000 C CNN
	1    6000 3700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6150 3900 6150 4500
Wire Wire Line
	5550 4500 6050 4500
Wire Wire Line
	6050 4500 6050 3900
Wire Wire Line
	5550 4250 5950 4250
Wire Wire Line
	5950 4250 5950 3900
Wire Wire Line
	4450 3200 4550 3200
Wire Wire Line
	6150 4500 6700 4500
Wire Wire Line
	5050 3200 6700 3200
Text HLabel 3550 4250 0    60   Input ~ 0
RegulEnable
$Comp
L CONN_01X05 Regul1
U 1 1 56ECAF1B
P 5350 3700
F 0 "Regul1" H 5428 3738 50  0000 L CNN
F 1 "Regul" H 5428 3647 50  0000 L CNN
F 2 "Footprints:Pololu_D24V50F5" H 5350 3700 50  0001 C CNN
F 3 "" H 5350 3700 50  0000 C CNN
	1    5350 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 3200 5100 3600
Connection ~ 5100 3200
Wire Wire Line
	4250 3600 5150 3600
Wire Wire Line
	5150 3900 5150 4000
Wire Wire Line
	5150 4000 6700 4000
Wire Wire Line
	5850 4000 5850 3900
Wire Wire Line
	5000 3750 5100 3750
Wire Wire Line
	5100 3700 5100 3800
Wire Wire Line
	5100 3700 5150 3700
Wire Wire Line
	5100 3800 5150 3800
Connection ~ 5100 3750
Connection ~ 5850 4000
Text HLabel 6700 4000 2    60   Output ~ 0
+5Vpower
$Comp
L Q_NPN_BEC Q1
U 1 1 57129C12
P 4150 4250
F 0 "Q1" H 4450 4300 50  0000 R CNN
F 1 "Q_NPN_BEC" H 4750 4200 50  0000 R CNN
F 2 "Footprints:SOT-23-3-bipolar-transistor" H 4350 4350 29  0001 C CNN
F 3 "" H 4150 4250 60  0000 C CNN
	1    4150 4250
	1    0    0    -1  
$EndComp
$Comp
L R R23
U 1 1 57129E28
P 3600 4400
F 0 "R23" V 3680 4400 50  0000 C CNN
F 1 "10kΩ" V 3600 4400 50  0000 C CNN
F 2 "Footprints:R_CMS1206" V 3530 4400 30  0001 C CNN
F 3 "" H 3600 4400 30  0000 C CNN
	1    3600 4400
	1    0    0    -1  
$EndComp
$Comp
L R R24
U 1 1 57129FB7
P 3800 4250
F 0 "R24" V 3880 4250 50  0000 C CNN
F 1 "1kΩ" V 3800 4250 50  0000 C CNN
F 2 "Footprints:R_CMS1206" V 3730 4250 30  0001 C CNN
F 3 "" H 3800 4250 30  0000 C CNN
	1    3800 4250
	0    -1   -1   0   
$EndComp
$Comp
L R R25
U 1 1 5712A078
P 4250 3800
F 0 "R25" V 4330 3800 50  0000 C CNN
F 1 "1kΩ" V 4250 3800 50  0000 C CNN
F 2 "Footprints:R_CMS1206" V 4180 3800 30  0001 C CNN
F 3 "" H 4250 3800 30  0000 C CNN
	1    4250 3800
	-1   0    0    1   
$EndComp
$Comp
L Q_NPN_BEC Q2
U 1 1 5712A0B1
P 4500 4000
F 0 "Q2" H 4800 4050 50  0000 R CNN
F 1 "Q_NPN_BEC" H 5100 3950 50  0000 R CNN
F 2 "Footprints:SOT-23-3-bipolar-transistor" H 4700 4100 29  0001 C CNN
F 3 "" H 4500 4000 60  0000 C CNN
	1    4500 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 3950 4250 4050
Wire Wire Line
	4300 4000 4250 4000
Connection ~ 4250 4000
Wire Wire Line
	4250 4450 4250 4750
Wire Wire Line
	3600 4750 6700 4750
Wire Wire Line
	4600 4200 4600 4750
Connection ~ 4600 4750
Connection ~ 4250 4750
Wire Wire Line
	4600 3800 4600 3500
Wire Wire Line
	4600 3500 5150 3500
Wire Wire Line
	4250 3650 4250 3600
Connection ~ 5100 3600
Wire Wire Line
	3550 4250 3650 4250
Connection ~ 3600 4250
Wire Wire Line
	3600 4550 3600 4750
Wire Wire Line
	4450 3300 5000 3300
Wire Wire Line
	5000 3300 5000 4750
Connection ~ 5000 4750
Connection ~ 5000 3750
Wire Wire Line
	5550 4600 5550 4750
Connection ~ 5550 4750
$EndSCHEMATC
