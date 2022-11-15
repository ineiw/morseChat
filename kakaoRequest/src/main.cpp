#include "client.h"
int main(int argc,char * argv[]){

  char dns[] = "www.kapi.kakao.com";
  char ok[] = "ok";

  string auth = string(argv[1]);
  string text = string(argv[2]);

  string thise = "wfe";
  string result = enter_web(ok,argv[2],thise.data(),ok);
  cout << "status : " << parsing_status(result.data());

  return 0;
}
