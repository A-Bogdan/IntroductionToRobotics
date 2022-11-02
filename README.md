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
