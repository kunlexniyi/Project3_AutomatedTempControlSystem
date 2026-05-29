#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Adafruit_BMP085 bmp;

const int relayPin = 8;
const float tempSetpoint = 27.0;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("System Starting.");
  delay(2000);
  lcd.clear();

  if (!bmp.begin()) {
    Serial.println("BMP180 not found!");
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!   ");
    while (1);
  }

  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);

  Serial.println("System Ready!");
  lcd.setCursor(0, 0);
  lcd.print("System Ready!   ");
  delay(1000);
  lcd.clear();
}

void loop() {
  float temperature = bmp.readTemperature();
  float pressure = bmp.readPressure() / 100.0F;

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temperature, 1);
  lcd.print("C      ");

  lcd.setCursor(0, 1);
  lcd.print("Pres:");
  lcd.print(pressure, 1);
  lcd.print("hPa  ");

  // Log to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C | Pressure: ");
  Serial.print(pressure);
  Serial.println(" hPa");

  // Control logic
  if (temperature > tempSetpoint) {
    digitalWrite(relayPin, LOW);
    Serial.println("Status: RELAY ON — Temperature High!");
    lcd.setCursor(0, 1);
    lcd.print("** RELAY ON! ** ");
  } else {
    digitalWrite(relayPin, HIGH);
    Serial.println("Status: RELAY OFF — Normal");
  }

  delay(1000);
}
