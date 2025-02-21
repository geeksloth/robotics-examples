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
      int lineNumber = msg.substring(0, commaIndex).toInt();
      String text = msg.substring(commaIndex + 1);
      lcd.setCursor(0, lineNumber);
      lcd.print("                    ");
      lcd.setCursor(0, lineNumber);
      lcd.print(text);
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(msg);
    }
  }
}
