#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MSG_LEN 10000
using namespace std;

string parsing_status(char * response){
  string result = "";

  for(int i=0;i<strlen(response);i++){
    result += response[i];
    if(response[i] == '\n')
      break;
  }
  return result;
}
void err_handling(string message){
  char * msg = message.data();
  
  fputs(msg,stderr);
  fputc('\n',stderr);
  exit(1);
}

string enter_web(){
  int sock;

  char site[] = "www.kapi.kakao.com";
  char pt[] = "/v2/api/talk/memo/default/send";
  char p[] = "80";
  char auth[] = "";
  char msg[] = "";

  long int res;
  struct sockaddr_in serv_addr;

  struct hostent * ok = gethostbyname(site);

  char message[MSG_LEN];
  string extra = "Content-Type: application/x-www-form-urlencoded\r\nAuthorization: Bearer " + string(auth) + "\r\n\r\ntemplate_object={\"object_type\": \"text\",\"text\": \"" + string(msg) + "\"}";
  sock = socket(PF_INET,SOCK_STREAM,0);

  if(sock == -1)
    err_handling("socket() error");

  memset(&serv_addr,0,sizeof(serv_addr));


  serv_addr.sin_family = PF_INET;
  serv_addr.sin_addr.s_addr = inet_addr(inet_ntoa(* (struct in_addr *)*ok->h_addr_list));
  serv_addr.sin_port = htons(atoi(p));

  if(connect(sock,(struct sockaddr*)&serv_addr,sizeof(struct sockaddr_in)) == -1)
    err_handling("conenct() error");

  cout << "connected!\n";
  
  string header = "POST /"+string(pt)+" HTTP/1.1\r\n\nHost: "+string(site)+"\r\n\r\n"+extra;

  send(sock,header.data(),strlen(header.data()),0);

  recv(sock,message,MSG_LEN,0);
  close(sock);
  
  return message;
}
