#define LED 13
#define BUTTON 12

void setup() {
  pinMode(LED,OUTPUT);
  pinMode(BUTTON,INPUT);
}

void loop() {
  int pushed = digitalRead(BUTTON);
  if(pushed){
    analogWrite(LED,255);
  }
  else
  {
    
  }
}
