// Soil moisture sensor test sketch
// Reads the analog value from the hydrometer and prints it to Serial Monitor

const int sensorPin = A0;  // connect your sensor's AO pin here

void setup() {
  Serial.begin(9600);      // start serial at 9600 baud
  pinMode(sensorPin, INPUT);
}

void loop() {
  int rawValue = analogRead(sensorPin);            // 0 (wet) → 1023 (dry) on most modules
  int moisturePct = map(rawValue, 1023, 0, 0, 100); // convert to 0–100% (adjust if your min/max differ)

  Serial.print("Raw value: ");
  Serial.print(rawValue);
  Serial.print("   Moisture: ");
  Serial.print(moisturePct);
  Serial.println("%");

  delay(1000); // print once per second
}
