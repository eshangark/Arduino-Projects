#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Pin Definitions
const int leftButton = 2;    // Minute button
const int middleButton = 3;  // Second button
const int rightButton = 4;   // Start button
const int buzzerPin = 6;     // Passive Buzzer connected to pin 6

// Time variables
int minutes = 0;
int seconds = 0;
bool timerRunning = false;
bool startPressed = false;

// LCD setup
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Adjust the LCD address if necessary

void setup() {
  // Start Serial Communication for debugging
  Serial.begin(9600);

  // Set up button pins with internal pull-up resistors
  pinMode(leftButton, INPUT_PULLUP);
  pinMode(middleButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);

  // Initialize LCD
  lcd.begin(16, 2);
  lcd.setBacklight(1);  // Ensure the backlight is on
  lcd.clear();

  // Display "Timer Display" for 4 seconds (Centered)
  int pos = (16 - 12) / 2;  // Calculate position to center the text ("Timer Display" is 12 characters long)
  lcd.setCursor(pos, 0);
  lcd.print("Timer Display");
  delay(4000);  // Wait for 4 seconds

  // Now display the "Time Set" screen (Centered) and time as 00:00
  lcd.clear();
  pos = (16 - 8) / 2;  // Center "Time Set" (8 characters)
  lcd.setCursor(pos, 0);
  lcd.print("Time Set");
  pos = (16 - 5) / 2;  // Center "00:00" (5 characters)
  lcd.setCursor(pos, 1);
  lcd.print("00:00");
  delay(2000);  // Wait for 2 seconds
}

void loop() {
  // Read button states and handle logic
  if (digitalRead(leftButton) == LOW) {  // Left button pressed (Increase Minutes)
    delay(200);  // Debounce delay
    if (!timerRunning) {
      minutes++;
      if (minutes > 99) minutes = 99;  // Limit to 99 minutes
      updateDisplay();
    }
  }

  if (digitalRead(middleButton) == LOW) {  // Middle button pressed (Increase Seconds)
    delay(200);  // Debounce delay
    if (!timerRunning) {
      seconds++;
      if (seconds > 59) seconds = 0;  // Reset seconds after 59
      updateDisplay();
    }
  }

  if (digitalRead(rightButton) == LOW && !startPressed) {  // Right button pressed (Start Timer)
    delay(200);  // Debounce delay
    startPressed = true;  // Prevent repeated presses
    if (!timerRunning) {
      timerRunning = true;
      Serial.println("Timer started!");
    }
  }

  // Timer countdown logic (only if timer is running)
  if (timerRunning) {
    if (seconds == 0 && minutes > 0) {
      minutes--;
      seconds = 59;
      updateDisplay();
    } else if (seconds > 0) {
      seconds--;
      updateDisplay();
    }

    // Check if the timer has reached zero
    if (minutes == 0 && seconds == 0) {
      timerRunning = false;  // Stop the timer after it reaches 00:00
      triggerBuzzer();  // Trigger buzzer when timer finishes
      startPressed = false;  // Reset start button state for next round
    }

    delay(1000);  // Wait for 1 second before updating again
  }
}

void updateDisplay() {
  // Update the time on the display (MM:SS format), keeping "Time Set" on top and updating time below it
  lcd.clear();
  
  // Print "Time Set" on the first line (always static)
  int pos = (16 - 8) / 2;  // Center "Time Set" (8 characters)
  lcd.setCursor(pos, 0);
  lcd.print("Time Set");

  // Print the time on the second line (MM:SS format)
  pos = (16 - 5) / 2;  // Center "00:00" (5 characters)
  lcd.setCursor(pos, 1);
  if (minutes < 10) lcd.print("0");
  lcd.print(minutes);
  lcd.print(":");
  if (seconds < 10) lcd.print("0");
  lcd.print(seconds);
}

void triggerBuzzer() {
  // Turn on buzzer for a dynamic pattern
  Serial.println("Timer reached 00:00, buzzer triggered!");

  // Flash "Timer Over!" for each short buzz with changing tones
  for (int i = 0; i < 3; i++) {
    lcd.clear();
    int pos = (16 - 11) / 2;  // Center "Timer Over!" (11 characters)
    lcd.setCursor(pos, 0);
    lcd.print("Timer Over!");
    
    // Varying tone frequency for a rising/falling pattern
    tone(buzzerPin, 500 + (i * 200));  // Rise in tone frequency
    delay(300);  // Buzz for 0.3 seconds
    noTone(buzzerPin);  // Stop buzzer
    delay(300);  // Pause for 0.3 seconds
    lcd.clear();  // Clear display after the tone
    delay(300);  // Wait before showing the message again
  }

  // Longer tone after the burst pattern with falling frequency
  for (int i = 0; i < 2; i++) {
    tone(buzzerPin, 1000 - (i * 200));  // Fall in tone frequency
    delay(600);  // Buzz for 0.6 seconds (increased duration)
    noTone(buzzerPin);  // Stop buzzer
    delay(600);  // Pause for 0.6 seconds
  }

  lcd.clear();  // Clear display after the final buzzer pattern
}
