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
  //Serial.print("right1 = "); //test sensor
  //Serial.println(right1);
  //Serial.println( hc.dist() ); //test ultrasonic


    carForward(255); 
    checkSensor();
    if (state == a ) {
      carStop();
      delay(5000);
    }
    else if (state == b ) {
      ReverseRight(200);
      delay(1000);
    }
    else if (state == c) {
      ReverseLeft(200);
      delay(1000);
    }
    else if (state == d || hc.dist() <= 20) {
      carReverse(255);
      delay(500);
    }
    else if (state == e) {
      turnLeft(255);
      delay(200);
    }
    else if (state == f) {
      turnRight(255);
      delay(200);
    }
    else if (line >= 180 && line <= 185) {
      carReturn(200);
      delay(920);
    }
    else if (line >= 175 && line <= 180) {
      carForward(255);
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
