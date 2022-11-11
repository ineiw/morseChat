#include <iostream>

using namespace std;

#define MORSE_IDX_LENGTH 36

class MorseTranslater{
  private:
    string codeTable [MORSE_IDX_LENGTH][2] = {
      {"A",".-"},
      {"B","-..."},
      {"C","-.-."},
      {"D","-.."},
      {"E","."},
      {"F","..-."},
      {"G","--."},
      {"H","...."},
      {"I",".."},
      {"J",".---"},
      {"K","-.-"},
      {"L",".-.."},
      {"M","--"},
      {"N","-."},
      {"O","---"},
      {"P",".--."},
      {"Q","--.-"},
      {"R",".-."},
      {"S","..."},
      {"T","-"},
      {"U","..-"},
      {"V","...-"},
      {"W",".--"},
      {"X","-..-"},
      {"Y","-.--"},
      {"Z","--.."},
      {"1",".----"},
      {"2","..---"},
      {"3","...--"},
      {"4","....-"},
      {"5","....."},
      {"6","-...."},
      {"7","--..."},
      {"8","---.."},
      {"9","----."},
      {"0","-----"},
    };
  public:
    string MorseToText(string code);
    string TextToMorse(string text);
};

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

int main(int argc,char * argv[]){

  string inputCode = string(argv[1]);
  string inputText = string(argv[2]);

  MorseTranslater morseTranslater = MorseTranslater();

  string resultText = morseTranslater.MorseToText(inputCode);
  string resultCode = morseTranslater.TextToMorse(inputText);

  cout << inputCode + " : " << resultText << "\n";
  cout << inputText + " : " << resultCode << "\n";
}
