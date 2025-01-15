# People Counter Using Ultrasonic Sensor

This project uses an **Arduino Uno**, an **HC-SR04 Ultrasonic Sensor**, and an **I2C LCD 1602 Display** to count the number of people passing through a specific area and display the count in real-time.

## Libraries Needed
1. **LiquidCrystal_I2C library**: Install the `LiquidCrystal_I2C` library to communicate with the LCD screen.

## Pin Connections
1. **HC-SR04 Ultrasonic Sensor**:
   - VCC: Connect to the **5V rail** on the breadboard (powered by the Arduino).
   - GND: Connect to the **GND rail** on the breadboard.
   - TRIG: Connect to **Arduino pin 3**.
   - ECHO: Connect to **Arduino pin 4**.

2. **I2C LCD 1602 Display**:
   - VCC: Connect to the **5V rail** on the breadboard.
   - GND: Connect to the **GND rail** on the breadboard.
   - SDA: Connect to **Arduino pin A4**.
   - SCL: Connect to **Arduino pin A5**.

3. **Breadboard Connections**:
   - Connect the **5V pin** from the Arduino to the **5V rail** on the breadboard.
   - From the **5V rail**, connect **5V** to the HC-SR04 sensor and LCD display to power them.

## How It Works
The HC-SR04 ultrasonic sensor sends out a sound pulse and measures the time it takes for the pulse to return after bouncing off an object. This time is used to calculate the distance to the object. By frequently measuring the distance, we can detect when someone crosses the detection zone and increment the count accordingly.

The count is then displayed on an I2C LCD 1602 screen, updating in real-time. The LCD shows the number of people detected in the area.

## Instructions
1. Install the required libraries in the Arduino IDE (LiquidCrystal_I2C).
2. Connect the components as per the pin configuration.
3. Upload the Arduino sketch (`People_Counter.ino`) to your board.
4. The LCD will show the current count of people detected.

## Notes
Ensure that the wiring is correct and the components are securely connected. The sensor should have a clear line of sight to detect objects accurately. If needed, adjust the threshold for detection to fine-tune the performance. 

Also, make sure the contrast on the LCD is set correctly, as it may appear faint if not adjusted.

