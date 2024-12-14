This project simulates a real-world traffic light system using Arduino, RGB LEDs, a push button, and a buzzer. The system mimics the functionality of German traffic lights, allowing pedestrians to request a green light while prioritizing car traffic by default.

Features
Car traffic light stays green by default.
Pedestrian button request with an LED indicator.
Realistic traffic light transitions with delays:
Car light transitions through green, blue (yellow simulation), and red.
Pedestrian light transitions through red, green, and blue.
Buzzer rings continuously during the pedestrian green light.
Automatic reset to default state after the cycle.
Designed to simulate real-world traffic control behavior.
Components Required
1 x Arduino Uno
2 x RGB LEDs
1 x Push Button
1 x LED (for pedestrian request indication)
1 x Buzzer
8 x 220Ω Resistors
1 x 10kΩ Resistor (for button pull-up)
Breadboard and Jumper Wires
Step-by-Step Guide
1. Circuit Assembly
Follow this table to connect the components:

Component	Arduino Pin	Breadboard Connection	Other Notes
Car Red LED	Pin 9	Resistor → LED Anode	220Ω resistor, Cathode → GND rail
Car Green LED	Pin 10	Resistor → LED Anode	220Ω resistor, Cathode → GND rail
Car Blue LED	Pin 11	Resistor → LED Anode	220Ω resistor, Cathode → GND rail
Pedestrian Red LED	Pin 6	Resistor → LED Anode	220Ω resistor, Cathode → GND rail
Pedestrian Green LED	Pin 5	Resistor → LED Anode	220Ω resistor, Cathode → GND rail
Pedestrian Blue LED	Pin 3	Resistor → LED Anode	220Ω resistor, Cathode → GND rail
Pedestrian Request LED	Pin 4	Resistor → LED Anode	220Ω resistor, Cathode → GND rail
Buzzer	Pin 7	Positive → Pin 7, Negative → GND	Ensure polarity is correct.
Push Button	Pin 2	1a → Pin 2, 2a → GND rail	Use a 10kΩ pull-up resistor between 1a and 5V.
2. Upload the Code
Connect your Arduino to your computer via USB.
Open the Arduino IDE and paste the following code:
cpp

-----------------------------------------------------------------------------------------
// Pin definitions for Car Traffic Lights
int carRed = 9;
int carGreen = 10;
int carBlue = 11;

// Pin definitions for Pedestrian Traffic Lights
int pedRed = 6;
int pedGreen = 5;
int pedBlue = 3;

// Additional components
int requestLED = 4;  // Pedestrian request LED
int buzzer = 7;      // Buzzer for pedestrian light
int buttonPin = 2;   // Button pin for pedestrians

void setup() {
  // Set all LED pins as output
  pinMode(carRed, OUTPUT);
  pinMode(carGreen, OUTPUT);
  pinMode(carBlue, OUTPUT);
  pinMode(pedRed, OUTPUT);
  pinMode(pedGreen, OUTPUT);
  pinMode(pedBlue, OUTPUT);
  pinMode(requestLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // Set button pin as input with pull-up
  pinMode(buttonPin, INPUT_PULLUP);

  // Initialize default state
  digitalWrite(carGreen, HIGH);  // Cars green
  digitalWrite(pedRed, HIGH);    // Pedestrians red
  digitalWrite(requestLED, LOW); // Request LED off
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    handlePedestrianRequest();
  }
}

void handlePedestrianRequest() {
  // Turn on pedestrian request LED
  digitalWrite(requestLED, HIGH);

  // Step 1: After 3 seconds, car light transitions to blue
  delay(3000);
  digitalWrite(carGreen, LOW);
  digitalWrite(carBlue, HIGH);

  // Step 2: After 2 seconds, car light turns red and pedestrian light turns green
  delay(2000);
  digitalWrite(carBlue, LOW);
  digitalWrite(carRed, HIGH);
  digitalWrite(pedRed, LOW);
  digitalWrite(pedGreen, HIGH);

  // Turn off pedestrian request LED
  digitalWrite(requestLED, LOW);

  // Step 3: Buzzer rings while pedestrian light is green
  for (int i = 0; i < 15; i++) {  // 15 short beeps for 3 seconds
    digitalWrite(buzzer, HIGH);
    delay(100);  // Buzzer ON for 100ms
    digitalWrite(buzzer, LOW);
    delay(100);  // Buzzer OFF for 100ms
  }

  // Step 4: Pedestrian light transitions from green to blue
  digitalWrite(pedGreen, LOW);
  digitalWrite(pedBlue, HIGH);
  delay(2000);

  // Step 5: Pedestrian light turns red, car light turns blue
  digitalWrite(pedBlue, LOW);
  digitalWrite(pedRed, HIGH);
  digitalWrite(carRed, LOW);
  digitalWrite(carBlue, HIGH);
  delay(2000);

  // Step 6: Car light turns green
  digitalWrite(carBlue, LOW);
  digitalWrite(carGreen, HIGH);
}
-----------------------------------------------------------
Click Upload in the Arduino IDE.
Open the Serial Monitor if needed for debugging.
3. Test the Circuit
Power on the Arduino.
Observe the following behavior:
Car light is green, and pedestrian light is red by default.
Press the button to start the pedestrian crossing sequence.
Check the buzzer, light transitions, and timing.
Verify the system resets after the cycle.
4. Troubleshooting
LEDs not lighting up: Check the connections and ensure resistors are properly placed.
Buzzer not working: Ensure the buzzer polarity matches the wiring.
No response to the button: Verify the pull-up resistor and button connections.
Timing issues: Adjust the delays in the code to match desired timings.
5. How to Expand
Add sensors for automatic vehicle detection.
Implement a night mode with flashing yellow lights.
Integrate IoT modules for remote monitoring.
