#ifndef __MORSETRANSLATER_H__
#define __MORSETRANSLATER_H__

#include <string>

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

#endif
