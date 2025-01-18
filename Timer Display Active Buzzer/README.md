# Timer Display with Active Buzzer Project

This project uses an **Arduino Uno**, **I2C LCD 1602 Screen**, and an **Active Buzzer** to create a countdown timer. The user can input the desired time using three buttons (one for minutes, one for seconds, and one for starting the timer). When the timer reaches zero, the buzzer sounds and the LCD displays a "Timer Over!" message.

## Libraries Needed
1. **LiquidCrystal_I2C library**: Install the LiquidCrystal_I2C library to communicate with the LCD screen.

## Pin Connections
1. **Buttons**:
   - Left Button (Minute): Connect to **Arduino pin 2**.
   - Middle Button (Second): Connect to **Arduino pin 3**.
   - Right Button (Start): Connect to **Arduino pin 4**.

2. **Active Buzzer**:
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
The user adjusts the time on the LCD display using the left and middle buttons for minutes and seconds. Once the start button is pressed, the timer counts down. When the timer reaches zero, the buzzer sounds and the LCD displays a "Timer Over!" message. The buzzer pattern is composed of a series of short beeps for a specified duration.

## Instructions
1. Install the required libraries in the Arduino IDE.
2. Connect the components as per the pin configuration.
3. Upload the Arduino sketch to your board.
4. The LCD will initially show "Timer Display," then allow you to set the time. Once the timer reaches zero, the buzzer will sound and the "Timer Over!" message will appear.

## Notes
- Ensure that the wiring is correct and the components are securely connected.
- The buzzer sound duration and pattern are customizable within the code.
- The LCD contrast can be adjusted using the potentiometer on the I2C module if necessary.
