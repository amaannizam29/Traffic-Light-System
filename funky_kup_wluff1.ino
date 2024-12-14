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

// Timing variables
unsigned long lastPressTime = 0;
unsigned long timeout = 20000;  // 20-second auto-reset

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
  // Check for button press
  if (digitalRead(buttonPin) == LOW) {
    delay(50);  // Debounce delay
    if (digitalRead(buttonPin) == LOW) {  // Confirm button press
      handlePedestrianRequest();
      lastPressTime = millis();  // Update last press time
    }
  }

  // Auto-reset to default state after timeout
  if (millis() - lastPressTime > timeout) {
    resetToDefault();
  }
}

void handlePedestrianRequest() {
  // Turn on pedestrian request LED
  digitalWrite(requestLED, HIGH);

  // Step 1: After 3 seconds, car light transitions to blue
  delay(3000);
  digitalWrite(carGreen, LOW);
  digitalWrite(carBlue, HIGH);  // Yellow light simulation

  // Step 2: After 2 more seconds, car light turns red, pedestrian light green
  delay(2000);
  digitalWrite(carBlue, LOW);
  digitalWrite(carRed, HIGH);
  digitalWrite(pedRed, LOW);
  digitalWrite(pedGreen, HIGH);

  // Turn off pedestrian request LED
  digitalWrite(requestLED, LOW);

  // Step 3: Buzzer rings while pedestrian light is green (3 seconds)
  for (int i = 0; i < 15; i++) {  // 15 short beeps for 3 seconds
    digitalWrite(buzzer, HIGH);
    delay(100);  // Buzzer ON for 100ms
    digitalWrite(buzzer, LOW);
    delay(100);  // Buzzer OFF for 100ms
  }

  // Step 4: Pedestrian light turns blue (prepare to stop)
  digitalWrite(pedGreen, LOW);
  digitalWrite(pedBlue, HIGH);
  delay(2000);  // 2 seconds

  // Step 5: Pedestrian light turns red, car light turns blue (prepare to go)
  digitalWrite(pedBlue, LOW);
  digitalWrite(pedRed, HIGH);
  digitalWrite(carRed, LOW);
  digitalWrite(carBlue, HIGH);
  delay(2000);  // 2 seconds

  // Step 6: Car light turns green, returning to default state
  digitalWrite(carBlue, LOW);
  digitalWrite(carGreen, HIGH);
}

void resetToDefault() {
  // Reset lights to default state
  digitalWrite(carRed, LOW);
  digitalWrite(carBlue, LOW);
  digitalWrite(carGreen, HIGH);
  digitalWrite(pedRed, HIGH);
  digitalWrite(pedGreen, LOW);
  digitalWrite(pedBlue, LOW);
  digitalWrite(requestLED, LOW);
}
