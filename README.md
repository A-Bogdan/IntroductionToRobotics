# IntroductionToRobotics
Introduction to Robotics homeworks, this is an optional course taken in the 4th year at the Faculty of Mathematics and Computer Science, University of Bucharest. Each homework includes requirements, implementation details, code and image files.

# Homework 1
### Components 
RBG  LED  (1  minimum),  potentiometers  (3  minimum),resistors and wires (per logic).
### Technical Task
Use a separate potentiometer in controlling each of the colors of the RGB led (Red, Green and Blue).  The control must be done with digital electronics(you must read the value of the potentiometer with Arduino, and write a mapped value to each of the pins connected to the led).

### Video
Live testing [here](https://youtu.be/mbYpfbbzCeY).

# Homework 2
### Components
5 LEDs, 1 button, 1 buzzer, resistors and wires (per logic)
### Technical Task
Building the traffic lights for a crosswalk. You will use 2 LEDs to represent the traffic lights for people (red and green) and 3 LEDs to represent the traffic lights for cars (red, yellow and green). See the states it needs to go through.
### System states
#### State 1
(default, reinstated after state 4 ends): green light for cars,red light for people, no sounds.   Duration: indefinite, changed by pressing the button.
#### State 2
(initiated by counting down 8 seconds after a button press):the light should be yellow for cars, red  for people and no sounds. Duration: 3 seconds.
#### State 3
(initiated after state 2 ends): red for cars, green for people and a beeping sound from the buzzer at a constant interval. Duration: 8 seconds.
#### State 4
(initiated after state 3 ends): red for cars, blinking green for people and a beeping sound from the buzzer, at a constant interval, faster than the beeping in state 3. This state should last 4 seconds.
### Video
Live testing [here](https://youtu.be/1m6PPYR4cYo).

# Homework 3
### Components
1 7-segment display, 1 joystick, resistors and wires (perlogic)
### General description
You will use the joystick to control the position ofthe segment and ”draw” on the display.  The movement between segments should be natural (meaning they should jump from the current position only to neighbors, but without passing through ”walls”.
### System states
#### State 1:
(default,  but  also  initiated  after  a  button  press  in  State 2): Current position blinking. Can use the joystick to move from one  position to neighbors. Short pressing the button toggles state 2. Long pressing the button in state 1 resets the entire display by turning all the segments OFF and moving the current position to the decimal point.
#### State 2:
(initiated after a button press in State 1): The current segment stops blinking, adopting the state of the segment before selection (ON or OFF). Toggling the X (or Y, you chose) axis should change the segment state from ON to OFF or from OFF to ON. Clicking the joystick should save the segment state and exit back to state 1.

# Homework 4
### Components
a joystick, a 4 digit 7-segment display, a 74hc595 shiftregister
### General description
Use the joystick to move through the 4 digit 7-segment displays digits, press the button to lock in on the current digitand use the other axis to increment or decrement the number. Keep the button pressed to reset all the digit values and the current position to the first digit in the first state.
### System states
#### State 1:
You can use a joystick axis to cycle through the 4 digits; using the other axis does nothing. A blinking decimal point shows the current digit position. When pressing the button, you lock in on the selected digit and enter the second state.
#### State 2:
in this state, the decimal point stays always on, no longer blinking and you can no longer use the axis to cycle throughthe 4 digits. Instead, using the other axis, you can increment or decrement the  number on the current digit IN HEX(aka from 0 to F, as in the lab). Pressing the button again returns you to the previous state. Also, keep in mind that when changing the number, you must increment it  for each joystick movement - it should not work continuosly increment if you keep the joystick in one position (aka with joyMoved).
#### State 3:
Reset: toggled by long pressing the button only in the first state. When resetting, all the digits go back to 0 and the current positionis set to the first (rightmost) digit, in the first state.
