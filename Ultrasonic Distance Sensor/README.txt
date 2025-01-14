# HC-SR04 Ultrasonic Distance Sensor with LCD Display Project

This project uses an **Arduino Uno**, an **HC-SR04 Ultrasonic Distance Sensor**, and an **I2C LCD 1602 Screen** to display real-time distance measurements.

## Libraries Needed
1. **LiquidCrystal_I2C library**: Install the LiquidCrystal_I2C library to communicate with the LCD screen.

## Pin Connections
1. **HC-SR04 Ultrasonic Sensor**:
   - **VCC**: Connect to the **5V rail** on the breadboard (powered by the Arduino).
   - **GND**: Connect to the **GND rail** on the breadboard.
   - **TRIG**: Connect to **Arduino pin 3**.
   - **ECHO**: Connect to **Arduino pin 4**.

2. **I2C LCD Screen**:
   - **VCC**: Connect to the **5V rail** on the breadboard.
   - **GND**: Connect to the **GND rail** on the breadboard.
   - **SDA**: Connect to **Arduino pin A4**.
   - **SCL**: Connect to **Arduino pin A5**.

3. **Breadboard Connections**:
   - Use **staple wires** to organize the connections between components and the breadboard rails.
   - Connect **5V** from the Arduino to the **5V rail** on the breadboard.
   - From the **5V rail**, connect **5V** to the ultrasonic sensor and LCD screen to power them.
   - Connect **GND** from the Arduino to the **GND rail** on the breadboard.

## How It Works
The **HC-SR04 Ultrasonic Distance Sensor** sends out a pulse when triggered, and the sensor measures the time it takes for the pulse to return. The Arduino calculates the distance based on the time it takes for the pulse to return and displays the distance in centimeters on the LCD screen. The sensor and display are powered using the **5V** rail from the Arduino.

## Instructions
1. Install the required libraries in the Arduino IDE:
   - **LiquidCrystal_I2C** for the LCD.
2. Connect the components as per the pin configuration.
3. Upload the Arduino sketch to your board.
4. The LCD will display the real-time distance measured by the ultrasonic sensor.

## Notes
- Ensure that the wiring is correct, and the components are securely connected.
- The LCD might appear faint if the contrast is too low. Adjust the contrast using the potentiometer on the I2C module if necessary.
- The sensor will display distance values in centimeters on the LCD, updating every 500ms.

