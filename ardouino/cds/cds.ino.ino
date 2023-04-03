int sensorPin = A0; // 조도 센서 연결 핀
int sensorValue = 0; // 측정된 조도 값

void setup() {
  Serial.begin(9600); // 시리얼 통신 시작
}

void loop() {
  sensorValue = analogRead(sensorPin); // 조도 센서 값을 측정
  Serial.print("조도 값: ");
  Serial.println(sensorValue); // 측정된 조도 값을 시리얼 모니터에 출력
}
