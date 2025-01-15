#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Pin definitions
#define trigPin 3
#define echoPin 4

// LCD setup
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Variables
long duration;
int distance;
int peopleCount = 0;

const int entryThreshold = 50; // Entry distance threshold (cm)
const int exitThreshold = 150; // Exit distance threshold (cm)
bool personDetected = false;  // Whether a person is currently detected
unsigned long lastDetectionTime = 0; // To debounce detections
const unsigned long debounceDelay = 1000; // 1-second debounce period

void setup() {
  // Initialize serial monitor and LCD
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.backlight();

  // HC-SR04 pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Initial message
  lcd.setCursor(0, 0);
  lcd.print("People Counter");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Count: 0");
}

int measureDistance() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the echo duration
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  int measuredDistance = duration * 0.034 / 2;

  // Return valid distance or -1 if invalid
  return (measuredDistance > 0 && measuredDistance < 400) ? measuredDistance : -1;
}

void loop() {
  // Measure the current distance
  distance = measureDistance();

  // Ignore invalid readings
  if (distance == -1) {
    return;
  }

  // Debounce: Allow counting only after the debounce delay
  unsigned long currentTime = millis();
  if (currentTime - lastDetectionTime < debounceDelay) {
    return;
  }

  // Detect entry and exit
  if (!personDetected && distance < entryThreshold) {
    personDetected = true; // Person enters detection zone
    lastDetectionTime = currentTime;
    Serial.println("Person detected entering.");
  } else if (personDetected && distance > exitThreshold) {
    personDetected = false; // Person exits detection zone
    peopleCount++; // Increment count
    lastDetectionTime = currentTime;
    Serial.println("Person counted.");
    
    // Update LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Count: ");
    lcd.print(peopleCount);
  }

  // Debugging on Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(100); // Delay for stability
}
