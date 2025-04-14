# Ultrasonic Radar With GUI Project

This project integrates an HC-SR04 ultrasonic sensor mounted on a servo motor to create a radar system that continuously scans its environment. Distance measurements obtained by the sensor are sent via Serial from the Arduino to a Processing-based graphical user interface (GUI), which visualizes the data as a sweeping radar display. When an object is detected, the GUI displays a full red line from the measured point to the edge of the radar arc.

## Libraries Needed

### For Arduino
- **Servo library** (included with the Arduino IDE)

### For Processing GUI
- **Processing Serial library** (included with Processing)

## Pin Connections

### HC-SR04 Ultrasonic Sensor
- **VCC**: Connect to the Arduino's 5V pin.
- **GND**: Connect to the Arduino's GND.
- **Trigger**: Connect to Arduino digital pin **10**.
- **Echo**: Connect to Arduino digital pin **11**.

### SG90 Servo Motor
- **Signal (Orange)**: Connect to Arduino digital pin **9**.
- **Power (Red)**: Connect to the Arduino's 5V pin.
- **Ground (Brown)**: Connect to the Arduino's GND.

### Buzzer (if used)
- **Positive**: Connect to Arduino digital pin **8**.
- **Ground**: Connect to Arduino's GND.

## How It Works

1. **Arduino Side**  
   - The Arduino code rotates the servo motor between the specified sweep angles (from the calibrated center ± the sweep range).
   - At each position, the HC-SR04 ultrasonic sensor measures the distance to any object.
   - The Arduino sends these angle–distance pairs over Serial (formatted as `angle,distance`).

2. **Processing GUI**  
   - The GUI reads the Serial data and maps the incoming servo angles into display angles so that the front (straight ahead) appears at the top-center of the radar display.
   - It draws a semicircular grid with a sweeping green line indicating the current scanning angle.
   - When an object is detected, a full red line is drawn from the measured point (based on the sensor’s distance) out to the edge of the radar arc, simulating a radar “blip.”

## Instructions

1. **Hardware Setup**  
   - Wire the HC-SR04, servo, and (optionally) the buzzer according to the pin connections above.
   
2. **Arduino Code**  
   - Open the file in the `Ultrasonic_radar_11` folder (e.g., `Ultrasonic_Radar_11.ino`) using the Arduino IDE.
   - Verify that your wiring matches the pin assignments in the code.
   - Upload the sketch to your Arduino board.

3. **Processing GUI**  
   - Open the Processing sketch in the `Ultrasonic_radar_GUI_11` folder (e.g., `Ultrasonic_Radar_GUI_11.pde`) using the Processing IDE.
   - Ensure that the serial port selected in the sketch matches your Arduino connection.
   - Run the Processing sketch to launch the radar visualization.

4. **Observe**  
   - The GUI displays a radar grid with a green sweeping line. When an object is within the sensor's range, a full red line will appear from the object's measured location to the radar edge.

## Notes

- **Calibration**:  
  The mapping between the servo angles and the display angles assumes that the sensor sweeps approximately from 15° to 165° (with 90° being straight ahead). Adjust the mapping parameters in the Processing sketch if your physical setup differs.

- **Scaling**:  
  You can adjust the `maxSensorDistance` and scale factors in the Processing code to better suit your environment and sensor range.

- **Component Placement**:  
  Ensure that the ultrasonic sensor is firmly mounted on the servo and that its field of view is unobstructed for reliable distance measurements.

Happy building!
