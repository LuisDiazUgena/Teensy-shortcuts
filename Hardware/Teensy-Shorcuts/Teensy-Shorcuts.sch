EESchema Schematic File Version 2
LIBS:LCD20x4
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
LIBS:Teensy-Shorcuts-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L SW_PUSH SW?
U 1 1 55056201
P 1850 1150
F 0 "SW?" H 2000 1260 50  0000 C CNN
F 1 "SW_PUSH" H 1850 1070 50  0000 C CNN
F 2 "" H 1850 1150 60  0000 C CNN
F 3 "" H 1850 1150 60  0000 C CNN
	1    1850 1150
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 55056234
P 1850 1750
F 0 "SW?" H 2000 1860 50  0000 C CNN
F 1 "SW_PUSH" H 1850 1670 50  0000 C CNN
F 2 "" H 1850 1750 60  0000 C CNN
F 3 "" H 1850 1750 60  0000 C CNN
	1    1850 1750
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 55056256
P 1850 2250
F 0 "SW?" H 2000 2360 50  0000 C CNN
F 1 "SW_PUSH" H 1850 2170 50  0000 C CNN
F 2 "" H 1850 2250 60  0000 C CNN
F 3 "" H 1850 2250 60  0000 C CNN
	1    1850 2250
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 55056277
P 1850 2650
F 0 "SW?" H 2000 2760 50  0000 C CNN
F 1 "SW_PUSH" H 1850 2570 50  0000 C CNN
F 2 "" H 1850 2650 60  0000 C CNN
F 3 "" H 1850 2650 60  0000 C CNN
	1    1850 2650
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 550562CE
P 2650 1150
F 0 "R?" V 2730 1150 50  0000 C CNN
F 1 "R" V 2657 1151 50  0000 C CNN
F 2 "" V 2580 1150 30  0000 C CNN
F 3 "" H 2650 1150 30  0000 C CNN
	1    2650 1150
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 55056305
P 2650 1750
F 0 "R?" V 2730 1750 50  0000 C CNN
F 1 "R" V 2657 1751 50  0000 C CNN
F 2 "" V 2580 1750 30  0000 C CNN
F 3 "" H 2650 1750 30  0000 C CNN
	1    2650 1750
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 5505632B
P 2650 2250
F 0 "R?" V 2730 2250 50  0000 C CNN
F 1 "R" V 2657 2251 50  0000 C CNN
F 2 "" V 2580 2250 30  0000 C CNN
F 3 "" H 2650 2250 30  0000 C CNN
	1    2650 2250
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 55056352
P 2650 2650
F 0 "R?" V 2730 2650 50  0000 C CNN
F 1 "R" V 2657 2651 50  0000 C CNN
F 2 "" V 2580 2650 30  0000 C CNN
F 3 "" H 2650 2650 30  0000 C CNN
	1    2650 2650
	0    1    1    0   
$EndComp
Wire Wire Line
	2400 1150 2150 1150
Wire Wire Line
	2400 1750 2150 1750
Wire Wire Line
	2400 2250 2150 2250
Wire Wire Line
	2400 2650 2150 2650
Text GLabel 3100 1150 2    60   Input ~ 0
GND
Text GLabel 3100 1750 2    60   Input ~ 0
GND
Text GLabel 3100 2250 2    60   Input ~ 0
GND
Text GLabel 3100 2650 2    60   Input ~ 0
GND
Wire Wire Line
	3100 2650 2900 2650
Wire Wire Line
	2900 2250 3100 2250
Wire Wire Line
	2900 1750 3100 1750
Wire Wire Line
	2900 1150 3100 1150
Text GLabel 1250 1150 0    60   Input ~ 0
VCC
Text GLabel 1250 1750 0    60   Input ~ 0
VCC
Text GLabel 1250 2250 0    60   Input ~ 0
VCC
Text GLabel 1250 2650 0    60   Input ~ 0
VCC
Wire Wire Line
	1250 1150 1550 1150
Wire Wire Line
	1550 1750 1250 1750
Wire Wire Line
	1550 2250 1250 2250
Wire Wire Line
	1550 2650 1250 2650
Text GLabel 2250 1000 1    60   Input ~ 0
D0
Text GLabel 2250 1650 1    60   Input ~ 0
D1
Text GLabel 2250 2150 1    60   Input ~ 0
D2
Text GLabel 2250 2550 1    60   Input ~ 0
D3
Wire Wire Line
	2250 2550 2250 2650
Connection ~ 2250 2650
Wire Wire Line
	2250 2150 2250 2250
Connection ~ 2250 2250
Wire Wire Line
	2250 1650 2250 1750
Connection ~ 2250 1750
Wire Wire Line
	2250 1000 2250 1150
Connection ~ 2250 1150
$Comp
L LCD20x4 DS?
U 1 1 55056E32
P 5450 1200
F 0 "DS?" H 4650 1600 40  0000 C CNN
F 1 "LCD20x4" H 6150 1600 40  0000 C CNN
F 2 "WC1602A" H 5450 1150 35  0000 C CIN
F 3 "" H 5450 1200 60  0000 C CNN
	1    5450 1200
	1    0    0    -1  
$EndComp
Text GLabel 4700 1950 3    60   Input ~ 0
GND
Text GLabel 5100 1950 3    60   Input ~ 0
GND
Text GLabel 6200 1950 3    60   Input ~ 0
GND
Wire Wire Line
	4700 1700 4700 1950
Wire Wire Line
	5100 1950 5100 1700
Wire Wire Line
	6200 1950 6200 1700
Text GLabel 4800 2250 3    60   Input ~ 0
VCC
Wire Wire Line
	4800 1700 4800 2250
$Comp
L POT RV?
U 1 1 550571AB
P 4900 2750
F 0 "RV?" H 4900 2650 50  0000 C CNN
F 1 "POT" H 4900 2750 50  0000 C CNN
F 2 "" H 4900 2750 60  0000 C CNN
F 3 "" H 4900 2750 60  0000 C CNN
	1    4900 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 2600 4900 1700
Text GLabel 4650 3050 3    60   Input ~ 0
VCC
Wire Wire Line
	4650 2750 4650 3050
Text GLabel 5150 3050 3    60   Input ~ 0
GND
Wire Wire Line
	5150 3050 5150 2750
Text GLabel 5000 1850 3    40   Input ~ 0
12
Wire Wire Line
	5000 1850 5000 1700
Text GLabel 5200 1800 3    40   Input ~ 0
11
Wire Wire Line
	5200 1800 5200 1700
Text GLabel 5700 1800 3    40   Input ~ 0
11
Text GLabel 5800 1800 3    40   Input ~ 0
11
Text GLabel 5900 1800 3    40   Input ~ 0
11
Text GLabel 6000 1800 3    40   Input ~ 0
11
Wire Wire Line
	5700 1800 5700 1700
Wire Wire Line
	5800 1800 5800 1700
Wire Wire Line
	5900 1800 5900 1700
Wire Wire Line
	6000 1800 6000 1700
Text GLabel 6100 2250 3    60   Input ~ 0
VCC
Wire Wire Line
	6100 2250 6100 1700
$EndSCHEMATC
