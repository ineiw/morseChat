#include "client.h"
int main(int argc,char * argv[]){

  char dns[] = "kapi.kakao.com";
  char path[] ="/v2/api/talk/memo/default/send"; 
  char port[] = "443";


  string payload = "template_object={\"object_type\": \"text\",\"text\": \"" ;
  payload += string(argv[2])+ "\",\"link\": {\"web_url\": \"https://developers.kakao.com\",\"mobile_web_url\": \"https://developers.kakao.com\"},\"button_title\": \"click\"}";
  string extra = "\r\nAuthorization: Bearer "+string(argv[1]);
  extra +="\r\nContent-Type: application/x-www-form-urlencoded";
  extra +="\r\nContent-Length: " + to_string(payload.length());
  extra +="\r\nAccept: */*";
  extra += "\r\nConnection: close\r\n\r\n";

  extra += payload;

  string result = enter_web(dns,port,path,extra.data());

  cout << "status : " << parsing_status(result.data());

  return 0;
}
