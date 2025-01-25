#include <IRremote.h>

const int recv_pin = 2;  // Pin connected to the IR receiver
IRrecv irrecv(recv_pin);  // Create an IR receiver object
decode_results results;   // Variable to store IR signal

void setup() {
  Serial.begin(9600);  // Start serial communication
  irrecv.enableIRIn(); // Start the IR receiver
  Serial.println("IR Receiver is ready");
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print("Received IR Code: ");
    Serial.print(results.value, HEX); // Print the code in hexadecimal
    Serial.println();
    
    irrecv.resume(); // Receive the next value
  }
}
