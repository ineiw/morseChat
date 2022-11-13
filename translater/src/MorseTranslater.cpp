#include <iostream>
#include "MorseTranslater.h"

using namespace std;

string MorseTranslater::MorseToText(string code){

  string result = "";
  
  for(int i=0;i<MORSE_IDX_LENGTH;i++){
    if(codeTable[i][1] == code){
      result = codeTable[i][0];
      break;
    }
  }

  return result;
}

string MorseTranslater::TextToMorse(string text){
  
  string result = "";

  for(int i=0;i<MORSE_IDX_LENGTH;i++){
    if(codeTable[i][0] == text){
      result = codeTable[i][1];
      break;
    }
  }

  return result;
}
