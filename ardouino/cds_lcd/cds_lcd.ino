#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int sensorPin = A0; // 조도 센서 연결 핀
int sensorValue = 0; // 측정된 조도 값

void setup() {
  lcd.init();
  lcd.init();
  lcd.backlight();
}

void loop() {
 sensorValue = analogRead(sensorPin); // 조도 센서 값을 측정
 lcd.setCursor(6,0);
 lcd.setCursor(0,0);
 lcd.print("cds : ");
 lcd.print(sensorValue);
 delay(1000);
 lcd.clear();
}
