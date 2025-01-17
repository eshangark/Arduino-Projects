#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD with I2C address (usually 0x27 or 16, 2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Button pins
const int dotButton = 2;
const int dashButton = 3;
const int enterButton = 4;

// Morse code string and translation table
String morseCode = "";
String translatedText = "";

// Morse code lookup table (Including digits 0-9)
String morseLookup[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", // A-Z
  "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."  // 0-9
};

char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";  // Include digits

unsigned long lastEnterTime = 0;
unsigned long enterDelay = 500; // Max delay for double press detection
bool waitingForSecondPress = false;

void setup() {
  // Initialize the LCD
  lcd.init();
  lcd.backlight();

  // Display "Morse Code Translator" for 5 seconds
  lcd.setCursor(0, 0);
  lcd.print("Morse Code");
  lcd.setCursor(0, 1);
  lcd.print("Translator");
  delay(5000); // Display for 5 seconds
  lcd.clear();  // Clear screen after 5 seconds

  // Set up button pins
  pinMode(dotButton, INPUT_PULLUP);
  pinMode(dashButton, INPUT_PULLUP);
  pinMode(enterButton, INPUT_PULLUP);

  // Display instructions for 2 seconds
  lcd.setCursor(0, 0);
  lcd.print("Enter Morse...");
  delay(2000);
  lcd.clear();  // Clear screen after instructions
}

void loop() {
  // Check for dot button press
  if (digitalRead(dotButton) == LOW) {
    morseCode += ".";
    lcd.setCursor(0, 1);
    lcd.print("Morse: " + morseCode);  // Print Morse on the bottom row
    delay(300); // Debounce
  }

  // Check for dash button press
  if (digitalRead(dashButton) == LOW) {
    morseCode += "-";
    lcd.setCursor(0, 1);
    lcd.print("Morse: " + morseCode);  // Print Morse on the bottom row
    delay(300); // Debounce
  }

  // Check for enter button press
  if (digitalRead(enterButton) == LOW) {
    unsigned long currentMillis = millis();

    // If the button was pressed within the defined delay, treat it as a double press for a space
    if (waitingForSecondPress && (currentMillis - lastEnterTime <= enterDelay)) {
      // Add space to translated text and clear Morse code
      translatedText += " ";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(translatedText);  // Show translated text with space
      morseCode = "";  // Clear Morse code for next word
      waitingForSecondPress = false;  // Reset
    } else {
      // Single press, translate Morse code to a letter or number
      char translatedChar = translateMorse(morseCode);

      lcd.clear();  // Clear both rows of the LCD

      if (translatedChar != '\0') {
        translatedText += translatedChar;  // Add to the translated text
        lcd.setCursor(0, 0);  // Top row for translated text
        lcd.print(translatedText);  // Show translated text
      } else {
        lcd.setCursor(0, 0);  // Top row for error message
        lcd.print("Invalid Morse");  // Invalid Morse code
      }

      // Clear the Morse code for the next character input
      morseCode = "";  // Clear Morse input for the next letter

      waitingForSecondPress = true;  // Wait for second press for space
    }

    lastEnterTime = currentMillis;  // Store the current time of press
    delay(300); // Debounce
  }
}

// Function to translate Morse code into a character
char translateMorse(String code) {
  for (int i = 0; i < 36; i++) {  // Loop through 26 letters + 10 digits
    if (morseLookup[i] == code) {
      return alphabet[i];  // Return corresponding letter or digit from alphabet
    }
  }
  return '\0'; // Return null character if not found
}
