#ifndef CLIENT
#define CLIENT

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

void err_handling(string message);
string parsing_status(char * response);

string enter_web(char * site,char * port,char * path);

#endif
