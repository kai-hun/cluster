#include <Servo.h>
Servo servo;

int pos = 0;
char in;
int PinA = 2;
int PinB = 3;
int enable = 11;

void setup() {
  Serial.begin(9600);
  servo.attach(9);
  pinMode(PinA, OUTPUT);
  pinMode(PinB, OUTPUT);
  pinMode(enable, OUTPUT);
  analogWrite(enable,250);
}
void Forward(){
  servo.write(45);
  digitalWrite(PinA, LOW);
  digitalWrite(PinB, HIGH);
}
void Backward(){
  servo.write(45);
  digitalWrite(PinA, HIGH);
  digitalWrite(PinB, LOW);
}
void Right(){
  servo.write(80);
}
void Left(){
  servo.write(0);
}
void Stop(){
  servo.write(45);
  digitalWrite(PinA, LOW);
  digitalWrite(PinB, LOW);
}
void loop(){
   if (Serial.available()) {
    in = Serial.read();   
    switch(in){
      case 'F': Forward(); delay(200);break;
      case 'R': Right(); break;
      case 'S': Stop(); delay(200);break;
      case 'L': Left(); break;
      case 'B': Backward(); delay(200);break;
    }
  }
}
