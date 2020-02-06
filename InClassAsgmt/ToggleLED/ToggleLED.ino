int LED = 26;    
const int sw = 25;   
bool LED_S = 0;       
bool sw_s = 0;              


void setup()
{
  pinMode(sw, INPUT_PULLUP);   
  pinMode(LED , OUTPUT);
}

void loop()
{
  if (digitalRead(sw)==0) 
  {
    if (LED_S==0) 
    {
      LED_S = 1;
      sw_s = !sw_s; 
    }
  }
  else LED_S = 0;
  digitalWrite(LED , sw_s); 

}
