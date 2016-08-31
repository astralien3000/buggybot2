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
Sheet 7 17
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
L CONN_01X03 P12
U 1 1 56E7A724
P 5550 3750
AR Path="/56E7FE3F/56E7A724" Ref="P12"  Part="1" 
AR Path="/56E7A6CD/56E7A724" Ref="P9"  Part="1" 
AR Path="/56E7FB11/56E7A724" Ref="P10"  Part="1" 
AR Path="/56E7FE3A/56E7A724" Ref="P11"  Part="1" 
F 0 "P9" H 5550 3950 50  0000 C CNN
F 1 "Servo" V 5650 3750 50  0000 C CNN
F 2 "Footprints:Conn_01x03" H 5550 3750 60  0001 C CNN
F 3 "" H 5550 3750 60  0000 C CNN
	1    5550 3750
	-1   0    0    1   
$EndComp
Text HLabel 6550 3750 2    60   Input ~ 0
GND
Text HLabel 6550 3850 2    60   Input ~ 0
+5V
Text HLabel 6550 3650 2    60   Input ~ 0
PWM
$Comp
L C C17
U 1 1 56E7A7BA
P 6150 4050
AR Path="/56E7FE3F/56E7A7BA" Ref="C17"  Part="1" 
AR Path="/56E7A6CD/56E7A7BA" Ref="C14"  Part="1" 
AR Path="/56E7FB11/56E7A7BA" Ref="C15"  Part="1" 
AR Path="/56E7FE3A/56E7A7BA" Ref="C16"  Part="1" 
F 0 "C14" H 6175 4150 50  0000 L CNN
F 1 "10µF" H 6175 3950 50  0000 L CNN
F 2 "Footprints:C_CMS1210" H 6188 3900 30  0001 C CNN
F 3 "" H 6150 4050 60  0000 C CNN
	1    6150 4050
	0    1    1    0   
$EndComp
$Comp
L R R12
U 1 1 570C507F
P 6150 3450
AR Path="/56E7FE3F/570C507F" Ref="R12"  Part="1" 
AR Path="/56E7A6CD/570C507F" Ref="R9"  Part="1" 
AR Path="/56E7FB11/570C507F" Ref="R10"  Part="1" 
AR Path="/56E7FE3A/570C507F" Ref="R11"  Part="1" 
F 0 "R9" V 6230 3450 50  0000 C CNN
F 1 "10kΩ" V 6150 3450 50  0000 C CNN
F 2 "Footprints:R_CMS1206" V 6080 3450 30  0001 C CNN
F 3 "" H 6150 3450 30  0000 C CNN
	1    6150 3450
	0    1    1    0   
$EndComp
Wire Wire Line
	5750 3850 6550 3850
Wire Wire Line
	6550 3750 5750 3750
Wire Wire Line
	5750 3650 6550 3650
Wire Wire Line
	6300 4050 6300 3850
Connection ~ 6300 3850
Wire Wire Line
	6000 3450 6000 4050
Connection ~ 6000 3750
Wire Wire Line
	6300 3650 6300 3450
Connection ~ 6300 3650
$EndSCHEMATC
