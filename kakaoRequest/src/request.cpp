#include "client.h"

int main(int argc,char * argv[]){
  string auth = string(argv[1]);
  string text = string(argv[2]);

  string res = enter_web();
  cout << "status : " <<  parsing_status(res.data());
  return 0;
}
