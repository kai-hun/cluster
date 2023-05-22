int PinA = 2;
int PinB = 3;
int enable = 11;
  
void setup() {
  pinMode(PinA, OUTPUT);
  pinMode(PinB, OUTPUT);
  pinMode(enable, OUTPUT);
  analogWrite(enable,1000);
}

void loop() {
  digitalWrite(PinA,LOW);
  digitalWrite(PinB,HIGH);
  delay(1000);
  digitalWrite(PinB,LOW);
  digitalWrite(PinA,HIGH);
  delay(1000);
}
