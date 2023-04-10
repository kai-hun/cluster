int redPin = 9;
int greenPin = 10;
int bluePin = 11;
int redValue = 0;
int greenValue = 0;
int blueValue = 0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
  redValue++;
  greenValue++;
  blueValue++;

  if (redValue > 255) {
    redValue = 0;
  }
  if (greenValue > 255) {
    greenValue = 0;
  }
  if (blueValue > 255) {
    blueValue = 0;
  }
  
  delay(10);
}
