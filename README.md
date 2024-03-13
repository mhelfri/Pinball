Tremaine Richardson, Max Helfrich
Pinball: An Embedded Systems Pinball Machine
03/12/2024

Code Summary:
The code makes use of 4 drivers, 2 subsystems, and 1 system. The drivers individually control the 4 components of our project,
the servo motors, the points system, the round system, and our LCD display. One subsystem just uses the servo motors to control
our flippers, and the other is responsible for updating information about the round system, point system, as well as displaying
this information to the player. 

Modules:
Pinball - System - Written from scratch-
Calls the initial and update functions from the subsystems

Flippers - Subsystem - Written from scratch-
Uses servo_motor to write the servo motors to specific duty cycles when their respective buttons are pressed

User_Interface - Subsystem - Written from scratch-
Uses round_control, point_accumulation, and display to control the round state variables given the limit switch inputs.
Also controls the points variable given the test button input. And then writes to the display information about the round state
and point total, and controls the LEDs corresponding to changes in the round state.

Round_Control - Driver - Written from scratch-
Has two boolean variable and one int variable. Has write and read functions to manipulate these variables and read information
from them. The two boolean variables are used to track the current round state and the previous round state, and the int variable
is used to track how many times the round state has changed.

Point_Accumulation - Driver - Written from scratch-
Has two int variables with write and read functions to manipulate these variables and read information from them, similar to 
round_control. These int variables represent the current point total and the previous point total.

Servo_Motor - Driver - Based on class code-
Sets the period for two servo motors and has functions that can be called to write the duty cycle to each motor separately
given a float parameter. Also contains all of the macros that define the min, max, and flip duty cycles for the motors.

Display - Driver - Based on textbook code-
Controls the LCD display inputs and has functions that move the "cursor" position on the LCD and writes to the LCD
given a string.

Hardware components:

Sprarkfun LCD display
  1: GND, GND
  2: VCC, 3.3V
  3: V0, Trimpot Potentiometer
  4: RS, PD_15
  5: R/W, GND
  6: E, PF_12
  7: D0, PG_9
  8: D1, PG_14
  9: D2, PF_15
  10: D3, PE_13
  11: D4, PF_14
  12: D5, PE_11
  13: D6, PE_9
  14: D7, PF_13
  15: LED-A, 3.3
  16:LED-K, GND

LED1
  PB_9, GND
LED2
  PB_8, GND

LIMIT SWITCHES
  PA_6, GND

SOLENOID DETECT
  PA_5

Right flipper button
  PD_14

Left flipper button
  PA_7

Servo 1
  PF-9, 1/PWM
  5V, 2
  GND, 3
    
Servo 2
 PF-8, 1/PWM
  5V, 2
  GND, 3


System Specification and Tests:
![image](https://github.com/mhelfri/Pinball/assets/155551490/69d5f80d-b366-4640-95d9-014129d69668)
![image](https://github.com/mhelfri/Pinball/assets/155551490/a3394e28-434d-4ff1-a447-40436b9ff211)
![image](https://github.com/mhelfri/Pinball/assets/155551490/c9b9b60f-5697-49c3-8141-ed2f4dbe80a3)




  
  
