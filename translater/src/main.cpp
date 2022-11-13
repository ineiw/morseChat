#include <iostream>
#include "MorseTranslater.h"

int main(int argc, char * argv[]){
  
  MorseTranslater morseTranslater = MorseTranslater();

  string inputCode = string(argv[1]);
  string inputText = string(argv[2]);

  string resultText = morseTranslater.MorseToText(inputCode);
  string resultCode = morseTranslater.TextToMorse(inputText);

  cout << inputCode << " : " << resultText << "\n";
  cout << inputText << " : " << resultCode << "\n";

  return 0;
}
