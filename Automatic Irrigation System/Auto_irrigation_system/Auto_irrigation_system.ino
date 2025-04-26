#include <DHT.h>

// Pin definitions
#define DHTPIN       2     // DHT11 data pin
#define DHTTYPE      DHT11 // Sensor type
const int soilPin    = A0;  // Soil sensor analog pin
const int relayPin   = 5;   // Relay IN (active-LOW)
const int buzzerPin  = 9;   // Passive buzzer pin

// Moisture thresholds (0% = fully wet, 100% = fully dry)
const int MOIST_MIN = 5;    // ≥5% dryness → pump allowed
const int MOIST_MAX = 60;   // ≤60% dryness → pump allowed

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(soilPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(relayPin, HIGH);  // pump OFF
  noTone(buzzerPin);             // buzzer OFF
}

void loop() {
  // 1) Read sensors
  int rawValue     = analogRead(soilPin);
  int moisturePct  = map(rawValue, 1023, 0, 0, 100);
  float temperature= dht.readTemperature();
  float humidity   = dht.readHumidity();

  // 2) Emit CSV line: moisture,temperature,humidity
  Serial.print(moisturePct);
  Serial.print(',');
  Serial.print(temperature, 1);
  Serial.print(',');
  Serial.println(humidity, 1);

  // 3) Control pump & buzzer
  if (moisturePct >= MOIST_MIN && moisturePct <= MOIST_MAX) {
    digitalWrite(relayPin, LOW);   // pump ON
    tone(buzzerPin, 1000);         // buzzer 1 kHz
  } else {
    digitalWrite(relayPin, HIGH);  // pump OFF
    noTone(buzzerPin);             // buzzer OFF
  }

  delay(1000);
}
