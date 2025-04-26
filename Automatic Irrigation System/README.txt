
## 1. Hardware & Arduino Sketch

### Components

- Arduino Uno  
- Soil moisture sensor (analog)  
- DHT11 temperature/humidity sensor  
- 5 V relay module + mini water pump  
- Passive buzzer  
- Jumper wires & breadboard

### Wiring

1. **Soil sensor**:  
   - VCC → 5 V  
   - GND → GND  
   - AO  → A0  

2. **DHT11**:  
   - VCC → 5 V  
   - GND → GND  
   - DATA→ D2  

3. **Relay** (coil side):  
   - VCC → 5 V  
   - GND → GND  
   - IN  → D5  

4. **Pump & power** (switching side):  
   - Relay COM → Arduino 5 V  
   - Relay NO  → Pump +  
   - Pump –     → GND  

5. **Buzzer**:  
   - + → D9  
   - – → GND

### Sketch: `Auto_irrigation_system.ino`

- Reads moisture %, temperature, humidity  
- Prints CSV: `moisture,temperature,humidity\n` at 1 Hz  
- Runs pump + buzzer when moisture is between 5 %–60 %

## 2. Data Logger

### `log_irrigation.py`

A simple Python script that:

1. Opens your Arduino’s Serial port at 9600 baud  
2. Reads CSV lines  
3. Appends timestamped rows to `moisture_log.csv`

Run it alongside the Arduino to capture long-term logs.

## 3. GUI

Inside `Auto_irrigation_system_GUI/`, open **Processing** and load `Irrigation_GUI.pde`. It:

- Reads the same Serial lines  
- Plots moisture, temperature, humidity in real time as interactive, point-connected graphs  
- Displays a crosshair tooltip with exact values

---

### Getting Started

1. Wire up the hardware as above.  
2. Upload `Auto_irrigation_system.ino` to the Arduino.  
3. Run `python log_irrigation.py` to start logging.  
4. In Processing, open and run `Irrigation_GUI.pde` to view the live dashboard.

Happy automating!
