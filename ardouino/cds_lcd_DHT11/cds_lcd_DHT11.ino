#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SimpleDHT.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int sensorPin = A0; // 조도 센서 연결 핀
int sensorValue = 0; // 측정된 조도 값
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);

void setup() {
  lcd.init();
  lcd.init();
  lcd.backlight();
}

void loop() {
 sensorValue = analogRead(sensorPin); // 조도 센서 값을 측정
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.print(SimpleDHTErrCode(err));
    Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
    return;
  }
 lcd.setCursor(0,0);
 lcd.print("cds : ");
 lcd.print(sensorValue);
 lcd.setCursor(0,1);
 lcd.print("T : ");
 lcd.print((int)temperature);
 lcd.print(", H : ");
 lcd.print((int)humidity);
 delay(1000);
}
