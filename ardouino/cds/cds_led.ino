int sensorPin = A0; // 조도 센서 연결 핀
int sensorValue = 0; // 측정된 조도 값

void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  Serial.begin(9600); // 시리얼 통신 시작
}

void loop() {
  sensorValue = analogRead(sensorPin); // 조도 센서 값을 측정
  if(sensorValue < 400)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
  }
  else
  digitalWrite(3, HIGH);
  digitalWrite(2, LOW);
  Serial.print("조도 값: ");
  Serial.println(sensorValue); // 측정된 조도 값을 시리얼 모니터에 출력
}
