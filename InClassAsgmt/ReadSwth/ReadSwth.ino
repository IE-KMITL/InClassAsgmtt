int sw = 25;
int LED = 26;
void setup() {
  pinMode(sw, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop() {
  int a = digitalRead(sw);
  if (a==1){
    digitalWrite(LED,0);
  }
  else {
    digitalWrite(LED,1);
  }
                    
}
