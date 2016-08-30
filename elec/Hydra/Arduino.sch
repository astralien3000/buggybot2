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
Sheet 17 17
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
L ARDUINO_MEGA_SHIELD SHIELD1
U 1 1 5707BD75
P 5700 3750
F 0 "SHIELD1" H 5675 5187 60  0000 C CNN
F 1 "ARDUINO_MEGA_SHIELD" H 5675 5081 60  0000 C CNN
F 2 "Footprints:ARDUINO_MEGA_SHIELD" H 5700 2200 50  0001 C CNN
F 3 "" H 5700 2400 60  0000 C CNN
	1    5700 3750
	1    0    0    -1  
$EndComp
Text HLabel 6600 4000 2    60   Output ~ 0
RegulEnable
Text HLabel 4750 3500 0    60   Input ~ 0
GP2_0
Text HLabel 4750 3600 0    60   Input ~ 0
GP2_1
Text HLabel 4750 3700 0    60   Input ~ 0
GP2_2
Text HLabel 4750 3800 0    60   Input ~ 0
GP2_3
Text HLabel 4750 4100 0    60   Input ~ 0
Input0
Text HLabel 4750 4200 0    60   Input ~ 0
Input1
Text HLabel 4750 4400 0    60   Input ~ 0
Input2
Text HLabel 4750 4500 0    60   Input ~ 0
Input3
Text HLabel 4750 4600 0    60   Input ~ 0
Input4
Text HLabel 2350 3100 0    60   Input ~ 0
GND
$Comp
L R R26
U 1 1 5707C05E
P 2900 4400
F 0 "R26" H 2950 4400 50  0000 L CNN
F 1 "200Ω" V 2900 4300 50  0000 L CNN
F 2 "Footprints:R_CMS1206" V 2830 4400 50  0001 C CNN
F 3 "" H 2900 4400 50  0000 C CNN
	1    2900 4400
	1    0    0    -1  
$EndComp
$Comp
L LED D1
U 1 1 5707C0E3
P 2900 4050
F 0 "D1" V 2854 4128 50  0000 L CNN
F 1 "LED" V 2945 4128 50  0000 L CNN
F 2 "Footprints:LED_Green_CMS" V 2991 4128 50  0001 L CNN
F 3 "" H 2900 4050 50  0000 C CNN
	1    2900 4050
	0    1    1    0   
$EndComp
Text HLabel 6600 5000 2    60   BiDi ~ 0
SDA
Text HLabel 6600 5100 2    60   Output ~ 0
SCL
Text HLabel 6600 4900 2    60   Input ~ 0
RX1
Text HLabel 6600 4800 2    60   Output ~ 0
TX1
Text HLabel 6600 4700 2    60   Input ~ 0
RX2
Text HLabel 6600 4600 2    60   Output ~ 0
TX2
Text HLabel 6600 4500 2    60   Input ~ 0
RX3
Text HLabel 6600 4400 2    60   Output ~ 0
TX3
Text HLabel 6600 3700 2    60   Output ~ 0
PWM0
Text HLabel 6600 3600 2    60   Output ~ 0
PWM1
Text HLabel 6600 3500 2    60   Output ~ 0
PWM2
Text HLabel 6600 3300 2    60   Output ~ 0
PWM3
$Comp
L LED D2
U 1 1 5709AC30
P 3200 4050
F 0 "D2" V 3154 4128 50  0000 L CNN
F 1 "LED" V 3245 4128 50  0000 L CNN
F 2 "Footprints:LED_Green_CMS" V 3291 4128 50  0001 L CNN
F 3 "" H 3200 4050 50  0000 C CNN
	1    3200 4050
	0    1    1    0   
$EndComp
$Comp
L LED D3
U 1 1 5709AC5C
P 3500 4050
F 0 "D3" V 3454 4128 50  0000 L CNN
F 1 "LED" V 3545 4128 50  0000 L CNN
F 2 "Footprints:LED_Green_CMS" V 3591 4128 50  0001 L CNN
F 3 "" H 3500 4050 50  0000 C CNN
	1    3500 4050
	0    1    1    0   
$EndComp
$Comp
L LED D4
U 1 1 5709AC8B
P 3800 4050
F 0 "D4" V 3754 4128 50  0000 L CNN
F 1 "LED" V 3845 4128 50  0000 L CNN
F 2 "Footprints:LED_Green_CMS" V 3891 4128 50  0001 L CNN
F 3 "" H 3800 4050 50  0000 C CNN
	1    3800 4050
	0    1    1    0   
$EndComp
$Comp
L LED D5
U 1 1 5709ACBB
P 4100 4050
F 0 "D5" V 4054 4128 50  0000 L CNN
F 1 "LED" V 4145 4128 50  0000 L CNN
F 2 "Footprints:LED_Green_CMS" V 4191 4128 50  0001 L CNN
F 3 "" H 4100 4050 50  0000 C CNN
	1    4100 4050
	0    1    1    0   
$EndComp
$Comp
L R R27
U 1 1 5709B191
P 3200 4400
F 0 "R27" H 3250 4400 50  0000 L CNN
F 1 "200Ω" V 3200 4300 50  0000 L CNN
F 2 "Footprints:R_CMS1206" V 3130 4400 50  0001 C CNN
F 3 "" H 3200 4400 50  0000 C CNN
	1    3200 4400
	1    0    0    -1  
$EndComp
$Comp
L R R28
U 1 1 5709B1BF
P 3500 4400
F 0 "R28" H 3550 4400 50  0000 L CNN
F 1 "200Ω" V 3500 4300 50  0000 L CNN
F 2 "Footprints:R_CMS1206" V 3430 4400 50  0001 C CNN
F 3 "" H 3500 4400 50  0000 C CNN
	1    3500 4400
	1    0    0    -1  
$EndComp
$Comp
L R R29
U 1 1 5709B1F7
P 3800 4400
F 0 "R29" H 3850 4400 50  0000 L CNN
F 1 "200Ω" V 3800 4300 50  0000 L CNN
F 2 "Footprints:R_CMS1206" V 3730 4400 50  0001 C CNN
F 3 "" H 3800 4400 50  0000 C CNN
	1    3800 4400
	1    0    0    -1  
$EndComp
$Comp
L R R30
U 1 1 5709B23B
P 4100 4400
F 0 "R30" H 4150 4400 50  0000 L CNN
F 1 "200Ω" V 4100 4300 50  0000 L CNN
F 2 "Footprints:R_CMS1206" V 4030 4400 50  0001 C CNN
F 3 "" H 4100 4400 50  0000 C CNN
	1    4100 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 3000 4400 3000
Connection ~ 3800 3600
Wire Wire Line
	4100 3600 4100 3850
Wire Wire Line
	3800 3600 3800 3850
Connection ~ 3200 3600
Wire Wire Line
	2900 3850 2900 3600
Connection ~ 3500 3600
Wire Wire Line
	2900 3600 4100 3600
Wire Wire Line
	3200 3850 3200 3600
Connection ~ 3500 3100
Wire Wire Line
	3500 3850 3500 3100
Wire Wire Line
	2900 5100 2900 4550
Wire Wire Line
	4750 5100 2900 5100
Wire Wire Line
	3200 5000 3200 4550
Wire Wire Line
	4750 5000 3200 5000
Wire Wire Line
	3500 4900 3500 4550
Wire Wire Line
	4750 4900 3500 4900
Wire Wire Line
	3800 4800 3800 4550
Wire Wire Line
	4750 4800 3800 4800
Wire Wire Line
	4100 4700 4100 4550
Wire Wire Line
	4750 4700 4100 4700
Connection ~ 4600 3100
Wire Wire Line
	6700 2700 6600 2700
Wire Wire Line
	6700 2200 6700 2700
Wire Wire Line
	4600 2200 6700 2200
Wire Wire Line
	4600 3100 4600 2200
Wire Wire Line
	4750 3100 4750 3200
Wire Wire Line
	2350 3100 4750 3100
Text HLabel 4400 3000 0    60   Output ~ 0
+5VADM
$EndSCHEMATC
