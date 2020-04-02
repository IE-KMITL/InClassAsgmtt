#include <HCSR04.h>
HCSR04 hc(7, 6); //initialisation class HCSR04 (trig pin , echo pin)
int sensor_l1 = 4;
int sensor_r1 = 5;
int sensor_l2 = 12;
int sensor_r2 = 13;
int analogPin = 3;
int ia1 = 8;
int ia2 = 9;
int ib1 = 10;
int ib2 = 11;
#define maxSpd 255    // motor max speed
int line = analogRead(analogPin); //detectColor
int state;
int a;
int b;
int c;
int d;
int e;
int f;

void setup() {
  pinMode(sensor_l1, INPUT);
  digitalWrite(sensor_l1, 0);
  pinMode(sensor_r1, INPUT);
  digitalWrite(sensor_r1, 0);
  pinMode(sensor_l2, INPUT);
  digitalWrite(sensor_l2, 0);
  pinMode(sensor_r2, INPUT);
  digitalWrite(sensor_r2, 0);
  pinMode(ia1, OUTPUT);
  pinMode(ia2, OUTPUT);
  pinMode(ib1, OUTPUT);
  pinMode(ib2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  bool left1 = digitalRead(sensor_l1);
  bool right1 = digitalRead(sensor_r1);
  bool left2 = digitalRead(sensor_l2);
  bool right2 = digitalRead(sensor_r2);
  line = analogRead(analogPin); //detectColor

  carForward(255);
  if (line > 500) //ถ้าเจอเส้นดำ //ต้องลองเทสสีดำ
  {
    carReverse(255);
    delay(200);
    carReturn(200);
    delay(920);
  }
  else if (hc.dist() <= 20) {
    carForward(255);
    delay(1000);
  }
  else if (left1 == 0 ) {
    turnLeft(200);
    delay(500);
  }
  else if (right1 == 0 ) {
    turnRight(200);
    delay(500);
  }
  else if (left2 == 0) {
    ReverseLeft(200);
    delay(500);
    carReverse(255);
    delay(500);
  }
  else if (right2 == 0) {
    ReverseRight(200);
    delay(500);
    carReverse(255);
    delay(500);
  }
  else if (left2 == 0 && right2 == 0) {
    carReverse(255);
    delay(500);
  }

}

void checkSensor()
{
  if (digitalRead(sensor_l1) == 0 && digitalRead(sensor_r1) == 0 && digitalRead(sensor_l2) == 0 && digitalRead(sensor_r2) == 0 ) {
    state = a;
  }
  else if (digitalRead(sensor_l1) == 0 && digitalRead(sensor_r1) == 0 && digitalRead(sensor_l2) == 0 && digitalRead(sensor_r2) == 1) {
    state = b;
  }
  else if (digitalRead(sensor_l1) == 0 && digitalRead(sensor_r1) == 0 && digitalRead(sensor_l2) == 1 && digitalRead(sensor_r2) == 0) {
    state = c;
  }
  else if (digitalRead(sensor_l1) == 0 && digitalRead(sensor_r1) == 0 && digitalRead(sensor_l2) == 1 && digitalRead(sensor_r2) == 1) {
    state = d;
  }
  else if (digitalRead(sensor_l1) == 1) {
    state = e;
  }
  else if (digitalRead(sensor_r1) == 1) {
    state = f;
  }
}

void carStop()
{
  digitalWrite(ia1, LOW);   // motor stop
  digitalWrite(ia2, LOW);
  digitalWrite(ib1, LOW);   // motor stop
  digitalWrite(ib2, LOW);
}

void carBreak()
{
  digitalWrite(ia1, HIGH);   // motor A break
  digitalWrite(ia2, HIGH);
  digitalWrite(ib1, HIGH);   // motor B break
  digitalWrite(ib2, HIGH);
}

void carForward(int speed)
{
  digitalWrite(ia1, LOW);
  analogWrite(ia2, speed);
  digitalWrite(ib1, LOW);
  analogWrite(ib2, speed);
}

void carReverse(int speed)
{
  digitalWrite(ia2, LOW);
  analogWrite(ia1, speed);
  digitalWrite(ib2, LOW);
  analogWrite(ib1, speed);
}

void ReverseLeft(int speed)
{
  digitalWrite(ia2, LOW);
  analogWrite(ia1, 0.2 * speed);
  digitalWrite(ib2, LOW);
  analogWrite(ib1, speed);
}

void ReverseRight(int speed)
{
  digitalWrite(ia2, LOW);
  analogWrite(ia1, speed);
  digitalWrite(ib2, LOW);
  analogWrite(ib1, 0.2 * speed);
}

void turnLeft(int speed)
{
  digitalWrite(ia1, LOW);
  digitalWrite(ia2, LOW);
  digitalWrite(ib1, LOW);
  analogWrite(ib2, speed);
}

void turnRight(int speed)
{
  digitalWrite(ia1, LOW);
  analogWrite(ia2, speed);
  digitalWrite(ib1, LOW);
  digitalWrite(ib2, LOW);
}

void carReturn(int speed)
{
  digitalWrite(ia1, LOW);
  analogWrite(ia2, speed);
  digitalWrite(ib1, LOW);
  digitalWrite(ib2, LOW);
}
