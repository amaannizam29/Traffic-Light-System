// Pin definitions for RGB LED 1 (Cars)
int carRed = 9;
int carGreen = 10;
int carBlue = 11;

// Pin definitions for RGB LED 2 (Pedestrians)
int pedRed = 6;
int pedGreen = 5;
int pedBlue = 3;

// Button pin
int buttonPin = 2;

void setup() {
  // Set RGB LED pins as output
  pinMode(carRed, OUTPUT);
  pinMode(carGreen, OUTPUT);
  pinMode(carBlue, OUTPUT);
  pinMode(pedRed, OUTPUT);
  pinMode(pedGreen, OUTPUT);
  pinMode(pedBlue, OUTPUT);

  // Set button pin as input with pull-up
  pinMode(buttonPin, INPUT_PULLUP);

  // Initialize lights: Cars green, Pedestrians red
  digitalWrite(carGreen, HIGH);
  digitalWrite(pedRed, HIGH);
}

void loop() {
  // Check if the button is pressed
  if (digitalRead(buttonPin) == LOW) {
    // Button pressed, change to pedestrian crossing mode

    // Turn car light yellow (simulate German traffic light transition)
    digitalWrite(carGreen, LOW);
    digitalWrite(carBlue, HIGH); // Yellow light simulation
    delay(1000);

    // Turn car light red and pedestrian light green
    digitalWrite(carBlue, LOW);
    digitalWrite(carRed, HIGH);
    digitalWrite(pedRed, LOW);
    digitalWrite(pedGreen, HIGH);
    delay(5000); // Pedestrian can cross for 5 seconds

    // Turn pedestrian light blue (finish crossing)
    digitalWrite(pedGreen, LOW);
    digitalWrite(pedBlue, HIGH);
    delay(2000);

    // Reset pedestrian light to red
    digitalWrite(pedBlue, LOW);
    digitalWrite(pedRed, HIGH);

    // Turn car light blue (prepare to go)
    digitalWrite(carRed, LOW);
    digitalWrite(carBlue, HIGH);
    delay(1000);

    // Turn car light back to green
    digitalWrite(carBlue, LOW);
    digitalWrite(carGreen, HIGH);
  }

  // Default state: Car light stays green, Pedestrian stays red
}
