#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello, KKU!");
  lcd.setCursor(0,1);
  lcd.print("CollegeOfComputing");
}

void loop() {
  if (Serial.available()) {
    String msg = Serial.readString();
    int commaIndex = msg.indexOf(',');
    if (commaIndex != -1) {
      String firstPart = msg.substring(0, commaIndex);
      String secondPart = msg.substring(commaIndex + 1);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(firstPart);
      lcd.setCursor(0, 1);
      lcd.print(secondPart);
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(msg);
    }
  }
}
