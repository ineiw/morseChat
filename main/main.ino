#include <MorseTranslater.h>

#define LED 13
#define BUTTON 22

#define DOT_TIME 200
#define BEEP_TIME 700
#define TRANSE_TIME 1000
#define SEND_TIME 1500

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_MOSI  33
#define OLED_CLK   32
#define OLED_DC    35
#define OLED_CS    31
#define OLED_RESET 34

Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

//변수 설정

void setup() {
  pinMode(LED,OUTPUT);
  pinMode(BUTTON,INPUT);
  Serial.begin(9600);
  setupOled();
}

float cur = millis();
float old = cur;

float pushedTime = 0;
float notPushedTime = 0;

MorseTranslater morseTranslater = MorseTranslater();

String code = "";
String text = "";
String textAndCode = "";

bool EnKoToggle = true;

void setupOled(){
  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();//화면 초기화
  display.setTextSize(1);//글자 사이즈 설정
  display.setTextColor(WHITE);//글자 색상 설정
  display.setCursor(0,0);//글자가 표시될 위치 설정
  stringDisplay("hello world");
}

void loop() {
  float deltaTime = getDeltaTime();
  int pushed = digitalRead(BUTTON);



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
    if(code == "......"){
      EnKoToggle = !EnKoToggle;
    }else if(code == "-...-"){
      text.remove(text.length()-1);
    }
    else{
      text += morseTranslater.MorseToText(code,EnKoToggle);
    }
    code = "";
  }
  textAndCode = text + code;
  stringDisplay(textAndCode);
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

void stringDisplay(String text){
  display.clearDisplay();//화면 초기화
  display.setCursor(0,0);//글자가 표시될 위치 설정
  display.println(text);
  display.display();
}