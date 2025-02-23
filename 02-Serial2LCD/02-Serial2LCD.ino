#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

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
    lcd.setCursor(0,0);
    lcd.print(msg);
  }
}
