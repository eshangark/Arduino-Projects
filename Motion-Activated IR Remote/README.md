# Motion-Activated IR Remote Project

This project uses an **Ultrasonic Distance Sensor** to detect motion by measuring changes in distance. When motion is detected, the Arduino sends an IR signal to control a device (e.g., a TV) via an **IR LED**. An **Active Buzzer** is also triggered when motion is detected.

## Libraries Needed
1. **IRremote library**: Install the IRremote library to communicate with the IR LED.

## Pin Connections
1. **Ultrasonic Sensor**:
   - **TRIG**: Connect to **Arduino pin 9**.
   - **ECHO**: Connect to **Arduino pin 10**.

2. **Active Buzzer**:
   - Connect to **Arduino pin 5**.

3. **IR LED**:
   - Connect the **anode** (long leg) of the IR LED to **Arduino pin 3**.
   - Connect the **cathode** (short leg) of the IR LED to **GND**.
   - Use a **220Ω resistor** in series with the IR LED to limit current and prevent damage to the LED.

## How It Works
This project uses an ultrasonic sensor to continuously measure the distance to an object. When the distance changes significantly (indicating motion), the Arduino triggers an IR signal to control a device (such as a TV). An active buzzer sounds to alert the user to the detected motion.

1. The ultrasonic sensor detects the distance and calculates any change that indicates motion.
2. If the motion threshold is crossed, the Arduino sends an IR signal to control a device, such as turning on the TV.
3. The buzzer emits a short sound pattern to indicate the motion detection.

## Instructions
1. Install the required libraries in the Arduino IDE.
2. Connect the components as per the pin configuration.
3. Upload the Arduino sketch (`IR_Motion_TV_8.ino`) to your board.
4. The ultrasonic sensor will continuously monitor the distance. When motion is detected, the buzzer will sound, and the IR signal will be sent to control the device (e.g., TV).

## Notes
- Ensure the ultrasonic sensor is placed in an area where it can detect motion effectively.
- The IR LED should be aligned with the device (e.g., TV) you want to control.
- The IR code used for the remote control is predefined, but you can modify it based on the device you want to control. You can capture the code using an IR receiver and modify the `irCode` variable in the code.
- The system has a debounce delay to avoid multiple detections of the same motion.
- The 220Ω resistor is essential for the proper operation of the IR LED and to prevent damage due to excessive current.
