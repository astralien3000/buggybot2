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
Sheet 2 17
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 5100 3500 0    60   Input ~ 0
GND
Text HLabel 5100 4050 0    60   Input ~ 0
GND
Text HLabel 5100 2950 0    60   Input ~ 0
GND
Text HLabel 5100 3400 0    60   Input ~ 0
TX1
Text HLabel 5100 3600 0    60   Output ~ 0
RX1
Text HLabel 5100 3950 0    60   Input ~ 0
TX2
Text HLabel 5100 4150 0    60   Output ~ 0
RX2
Text HLabel 5100 2850 0    60   Input ~ 0
SCL
Text HLabel 5100 3050 0    60   BiDi ~ 0
SDA
Text HLabel 5100 2300 0    60   Input ~ 0
+5V
$Comp
L R R1
U 1 1 5602B2EE
P 5200 2550
F 0 "R1" V 5280 2550 50  0000 C CNN
F 1 "10kΩ" V 5200 2550 50  0000 C CNN
F 2 "Footprints:R_CMS1206" V 5130 2550 30  0001 C CNN
F 3 "" H 5200 2550 30  0000 C CNN
	1    5200 2550
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 5602B4FB
P 5400 2550
F 0 "R2" V 5480 2550 50  0000 C CNN
F 1 "10kΩ" V 5400 2550 50  0000 C CNN
F 2 "Footprints:R_CMS1206" V 5330 2550 30  0001 C CNN
F 3 "" H 5400 2550 30  0000 C CNN
	1    5400 2550
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 5602B666
P 5600 2550
F 0 "R3" V 5680 2550 50  0000 C CNN
F 1 "10kΩ" V 5600 2550 50  0000 C CNN
F 2 "Footprints:R_CMS1206" V 5530 2550 30  0001 C CNN
F 3 "" H 5600 2550 30  0000 C CNN
	1    5600 2550
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 5602B66C
P 5800 2550
F 0 "R4" V 5880 2550 50  0000 C CNN
F 1 "10kΩ" V 5800 2550 50  0000 C CNN
F 2 "Footprints:R_CMS1206" V 5730 2550 30  0001 C CNN
F 3 "" H 5800 2550 30  0000 C CNN
	1    5800 2550
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 5602BC08
P 6000 2550
F 0 "R5" V 6080 2550 50  0000 C CNN
F 1 "10kΩ" V 6000 2550 50  0000 C CNN
F 2 "Footprints:R_CMS1206" V 5930 2550 30  0001 C CNN
F 3 "" H 6000 2550 30  0000 C CNN
	1    6000 2550
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 5602BC0E
P 6200 2550
F 0 "R6" V 6280 2550 50  0000 C CNN
F 1 "10kΩ" V 6200 2550 50  0000 C CNN
F 2 "Footprints:R_CMS1206" V 6130 2550 30  0001 C CNN
F 3 "" H 6200 2550 30  0000 C CNN
	1    6200 2550
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 P2
U 1 1 56E72478
P 8150 3550
F 0 "P2" H 8150 3800 50  0000 C CNN
F 1 "UART_1" V 8250 3550 50  0000 C CNN
F 2 "Footprints:Conn_01x04" H 8150 3550 60  0001 C CNN
F 3 "" H 8150 3550 60  0000 C CNN
	1    8150 3550
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 P3
U 1 1 56E725F7
P 8150 4100
F 0 "P3" H 8150 4350 50  0000 C CNN
F 1 "UART_2" V 8250 4100 50  0000 C CNN
F 2 "Footprints:Conn_01x04" H 8150 4100 60  0001 C CNN
F 3 "" H 8150 4100 60  0000 C CNN
	1    8150 4100
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 P4
U 1 1 56E7268A
P 8150 4600
F 0 "P4" H 8150 4800 50  0000 C CNN
F 1 "UART_3" V 8250 4600 50  0000 C CNN
F 2 "Footprints:Conn_01x03" H 8150 4600 60  0001 C CNN
F 3 "" H 8150 4600 60  0000 C CNN
	1    8150 4600
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X04 P1
U 1 1 56E726F0
P 8150 3000
F 0 "P1" H 8150 3250 50  0000 C CNN
F 1 "I2C_1" V 8250 3000 50  0000 C CNN
F 2 "Footprints:Conn_01x04" H 8150 3000 60  0001 C CNN
F 3 "" H 8150 3000 60  0000 C CNN
	1    8150 3000
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 56E72AA3
P 6400 2550
F 0 "R7" V 6480 2550 50  0000 C CNN
F 1 "10kΩ" V 6400 2550 50  0000 C CNN
F 2 "Footprints:R_CMS1206" V 6330 2550 30  0001 C CNN
F 3 "" H 6400 2550 30  0000 C CNN
	1    6400 2550
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 56E72AA9
P 6600 2550
F 0 "R8" V 6680 2550 50  0000 C CNN
F 1 "10kΩ" V 6600 2550 50  0000 C CNN
F 2 "Footprints:R_CMS1206" V 6530 2550 30  0001 C CNN
F 3 "" H 6600 2550 30  0000 C CNN
	1    6600 2550
	1    0    0    -1  
$EndComp
Text HLabel 5100 4600 0    60   Input ~ 0
GND
Text HLabel 5100 4500 0    60   Input ~ 0
TX3
Text HLabel 5100 4700 0    60   Output ~ 0
RX3
Text HLabel 5100 5050 0    60   Input ~ 0
+7.5V
$Comp
L C C3
U 1 1 5709C09B
P 7750 3250
F 0 "C3" V 8002 3250 50  0000 C CNN
F 1 "10µF" V 7911 3250 50  0000 C CNN
F 2 "Footprints:C_CMS1210" H 7788 3100 50  0001 C CNN
F 3 "" H 7750 3250 50  0000 C CNN
	1    7750 3250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5100 2300 6800 2300
Wire Wire Line
	5200 2300 5200 2400
Wire Wire Line
	5400 2300 5400 2400
Connection ~ 5200 2300
Wire Wire Line
	5800 2300 5800 2400
Connection ~ 5400 2300
Wire Wire Line
	5600 2400 5600 2300
Connection ~ 5600 2300
Wire Wire Line
	6000 2300 6000 2400
Connection ~ 5800 2300
Wire Wire Line
	6200 2300 6200 2400
Connection ~ 6000 2300
Wire Wire Line
	6400 2300 6400 2400
Connection ~ 6200 2300
Connection ~ 6400 2300
Wire Wire Line
	6600 2300 6600 2400
Wire Wire Line
	5100 4700 7950 4700
Wire Wire Line
	5100 4600 7950 4600
Wire Wire Line
	5100 4500 7950 4500
Wire Wire Line
	6600 2700 6600 4700
Connection ~ 6600 4700
Wire Wire Line
	6400 2700 6400 4500
Connection ~ 6400 4500
Wire Wire Line
	5100 4150 7950 4150
Wire Wire Line
	5100 4050 7950 4050
Wire Wire Line
	5100 3950 7950 3950
Wire Wire Line
	5100 3600 7950 3600
Wire Wire Line
	5100 3500 7950 3500
Wire Wire Line
	5100 3400 7950 3400
Wire Wire Line
	5100 2850 7950 2850
Wire Wire Line
	5100 3050 7950 3050
Wire Wire Line
	5100 2950 7950 2950
Wire Wire Line
	5100 5050 6800 5050
Wire Wire Line
	6800 5050 6800 3700
Wire Wire Line
	6800 3700 7950 3700
Wire Wire Line
	6800 4250 7950 4250
Connection ~ 6800 4250
Wire Wire Line
	6800 3150 7950 3150
Wire Wire Line
	6800 2300 6800 3150
Connection ~ 6600 2300
Wire Wire Line
	6200 2700 6200 4150
Connection ~ 6200 4150
Wire Wire Line
	6000 2700 6000 3950
Connection ~ 6000 3950
Wire Wire Line
	5800 2700 5800 3600
Connection ~ 5800 3600
Wire Wire Line
	5600 2700 5600 3400
Connection ~ 5600 3400
Wire Wire Line
	5400 2700 5400 3050
Connection ~ 5400 3050
Wire Wire Line
	5200 2700 5200 2850
Connection ~ 5200 2850
Wire Wire Line
	7900 3250 7900 3150
Connection ~ 7900 3150
Wire Wire Line
	7600 3250 7600 2950
Connection ~ 7600 2950
$Comp
L C C4
U 1 1 5709C9E3
P 7750 3800
F 0 "C4" V 8002 3800 50  0000 C CNN
F 1 "10µF" V 7911 3800 50  0000 C CNN
F 2 "Footprints:C_CMS1210" H 7788 3650 50  0001 C CNN
F 3 "" H 7750 3800 50  0000 C CNN
	1    7750 3800
	0    -1   -1   0   
$EndComp
$Comp
L C C5
U 1 1 5709CA2B
P 7750 4350
F 0 "C5" V 8002 4350 50  0000 C CNN
F 1 "10µF" V 7911 4350 50  0000 C CNN
F 2 "Footprints:C_CMS1210" H 7788 4200 50  0001 C CNN
F 3 "" H 7750 4350 50  0000 C CNN
	1    7750 4350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7900 3800 7900 3700
Connection ~ 7900 3700
Wire Wire Line
	7600 3800 7600 3500
Connection ~ 7600 3500
Wire Wire Line
	7900 4350 7900 4250
Connection ~ 7900 4250
Wire Wire Line
	7600 4350 7600 4050
Connection ~ 7600 4050
$Comp
L CP1 C1
U 1 1 5709CC52
P 7350 3800
F 0 "C1" V 7098 3800 50  0000 C CNN
F 1 "330µF" V 7189 3800 50  0000 C CNN
F 2 "Footprints:C_Radial" H 7350 3800 50  0001 C CNN
F 3 "" H 7350 3800 50  0000 C CNN
	1    7350 3800
	0    1    1    0   
$EndComp
Wire Wire Line
	7500 3800 7500 3700
Connection ~ 7500 3700
Wire Wire Line
	7200 3800 7200 3500
Connection ~ 7200 3500
$Comp
L CP1 C2
U 1 1 5707DB6F
P 7350 4350
F 0 "C2" V 7098 4350 50  0000 C CNN
F 1 "330µF" V 7189 4350 50  0000 C CNN
F 2 "Footprints:C_Radial" H 7350 4350 50  0001 C CNN
F 3 "" H 7350 4350 50  0000 C CNN
	1    7350 4350
	0    1    1    0   
$EndComp
Wire Wire Line
	7500 4350 7500 4250
Connection ~ 7500 4250
Wire Wire Line
	7200 4350 7200 4050
Connection ~ 7200 4050
$EndSCHEMATC
