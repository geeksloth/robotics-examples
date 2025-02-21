#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

int led_red = 13;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello, KKU!");
  lcd.setCursor(0,1);
  lcd.print("CollegeOfComputing");

  pinMode(led_red, OUTPUT);
  digitalWrite(led_red, LOW);
}

void loop() {
  if (Serial.available()) {
    String msg = Serial.readString();
    int commaIndex = msg.indexOf(',');
    if (commaIndex != -1) {
      int opcode = msg.substring(0, commaIndex).toInt();
      if (opcode == 0 || opcode == 1) {
        String text = msg.substring(commaIndex + 1);
        lcd.setCursor(0, opcode);
        lcd.print("                    ");
        lcd.setCursor(0, opcode);
        lcd.print(text);
      } else if (opcode == 2) {
        lcd.noBacklight();
      } else if (opcode == 3) {
        lcd.backlight();
      } else if (opcode == 4) {
        digitalWrite(led_red, HIGH);
      } else if (opcode == 5) {
        digitalWrite(led_red, LOW);
      }
    }
  }
}
