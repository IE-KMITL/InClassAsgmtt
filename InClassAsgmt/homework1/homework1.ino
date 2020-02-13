int sensor_l = 26;
int LED_R = 27;
int sensor_r = 18;
const int trigPin = 13;
const int echoPin = 23;
long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(sensor_l, INPUT);
  digitalWrite(LED_BUILTIN, 0);
  digitalWrite(sensor_l, 0); 

  pinMode(LED_R, OUTPUT);
  pinMode(sensor_r, INPUT);
  digitalWrite(LED_R, 0);
  digitalWrite(sensor_r, 0);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); //ultrasonic
}

void loop() {
  bool a = digitalRead(sensor_l);
  bool b = digitalRead(sensor_r);
  if (!a) {
    digitalWrite(LED_BUILTIN, HIGH);
    if (!b) {
      digitalWrite(LED_R, HIGH);
    }
    else  {
      digitalWrite(LED_R, LOW);
    }
  }
  else  {
    digitalWrite(LED_BUILTIN, LOW);
    if (!b) {
      digitalWrite(LED_R, HIGH);
    }
    else  {
      digitalWrite(LED_R, LOW);
    }
  }
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  // put your main code here, to run repeatedly:
  if (distance < 20) {
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(LED_R, LOW);
  }
  else if (distance > 40)
  { digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(LED_R, HIGH);
  }
  else 
  {
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(LED_R, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(LED_R, LOW);
    delay(200);
  }
  delay(50);
}
