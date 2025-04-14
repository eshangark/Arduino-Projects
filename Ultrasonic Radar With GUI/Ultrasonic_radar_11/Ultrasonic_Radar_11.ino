#include <Servo.h>

// Pin assignments
const int servoPin = 9;    // Servo control signal
const int trigPin = 10;    // HC-SR04 Trigger pin
const int echoPin = 11;    // HC-SR04 Echo pin
const int buzzerPin = 8;   // Buzzer for proximity alert

// Configuration parameters
const int threshold = 20;       // Distance threshold in centimeters for buzzer activation
const int movementDelay = 15;   // Delay (in ms) between servo increments for smooth motion

// Calibrated center position
// Adjust this value if the physical center is not achieved at a command of 90°
// For example, if a command of 90° is too far right, try increasing this value (e.g., 100)
const int servoCenter = 120;

// Sweep extents relative to the calibrated center.
// Here we are aiming for a sweep of 90° to the right and 90° to the left.
const int sweepAngle = 90;
// Calculate limits ensuring the servo stays within 0° to 180°
const int rightLimit = min(servoCenter + sweepAngle, 180);
const int leftLimit  = max(servoCenter - sweepAngle, 0);

Servo myServo;
bool initialScan = true;

void setup() {
  // Attach the servo and move it to the calibrated center.
  myServo.attach(servoPin);
  myServo.write(servoCenter);
  delay(500);  // Allow time to settle at the center
  
  // Set up pins for the ultrasonic sensor and buzzer
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Begin Serial communication
  Serial.begin(9600);
}

void loop() {
  // First, move from the calibrated center to the right limit.
  if (initialScan) {
    for (int angle = servoCenter; angle <= rightLimit; angle++) {
      sweepAndMeasure(angle);
    }
    initialScan = false;
  }
  
  // Continuous scanning:
  // Sweep from right limit to left limit (simulate a radar sweep)
  for (int angle = rightLimit; angle >= leftLimit; angle--) {
    sweepAndMeasure(angle);
  }
  // Then sweep from left limit back to right limit.
  for (int angle = leftLimit; angle <= rightLimit; angle++) {
    sweepAndMeasure(angle);
  }
}

// Function to move the servo to a given angle, read the distance, control the buzzer, and output via Serial.
void sweepAndMeasure(int angle) {
  myServo.write(angle);
  delay(movementDelay);
  
  int distance = readDistance();
  
  // Activate the buzzer when an object is within the threshold distance.
  if (distance > 0 && distance < threshold) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }
  
  // Send the angle and distance as a comma-separated string.
  Serial.print(angle);
  Serial.print(",");
  Serial.println(distance);
}

// Function to trigger the ultrasonic sensor and calculate the distance (in centimeters)
int readDistance() {
  // Ensure a clean pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echo pulse (with a timeout for safety)
  long duration = pulseIn(echoPin, HIGH, 30000);
  
  // Convert the pulse duration to distance (speed of sound ≈ 0.034 cm/µs)
  int distance = duration * 0.034 / 2;
  
  return distance;
}
