# Project 9 - Button Tester

This simple project uses an **Arduino Uno** and a **push button** to detect and display button presses in the Serial Monitor. It’s a great beginner-friendly way to test the functionality of a button and understand how digital inputs work with Arduino.

## Components Used
- Arduino Uno  
- Push Button  
- Breadboard  
- Jumper Wires  

## Pin Connections
1. **Button**:
   - One leg of the button connects to **digital pin 2** on the Arduino.
   - The other leg is connected to **GND** through the breadboard.
   - **No external resistor needed** as the code uses the Arduino’s **internal pull-up resistor**.

## How It Works
The button is connected to **digital pin 2** using **INPUT_PULLUP mode**, which means the input reads **HIGH** when the button is not pressed, and **LOW** when it is pressed. The program continuously monitors the state of the button and prints **“Button pressed!”** to the Serial Monitor each time the button is detected as pressed.

## Instructions
1. Connect the button to pin 2 and ground as described above.
2. Upload the Arduino sketch to your Arduino board.
3. Open the Serial Monitor in the Arduino IDE.
4. Press the button — the message **“Button pressed!”** should appear in the Serial Monitor each time.

## Code Explanation
- `pinMode(buttonPin, INPUT_PULLUP);`: Enables the internal pull-up resistor to avoid the need for an external one.
- `digitalRead(buttonPin)`: Reads the button state; if LOW, the button is pressed.
- `Serial.println("Button pressed!");`: Outputs a message when the button is detected as pressed.
- `delay(200);`: Adds a small delay to prevent spamming the Serial Monitor with repeated messages.

## Troubleshooting
- **Button not responding?**
  - Make sure the button is wired correctly and the right pin number is used.
  - Check for a loose connection or misaligned button on the breadboard.

- **Output appearing constantly?**
  - If you’re seeing constant “Button pressed!” messages, double-check the wiring. The button should only connect to GND when pressed.

## Improvements
- Add an LED to visually indicate a button press.
- Use multiple buttons to test input detection on different pins.
- Add debounce logic or software debounce to avoid false triggers.
