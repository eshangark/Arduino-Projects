#include <IRremote.h>

const int RECV_PIN = 11; // Signal pin for the IR Receiver

void setup() {
  Serial.begin(9600);
  
  // Initialize the IR Receiver on the specified pin
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK);
  Serial.println("IR Receiver is ready...");
}

void loop() {
  if (IrReceiver.decode()) {
    // Print received data in hexadecimal
    Serial.print("Received IR Signal: 0x");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);

    IrReceiver.resume(); // Prepare for the next signal
  }
}
