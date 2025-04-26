<!-- soil_moisture_test/README.md -->

# Project 12: Soil Moisture Test

This project helps you test and calibrate a soil moisture sensor by printing real-time moisture readings to the Serial Monitor.

## Files

- **`soil_moisture_test.ino`**  
  Arduino sketch that reads the analog moisture value (0–1023), maps it to a 0–100 % scale, and prints `moisturePct\n` every second.

## Components

- **Soil moisture sensor module** (probe + analog output)
- **Arduino Uno** (or compatible)
- **Jumper wires** and **breadboard**

## Wiring

1. **Sensor VCC** → Arduino **5 V**  
2. **Sensor GND** → Arduino **GND**  
3. **Sensor AO**  → Arduino **A0**

## Usage

1. Open the Arduino IDE.  
2. Select the correct board and port.  
3. Upload `soil_moisture_test.ino`.  
4. Open the **Serial Monitor** at **9600 baud**.  
5. Observe lines like:
