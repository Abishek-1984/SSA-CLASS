#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD setup: address 0x27, 16 columns, 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);   // Receive from ESP32-CAM
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Waiting QR...");
}

void loop() {
  if (Serial.available()) {
    String qrText = Serial.readStringUntil('\n');  // Read QR data
    int commaIndex = qrText.indexOf(',');

    String item = qrText.substring(0, commaIndex);
    String weight = qrText.substring(commaIndex + 1);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Item: " + item);
    lcd.setCursor(0, 1);
    lcd.print("Weight: " + weight);
  }
}
