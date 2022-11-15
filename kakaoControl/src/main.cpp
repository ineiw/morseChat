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

  extra = "Cache-Control: max-age=0\r\nSec-Ch-Ua: \"Chromium\";v=\"107\", \"Not=A?Brand\";v=\"24\"";
  extra += "\r\nSec-Ch-Ua-Mobile: ?0";
  extra += "\r\nSec-Ch-Ua-Platform: \"Windows\"";
  extra += "\r\nUpgrade-Insecure-Requests: 1";
  extra += "\r\nContent-Type: application/x-www-form-urlencoded";
  extra += "\r\nAuthorization: Bearer D_Han7DxgJggt278rLd7wCmYo7PZWuYfBTkSuKvpCinI2QAAAYR2PRkJ";
  extra += "\r\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/107.0.5304.107 Safari/537.36";
  extra += "\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9";
  extra += "\r\nSec-Fetch-Site: none";
  extra += "\r\nSec-Fetch-Mode: navigate";
  extra += "\r\nSec-Fetch-User: ?1";
  extra += "\r\nSec-Fetch-Dest: document";
  extra += "\r\nAccept-Encoding: gzip, deflate";
  extra += "\r\nAccept-Language: ko-KR,ko;q=0.9,en-US;q=0.8,en;q=0.7";
  extra += "\r\nConnection: close";
  extra += "\r\nContent-Length: 177";
  extra += "\r\n\r\ntemplate_object={\"object_type\": \"text\",\"text\": \"23\",\"link\": {\"web_url\": \"https://developers.kakao.com\",\"mobile_web_url\": \"https://developers.kakao.com\"},\"button_title\": \"abc\"}";
  string result = enter_web(dns,port,path,extra.data());

  cout << "status : " << parsing_status(result.data());

  return 0;
}
