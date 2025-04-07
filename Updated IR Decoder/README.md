# Project 10 - Updated IR Decoder (IRremote 4.x)

This project demonstrates how to use an **IR receiver** and the **updated IRremote 4.x library** to decode infrared (IR) signals from a remote control. When a button is pressed on the remote, the IR receiver captures and prints the hexadecimal signal to the Serial Monitor.

## Components Used
- Arduino Uno  
- IR Receiver (e.g., TSOP382 or similar)  
- IR Remote  
- Jumper Wires  
- Breadboard  

## Libraries Needed
- **IRremote 4.x**: Install via Arduino Library Manager. This project uses the updated version of the IRremote library.

## Pin Connections
1. **IR Receiver**:
   - **Signal pin** → **Pin 11** on Arduino  
   - **VCC** → **5V**  
   - **GND** → **GND**  

## How It Works
The IR receiver detects IR signals sent by any standard IR remote. When the Arduino receives the signal, it decodes and prints it in **hexadecimal format** to the Serial Monitor.

The code uses the `IrReceiver.begin()` function to initialize the receiver and `IrReceiver.decode()` to read incoming signals.

## Instructions
1. Install the IRremote 4.x library via the Arduino Library Manager.
2. Connect the IR receiver to the Arduino as described above.
3. Upload the sketch to your Arduino.
4. Open the Serial Monitor at **9600 baud rate**.
5. Point a remote at the receiver and press any button — the hex value of the signal should appear in the Serial Monitor.

## Code Explanation
- `IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);`: Initializes the receiver and enables feedback via onboard LED if available.
- `IrReceiver.decode()`: Checks if a new IR signal is received.
- `IrReceiver.decodedIRData.decodedRawData`: Holds the raw decoded signal.
- `IrReceiver.resume()`: Prepares the receiver to receive the next signal.

## Troubleshooting
- **No signal detected?**
  - Ensure correct wiring (especially pin 11 for signal).
  - Make sure the IR remote has working batteries.
  - Confirm the correct version of the IRremote library is installed.

- **Wrong signal output?**
  - Use the latest IRremote library and ensure you’re using `decodedRawData` for raw hex output.

## Improvements
- Add support for specific IR codes to control devices (TV, lights, fans, etc.).
- Display the decoded signal on an LCD instead of the Serial Monitor.
- Add a button to clear previous values from the screen.
