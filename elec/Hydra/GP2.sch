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
Sheet 3 17
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
L CONN_01X03 P1
U 1 1 55E7C054
P 4900 3750
AR Path="/55E75835/55E7C054" Ref="P1"  Part="1" 
AR Path="/55E760A5/55E7C054" Ref="P2"  Part="1" 
AR Path="/55E7647A/55E7C054" Ref="P3"  Part="1" 
AR Path="/55E7647F/55E7C054" Ref="P4"  Part="1" 
AR Path="/56E73C19/55E7C054" Ref="P5"  Part="1" 
AR Path="/56E74A24/55E7C054" Ref="P7"  Part="1" 
AR Path="/56E74A29/55E7C054" Ref="P8"  Part="1" 
AR Path="/56E745E7/55E7C054" Ref="P6"  Part="1" 
F 0 "P5" H 4900 3950 50  0000 C CNN
F 1 "GP2" V 5000 3750 50  0000 C CNN
F 2 "Footprints:Conn_01x03" H 4900 3750 60  0001 C CNN
F 3 "" H 4900 3750 60  0000 C CNN
	1    4900 3750
	-1   0    0    1   
$EndComp
$Comp
L C C1
U 1 1 55E7C068
P 5250 3450
AR Path="/55E75835/55E7C068" Ref="C1"  Part="1" 
AR Path="/55E760A5/55E7C068" Ref="C3"  Part="1" 
AR Path="/55E7647A/55E7C068" Ref="C5"  Part="1" 
AR Path="/55E7647F/55E7C068" Ref="C7"  Part="1" 
AR Path="/56E73C19/55E7C068" Ref="C6"  Part="1" 
AR Path="/56E74A24/55E7C068" Ref="C10"  Part="1" 
AR Path="/56E74A29/55E7C068" Ref="C12"  Part="1" 
AR Path="/56E745E7/55E7C068" Ref="C8"  Part="1" 
F 0 "C6" H 5275 3550 50  0000 L CNN
F 1 "10µF" H 5275 3350 50  0000 L CNN
F 2 "Footprints:C_CMS1210" H 5288 3300 30  0001 C CNN
F 3 "" H 5250 3450 60  0000 C CNN
	1    5250 3450
	0    1    1    0   
$EndComp
Text HLabel 5100 3300 1    60   Input ~ 0
+5V
Text HLabel 5400 3300 1    60   Input ~ 0
GND
Text HLabel 5650 3900 3    60   Output ~ 0
Signal
$Comp
L C C2
U 1 1 5602AA98
P 5650 3650
AR Path="/55E75835/5602AA98" Ref="C2"  Part="1" 
AR Path="/55E760A5/5602AA98" Ref="C4"  Part="1" 
AR Path="/55E7647A/5602AA98" Ref="C6"  Part="1" 
AR Path="/55E7647F/5602AA98" Ref="C8"  Part="1" 
AR Path="/56E73C19/5602AA98" Ref="C7"  Part="1" 
AR Path="/56E74A24/5602AA98" Ref="C11"  Part="1" 
AR Path="/56E74A29/5602AA98" Ref="C13"  Part="1" 
AR Path="/56E745E7/5602AA98" Ref="C9"  Part="1" 
F 0 "C7" H 5675 3750 50  0000 L CNN
F 1 "100nF" H 5675 3550 50  0000 L CNN
F 2 "Footprints:C_CMS0603" H 5688 3500 30  0001 C CNN
F 3 "" H 5650 3650 60  0000 C CNN
	1    5650 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 3300 5100 3650
Wire Wire Line
	5400 3750 5100 3750
Wire Wire Line
	5400 3300 5400 3750
Connection ~ 5100 3450
Connection ~ 5400 3450
Wire Wire Line
	5650 3800 5650 3900
Wire Wire Line
	5100 3850 5650 3850
Connection ~ 5650 3850
Wire Wire Line
	5650 3500 5650 3450
Wire Wire Line
	5650 3450 5400 3450
$EndSCHEMATC
