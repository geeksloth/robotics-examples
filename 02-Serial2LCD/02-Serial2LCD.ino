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
    lcd.setCursor(0,0);
    String msg = Serial.readString();
    lcd.print(msg);
  }
}
