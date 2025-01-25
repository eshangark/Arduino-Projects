#include <IRremote.h>

#define TRIG_PIN 9    // Trigger pin of the ultrasonic sensor
#define ECHO_PIN 10   // Echo pin of the ultrasonic sensor
#define BUZZER_PIN 5  // Pin connected to the active buzzer
#define IR_LED_PIN 3  // Pin where the IR LED is connected

IRsend irsend;  // Create an IR send object

long duration;
int distance;
int previousDistance = 0;   // Store the last distance value
const int motionThreshold = 65;  // Change in distance threshold to detect motion (cm)
unsigned long lastMotionTime = 0;  // Time of the last detected motion
const unsigned long debounceDelay = 1000;  // Delay to prevent double detection (in ms)
bool isMotionDetected = false;  // State flag for motion detection

// Replace with the hex code you captured from the remote control
unsigned long irCode = 0x20DF10EF;  // Example IR code (replace this with your captured hex code)

void setup() {
  pinMode(TRIG_PIN, OUTPUT);   // Set TRIG pin as an OUTPUT
  pinMode(ECHO_PIN, INPUT);    // Set ECHO pin as an INPUT
  pinMode(BUZZER_PIN, OUTPUT); // Set BUZZER pin as an OUTPUT
  pinMode(IR_LED_PIN, OUTPUT); // Set IR LED pin as an OUTPUT
  
  Serial.begin(9600);  // Start serial communication
}

void playBuzzer() {
  digitalWrite(BUZZER_PIN, HIGH);  // Turn on the active buzzer
  delay(500);                      // Keep it on for 500 ms
  digitalWrite(BUZZER_PIN, LOW);   // Turn off the active buzzer
}

void loop() {
  // Send a 10-microsecond pulse to the TRIG pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Read the duration of the pulse from the ECHO pin
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate distance in cm
  distance = duration * 0.0344 / 2;  // Speed of sound = 0.0344 cm/us
  
  Serial.print("Current Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Get the current time
  unsigned long currentTime = millis();
  
  // Check for significant change in distance to detect motion
  if (!isMotionDetected && abs(distance - previousDistance) > motionThreshold) {
    // Prevent double detection by checking debounce delay
    if (currentTime - lastMotionTime > debounceDelay) {
      Serial.println("Motion Detected!");
      
      // Play sound pattern on the active buzzer
      playBuzzer();
      
      // Send the IR signal to turn on the TV
      irsend.sendNEC(irCode, 32);  // 32 is the bit length for the NEC protocol
      
      // Set motion detected flag
      isMotionDetected = true;
      
      // Update the last motion time
      lastMotionTime = currentTime;
    }
  }
  
  // Reset the motion detected flag after debounceDelay
  if (isMotionDetected && currentTime - lastMotionTime > debounceDelay) {
    isMotionDetected = false;
  }
  
  // Update the previous distance
  previousDistance = distance;

  delay(100);  // Short delay to stabilize readings
}
