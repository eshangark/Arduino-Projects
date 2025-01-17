# Morse Code Translator Project

This project uses an **Arduino Uno**, **push buttons**, and an **I2C LCD Screen** to input Morse code and translate it into text, displaying it on the LCD. It allows users to input Morse code by pressing buttons for dots and dashes, and pressing the Enter button to translate the code into a letter or number.

## Libraries Needed
1. **LiquidCrystal_I2C library**: Install the LiquidCrystal_I2C library to communicate with the I2C LCD screen.

## Pin Connections
1. **Dot Button** (Pin 2):
   - This button will be used to input a dot (".") in Morse code.
   
2. **Dash Button** (Pin 3):
   - This button will be used to input a dash ("-") in Morse code.
   
3. **Enter Button** (Pin 4):
   - This button will be used to submit the Morse code for translation into a letter or number.

4. **I2C LCD Screen**:
   - **VCC**: Connect to the **5V rail** on the breadboard.
   - **GND**: Connect to the **GND rail** on the breadboard.
   - **SDA**: Connect to **Arduino pin A4**.
   - **SCL**: Connect to **Arduino pin A5**.

5. **Breadboard Connections**:
   - Connect the **5V pin** from the Arduino to the **5V rail** on the breadboard.
   - Connect the **GND pin** from the Arduino to the **GND rail** on the breadboard.

## How It Works
In this project, you use three buttons: one for a dot, one for a dash, and one to submit the Morse code. When a button is pressed, the corresponding symbol is added to the input string. When the Enter button is pressed, the Morse code is translated into a letter or number, and the LCD screen displays the translated text. The program supports the translation of both letters (A-Z) and numbers (0-9).

The project works by storing the Morse code sequence in a string and translating it into the corresponding letter or number using a predefined Morse code lookup table. After translation, the letter is displayed on the LCD screen. A double press of the Enter button adds a space to the translated text.

## Instructions
1. Install the required libraries in the Arduino IDE (LiquidCrystal_I2C).
2. Connect the components as per the pin configuration.
3. Upload the Arduino sketch to your Arduino board.
4. Press the **dot** button for a dot, the **dash** button for a dash, and the **Enter** button to translate the Morse code into a letter or number.
5. The LCD will display the translated text as you input the Morse code.

## Code Explanation
- **Morse Code Input**: The dot and dash buttons are used to input Morse code symbols. Each press appends a symbol to the `morseCode` string.
- **Translation**: When the Enter button is pressed, the Morse code is translated into its corresponding letter or number by comparing the `morseCode` string to a predefined lookup table (`morseLookup`).
- **Space Detection**: A double press of the Enter button is used to detect a space between words and add a space to the translated text.

## Notes
- Ensure that the wiring is correct and the components are securely connected.
- You can adjust the debounce time for button presses if needed by modifying the delay values in the code.
- The LCD might appear faint if the contrast is too low. Adjust the contrast using the potentiometer on the I2C module if necessary.

## Troubleshooting
1. **Button presses not detected**: Make sure the buttons are connected properly and the Arduino pins are configured correctly. Also, ensure the buttons are not stuck or malfunctioning.
2. **LCD not displaying properly**: Check the connections to the LCD, especially the SDA and SCL pins. Also, adjust the contrast on the LCD module.
3. **Morse code not translating correctly**: Verify that the Morse code lookup table (`morseLookup[]`) is correctly defined and matches the Morse code symbols.

## Improvements
- Add support for longer words by improving the handling of spaces and punctuation.
- Integrate a speaker or buzzer to provide audible feedback for each dot and dash press.
