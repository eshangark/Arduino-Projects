# Timer Display with Passive Buzzer Project

This project is similar to the **Timer Display with Active Buzzer**, but instead of using an active buzzer, a **Passive Buzzer** is used to produce a melody when the timer reaches zero. The project still uses an **Arduino Uno**, **I2C LCD 1602 Screen**, and the user can input time using three buttons.

## Libraries Needed
1. **LiquidCrystal_I2C library**: Install the LiquidCrystal_I2C library to communicate with the LCD screen.
2. **Tone library**: Install the Tone library to produce sounds with the passive buzzer.

## Pin Connections
1. **Buttons**:
   - Left Button (Minute): Connect to **Arduino pin 2**.
   - Middle Button (Second): Connect to **Arduino pin 3**.
   - Right Button (Start): Connect to **Arduino pin 4**.

2. **Passive Buzzer**:
   - Connect to **Arduino pin 6**.

3. **I2C LCD Screen**:
   - VCC: Connect to **5V rail**.
   - GND: Connect to **GND rail**.
   - SDA: Connect to **Arduino pin A4**.
   - SCL: Connect to **Arduino pin A5**.

4. **Breadboard Connections**:
   - Connect the **5V pin** from the Arduino to the **5V rail** on the breadboard.
   - Connect the **GND pin** from the Arduino to the **GND rail**.

## How It Works
The passive buzzer plays a melody when the timer reaches zero. The melody is created using different frequencies to generate a pleasant sound. As with the active buzzer version, the user inputs the time using the buttons, and once the time is up, the buzzer triggers, and the LCD displays a "Timer Over!" message.

## Instructions
1. Install the required libraries in the Arduino IDE.
2. Connect the components as per the pin configuration.
3. Upload the Arduino sketch to your board.
4. The LCD will initially show "Timer Display," then allow you to set the time. Once the timer reaches zero, the passive buzzer will play a melody, and the "Timer Over!" message will appear on the LCD.

## Notes
- Ensure that the wiring is correct and the components are securely connected.
- The melody can be customized in the code for the passive buzzer.
- The LCD contrast can be adjusted using the potentiometer on the I2C module if necessary.
