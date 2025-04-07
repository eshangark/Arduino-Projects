const int buttonPin = 2;  // Button connected to D2

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // Use internal pull-up resistor
  Serial.begin(9600);
  Serial.println("Button test initialized...");
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {  // Button is pressed
    Serial.println("Button pressed!");
  } else {  // Button is not pressed
    
  }

  delay(200);  // Small delay to avoid spamming the Serial Monitor
}
