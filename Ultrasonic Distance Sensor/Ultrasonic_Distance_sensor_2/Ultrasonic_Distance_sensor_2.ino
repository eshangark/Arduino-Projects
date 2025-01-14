#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Pin connections for the HC-SR04 ultrasonic sensor
#define trigPin 3
#define echoPin 4

// Initialize the LCD with I2C address 0x27 (change if needed)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize the serial monitor and LCD
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.backlight();
  
  // Set HC-SR04 pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Display initial message on LCD
  lcd.setCursor(0, 0);
  lcd.print("Distance Sensor");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);  // Wait for 2 seconds
  lcd.clear();
}

void loop() {
  // Send a 10µs pulse to trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the time taken for the pulse to return
  long duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance based on the duration
  long distance = duration * 0.034 / 2;  // Speed of sound: 0.034 cm/us
  
  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Display the distance on the LCD (1st row)
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");

  // Clear the remaining part of the LCD row
  int len = String(distance).length() + 3;  // Account for the " cm" part
  for (int i = len; i < 16; i++) {    // Clear any remaining characters
    lcd.print(" ");
  }

  delay(500); // Wait for 0.5 seconds before updating
}
