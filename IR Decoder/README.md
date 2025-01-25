# IR Decoder Project

This project demonstrates how to use an **IR Receiver** to decode signals from an **IR Remote Control**. The decoded signal can be displayed on the serial monitor or used to trigger actions based on the received IR signals.

## Libraries Needed
1. **IRremote library**: Install the IRremote library to communicate with the IR receiver.

## Pin Connections
1. **IR Receiver**:
   - Connect the **VCC** pin to the **5V rail**.
   - Connect the **GND** pin to the **GND rail**.
   - Connect the **OUT** pin to **Arduino pin 2** (or any other digital pin if required).

## How It Works
This project reads IR signals sent from an IR remote control and decodes them. The IR signals are printed to the serial monitor for display. The output includes the decoded values for each button press on the remote control, which can be used to trigger further actions.

## Instructions
1. Install the required libraries in the Arduino IDE.
2. Connect the components as per the pin configuration.
3. Upload the Arduino sketch (`IR_Decoder_7.ino`) to your board.
4. Open the serial monitor and press buttons on the IR remote. You will see the decoded signal printed to the serial monitor.

## Notes
- Make sure the IR receiver is aligned and positioned correctly to receive the signals.
- The decoded values can be used to control other devices or trigger actions in your Arduino projects.
- The IR receiver must be placed facing the remote control with no obstructions.
