#include <Servo.h>
Servo servo;

int pos = 0;
char in;
int PinA = 2;
int PinB = 3;
int enable = 11;

void Forward(){
  servo.write(43);
  digitalWrite(PinA, LOW);
  digitalWrite(PinB, HIGH);
}
void Backward(){
  servo.write(43);
  digitalWrite(PinA, HIGH);
  digitalWrite(PinB, LOW);
}
void Right(){
  servo.write(75);
}
void Left(){
  servo.write(10);
}
void Stop(){
  servo.write(43);
  digitalWrite(PinA, LOW);
  digitalWrite(PinB, LOW);
}

void setup() {
  servo.attach(9);
  pinMode(PinA, OUTPUT);
  pinMode(PinB, OUTPUT);
  pinMode(enable, OUTPUT);
  analogWrite(enable,250);
  Forward(); delay(7000);
  Left(); delay(6800);
  Forward(); delay(6000);
  Stop();  
}

void loop(){}
