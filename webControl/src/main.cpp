#include "client.h"
int main(int argc,char * argv[]){

  string result = enter_web(argv[1],argv[2],argv[3]);

  cout << "status : " << parsing_status(result.data());

  return 0;
}
