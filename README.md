# Arduino-Projects

This repository contains a collection of Arduino projects, each designed with practical applications and easy implementation in mind. The goal is to provide useful, well-documented code and explanations to help you set up and understand each project quickly.

## Projects Overview

### Project 1 - Temperature and Humidity Sensor  
**Folder**: `Temp & Humidity Sensor`  
In this project, you'll learn how to use the DHT11 sensor to measure temperature and humidity levels. The project includes:  
- The Arduino code (`Temp_Humidity_Sensor_1.ino`)  
- A detailed `README.md` explaining the components used, wiring connections, and how the code works.

### Project 2 - Ultrasonic Distance Sensor  
**Folder**: `Ultrasonic Distance Sensor`  
In this project, you'll learn how to use an HC-SR04 ultrasonic sensor to measure the distance to an object and display it on an I2C LCD screen. The project includes:  
- The Arduino code (`Ultrasonic_Distance_Sensor.ino`)  
- A detailed `README.md` explaining the components used, wiring connections, and how the code works.

### Project 3 - People Counter Using Ultrasonic Sensor  
**Folder**: `Ultrasonic People Counter`  
This project uses an HC-SR04 ultrasonic sensor to count the number of people passing through a specific area. The project includes:  
- The Arduino code (`Ultrasonic_People_Counter_3.ino`)  
- A detailed `README.md` explaining the components used, wiring connections, and how the code works.

### Project 4 - Morse Code Translator  
**Folder**: `Morse Code Translator`  
In this project, you’ll learn how to implement a Morse code translator using an Arduino and buttons. The project includes:  
- The Arduino code (`Morse_Code_Translator_4.ino`)  
- A detailed `README.md` explaining the components used, wiring connections, how the code works, and how to input Morse code for translation.

### Project 5 - Timer Display with Active Buzzer  
**Folder**: `Timer Display Active Buzzer`  
In this project, you’ll create a countdown timer with minute and second adjustments using three buttons. The time is displayed on an I2C LCD display. An active buzzer signals when the timer reaches zero, and the display shows a “Timer Over!” message. The project includes:  
- The Arduino code (`Timer_Display_Active_5.ino`)  
- A detailed `README.md` explaining the components used, wiring connections, how the code works, and how to control the timer and buzzer.

### Project 6 - Timer Display with Passive Buzzer  
**Folder**: `Timer Display Passive Buzzer`  
This project is similar to the Timer Display with Active Buzzer but replaces the active buzzer with a passive buzzer. When the timer reaches zero, the passive buzzer plays a melody. The project includes:  
- The Arduino code (`Timer_Display_Passive_6.ino`)  
- A detailed `README.md` explaining the components used, wiring connections, how the code works, and how the passive buzzer creates a melody when the timer ends.

### Project 7 - IR Decoder  
**Folder**: `IR Decoder`  
This project demonstrates how to use an IR receiver to decode signals from an IR remote control. The project includes:  
- The Arduino code (`IR_Decoder_7.ino`)  
- A detailed `README.md` explaining how to capture and decode IR signals along with wiring instructions.

### Project 8 - Motion-Activated IR Remote  
**Folder**: `Motion-Activated IR Remote`  
This project uses a motion sensor to detect movement and sends an IR signal to control a device (e.g., a TV). The project includes:  
- The Arduino code (`IR_Motion_TV_8.ino`)  
- A detailed `README.md` explaining the components used, wiring connections, and how motion triggers the IR signal.

### Project 9 - Button Tester  
**Folder**: `Button Tester`  
A simple project to test a push button connected to an Arduino. It prints a message to the Serial Monitor when the button is pressed. The project includes:  
- The Arduino code (`Button_Test_9.ino`)  
- A detailed `README.md` explaining the wiring (with the button connected to digital pin 2 using an internal pull-up) and how the code detects button presses.

### Project 10 - Updated IR Decoder (IRremote 4.x)  
**Folder**: `Updated_4.x_IR_Decoder_10`  
This updated project uses version 4.x of the `IRremote` library to read and decode signals from an IR remote, outputting the received signal in hexadecimal format to the Serial Monitor. The project includes:  
- The Arduino code (`Updated_IR_Decoder_10.ino`)  
- A detailed `README.md` explaining the components used, wiring (IR receiver on digital pin 11), and how the new library functions with `IrReceiver.begin()` and `IrReceiver.decode()`.

### Project 11 - Ultrasonic Radar With GUI  
**Folders**:  
- `Ultrasonic_radar_11`  
- `Ultrasonic_radar_GUI_11`  

This project integrates an ultrasonic sensor mounted on a servo to create a radar system that continuously scans its environment. The Arduino code measures distances using an HC-SR04 sensor and transmits angle–distance pairs over Serial. The Processing-based GUI receives this data and visualizes it as a radar display with a sweeping line, while full red lines indicate object detection. The project includes:  
- The Arduino code (`Ultrasonic_Radar_11.ino`)  
- The Processing GUI code (`Ultrasonic_Radar_GUI_11.pde`)  
- A detailed `README.md` explaining the components used, wiring connections, code logic, and setup instructions for both the Arduino and GUI.

### Project 12 - Soil Moisture Test  
**Folder**: `soil_moisture_test`  
Test and calibrate your soil moisture sensor. This project includes:  
- The Arduino code (`soil_moisture_test.ino`) that reads the analog moisture level and prints it to the Serial Monitor.  
- A `README.md` explaining wiring, code usage, and calibration guidelines.

### Project 13 - Automatic Irrigation System With GUI
**Folders**:  
- `Auto_irrigation_system`  
- `Auto_irrigation_system_GUI`  

Automatically water your plants based on soil moisture and environmental conditions. This project includes:  
- The Arduino sketch (`Auto_irrigation_system.ino`) with DHT11, soil moisture sensor, relay-controlled pump, and passive buzzer alerts.  
- A Python logging script (`log_irrigation.py`) that captures Serial data and writes it to a CSV.  
- A Processing-based GUI (`Auto_irrigation_system_GUI/Irrigation_GUI.pde`) for real-time visualization of moisture, temperature, and humidity.  
- `README.md` files in each folder detailing wiring, code operation, and setup steps.

---

This repository is designed to be a comprehensive resource for learning and implementing a variety of Arduino projects with complete documentation and code examples.

Happy building!
