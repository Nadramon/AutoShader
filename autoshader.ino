#include <Servo.h>

Servo servoLeft;
Servo servoRight;

const int pressurePin = 0;
const int lightPin = 1;
int lightVal;
int pressureVal;

void setup() {
  // put your setup code here, to run once:
  servoLeft.attach(5);
  servoRight.attach(6);
  Serial.begin(9600);
  servoLeft.write(110);
  servoRight.write(130);

}

void loop() {


  lightVal = analogRead(lightPin);
  pressureVal = analogRead(pressurePin);
  Serial.print("Light: "); //for debugging
  Serial.println(lightVal);
  Serial.print("Pressure: ");
  Serial.println(pressureVal);
  if (pressureVal > 70 && lightVal > 50) {
    servoLeft.write(110);
    servoRight.write(130);
  }
  else {
    servoLeft.write(60);
    servoRight.write(180);
  }
  

}
