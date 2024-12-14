This repository contains two versions of an Arduino-based traffic light system. Both simulate real-world traffic light behavior, but with varying levels of functionality to suit different project requirements and complexity levels.

Overview

Basic Traffic Light System:

A simple implementation of a traffic light system using an Arduino and RGB LEDs.
Focuses on controlling car and pedestrian lights with realistic transitions.
No additional buzzer or pedestrian request LED.

Advanced Traffic Light System:

Adds features to simulate a more realistic German-style traffic light system.
Includes a buzzer for pedestrian crossings and a request LED that lights up when the pedestrian button is pressed.
Both versions are fully documented with circuit diagrams, code files, and descriptions for easy setup.


Features
Basic Traffic Light System
Simulates car and pedestrian traffic lights.
Default behavior:
Car light is green.
Pedestrian light is red.
Simple light transitions:
Car light switches to red when the pedestrian light turns green.
Lights reset to default state after the pedestrian cycle.
Advanced Traffic Light System
Includes all features from the basic system.
Buzzer Integration:
Rings continuously while the pedestrian light is green.
Pedestrian Request LED:
Lights up when a pedestrian presses the button.
Turns off when the pedestrian light turns green.
Realistic transitions and delays:
Follows a German-style traffic light system with clear delays between light states.
Automatic reset after the pedestrian cycle.
Repository Structure

File	Description
basic-code.ino	Arduino code for the basic traffic light system.
basic-circuit.png	Circuit diagram for the basic traffic light system.
advanced-code.ino	Arduino code for the advanced traffic light system with buzzer and request LED.
Advanced-Circuit.png	Circuit diagram for the advanced traffic light system.
Advanced-Circuit-Detailed.pdf	A detailed blueprint of the advanced circuit.

Components Required
Basic System
1 x Arduino Uno
2 x RGB LEDs
7 x 220Ω Resistors
1 x Push Button
Breadboard and Jumper Wires
Advanced System
All components from the basic system plus:
1 x LED (for pedestrian request indication)
1 x Buzzer
1 x 10kΩ Resistor (for pull-up on the button)

How to Build
1. Basic Traffic Light System
Refer to the circuit diagram (basic-circuit.png) to wire your components:
Use RGB LEDs for car and pedestrian lights.
Connect resistors to limit current to the LEDs.
Wire the push button with a pull-up resistor.
Upload the basic-code.ino file to your Arduino.
Observe the behavior:
The car light is green by default.
When the button is pressed, the car light transitions to red, and the pedestrian light turns green.
The system resets to the default state after the pedestrian cycle.

2. Advanced Traffic Light System
Refer to the detailed circuit diagram (Advanced-Circuit.png or Advanced-Circuit-Detailed.pdf) to wire your components:
Add the buzzer and request LED as shown in the diagram.
Use RGB LEDs for car and pedestrian lights.
Connect resistors to protect the LEDs.
Wire the push button with a pull-up resistor.
Upload the advanced-code.ino file to your Arduino.

Observe the behavior:
The car light is green, and the pedestrian light is red by default.

When the button is pressed:
The pedestrian request LED lights up.
The car light transitions from green to blue (yellow simulation) and then to red.
The pedestrian light turns green, and the buzzer rings continuously for the duration of the pedestrian green light.
After the pedestrian light turns blue (prepare to stop), it switches back to red, and the car light transitions back to green.
The system automatically resets after the cycle.
Timing Details (Advanced System)

Default State:
Car: Green
Pedestrian: Red
Button Press:
After 3 seconds: Car light turns blue (yellow simulation).
After another 2 seconds: Car light turns red, and pedestrian light turns green (buzzer rings).
After 3 seconds: Pedestrian light turns blue (prepare to stop).
After 2 seconds: Pedestrian light turns red, and car light turns blue (prepare to go).
After 2 seconds: Car light turns green.

How to Test
Assemble the Circuit:
Use the diagrams to connect the components correctly.
Upload the Code:
Select either the basic-code.ino or advanced-code.ino file based on your setup.
Test the Default State:
Car light should be green, and pedestrian light should be red.
Press the Button:
For the basic system, observe the light transitions.
For the advanced system, check the request LED, buzzer, and realistic transitions.

Verify Reset:
Ensure the system resets to the default state after completing the cycle.

Troubleshooting
LEDs not lighting up:
Verify connections and resistor placements.
Button not working:
Check the pull-up resistor and button wiring.
Buzzer not ringing:
Ensure correct polarity for the buzzer.
Timing issues:
Adjust delays in the code for your desired timings.

How to Expand
Night Mode:
Flash yellow lights for cars and turn off pedestrian signals during low traffic hours.
Automatic Detection:
Add sensors for car and pedestrian detection.
IoT Integration:
Monitor and control the system remotely via Wi-Fi or Bluetooth.

Thanks for Checking Out the Project!
This repository contains everything you need to build both the basic and advanced versions of the Arduino traffic light system. Feel free to contribute or modify the project as needed! 🚦

