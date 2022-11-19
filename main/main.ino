#include <MorseTranslater.h>

#define LED 13
#define BUTTON 12

#define DOT_TIME 200
#define BEEP_TIME 700
#define TRANSE_TIME 1000
#define SEND_TIME 1500

void setup() {
  pinMode(LED,OUTPUT);
  pinMode(BUTTON,INPUT);
  Serial.begin(9600);
}

float cur = millis();
float old = cur;

float pushedTime = 0;
float notPushedTime  =0;

MorseTranslater morseTranslater = MorseTranslater();

String code = "";
String text = "";
void loop() {
  float deltaTime = getDeltaTime();
  int pushed = digitalRead(BUTTON);

  Serial.println(code);
  Serial.println(text);

  if(pushed){
    analogWrite(LED,255);
    pushedTime += deltaTime;
    notPushedTime = 0;
  }
  else
  {
    signalToCode(pushedTime);
    analogWrite(LED,0);
    notPushedTime += deltaTime;
    pushedTime = 0;  
  }

  if(notPushedTime > TRANSE_TIME)
  {
    text += morseTranslater.MorseToText(code);
    code = "";
  }
}

int getDeltaTime(){
  cur = millis();
  float res = cur - old;
  old = cur;
  return res;
}

void signalToCode(float pushedTime){
  if(pushedTime > 0 && pushedTime < DOT_TIME){
    code += ".";
  }
  else if(pushedTime > DOT_TIME && pushedTime < BEEP_TIME){
    code += "-";
  }
  else if(pushedTime > SEND_TIME){
    code = "";
    text = "";
  }
}
