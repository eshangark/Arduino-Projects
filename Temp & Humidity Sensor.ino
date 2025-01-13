#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Define I2C LCD address and initialize
LiquidCrystal_I2C lcd(0x27, 16, 2); // Change 0x27 to your I2C address if needed

// DHT sensor settings
#define DHTPIN 2    // DHT11 data pin connected to Arduino pin 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);
  Serial.println("Initializing...");

  // Initialize the DHT sensor
  dht.begin();
  
  // Initialize the LCD screen
  lcd.init();
  lcd.backlight();
  delay(2000);  // Delay to see startup message
  lcd.clear();
}

void loop() {
  // Read temperature and humidity from DHT11
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  
  // Check if readings failed
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    lcd.setCursor(0, 0);
    lcd.print("DHT11 Error");
    delay(2000);
    lcd.clear();
    return;
  }

  // Print readings to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Display "The temperature and humidity is..." on the first row
  lcd.setCursor(0, 0); // Set to first row
  lcd.print("The Temperature");

  lcd.setCursor(0, 1); // Set to second row
  lcd.print("And Humidity is:");

  delay(4000); // Pause before displaying readings
  
  // Display temperature and humidity readings on the LCD
  lcd.clear();
  lcd.setCursor(0, 0); // Set to first row
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" *C");

  lcd.setCursor(0, 1); // Set to second row
  lcd.print("Hum: ");
  lcd.print(humidity);
  lcd.print(" %");
  
  delay(15000); // Update every 15 seconds
}
