# DHT11 Sensor with LCD Display Project

This project uses an **Arduino Uno**, **DHT11 Temperature and Humidity Sensor**, and an **I2C LCD 1602 Screen** to display real-time temperature and humidity readings.

## Libraries Needed
1. **DHT sensor library**: Install the DHT sensor library to interface with the DHT11 sensor.
2. **LiquidCrystal_I2C library**: Install the LiquidCrystal_I2C library to communicate with the LCD screen.

## Pin Connections
1. **DHT11 Sensor**:
   - VCC: Connect to the **5V rail** on the breadboard (powered by the Arduino).
   - GND: Connect to the **GND rail** on the breadboard.
   - DATA: Connect to **Arduino pin 2**.

2. **I2C LCD Screen**:
   - VCC: Connect to the **5V rail** on the breadboard.
   - GND: Connect to the **GND rail** on the breadboard.
   - SDA: Connect to **Arduino pin A4**.
   - SCL: Connect to **Arduino pin A5**.

3. **Breadboard Connections**:
   - Connect the **5V pin** from the Arduino to the **5V rail** on the breadboard.
   - From the **5V rail**, connect **5V** to the DHT11 sensor and LCD screen to power them.

## How It Works
The DHT11 sensor measures the temperature and humidity, which are read by the Arduino. These values are then displayed on the LCD screen, which updates every 2 seconds. The sensor and display are powered using the 5V pin from the Arduino, routed through a breadboard.

## Instructions
1. Install the required libraries in the Arduino IDE.
2. Connect the components as per the pin configuration.
3. Upload the Arduino sketch to your board.
4. The LCD will show the temperature and humidity readings in real-time.

## Notes
Ensure that the wiring is correct and the components are securely connected. The LCD might appear faint if the contrast is too low. Adjust the contrast using the potentiometer on the I2C module if necessary.
