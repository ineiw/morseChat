#include "client.h"
int main(int argc,char * argv[]){

  char ok[] = "ok";
  string result = enter_web(ok,argv[2],argv[3],argv[1]);
  cout << "status : " << parsing_status(result.data());

  return 0;
}
