#include    <string>
#include    <iostream>
#include    <cstring>

#include    <curl/curl.h>

using namespace std;



size_t callBackFunk(char* ptr, size_t size, size_t nmemb, string* stream)
{
  int realsize = size * nmemb;
  stream->append(ptr, realsize);
  return realsize;
}

string url_post_proc (const char url[],const char post_data[],const char auth[])
{
  CURL *curl;
  CURLcode res;
  curl = curl_easy_init();
  string chunk;

  struct curl_slist *headerlist = NULL;
    if (curl)
  {
    headerlist = curl_slist_append(headerlist, "Content-Type: application/x-www-form-urlencoded" );

    string auth_line = "Authorization: Bearer "+string(auth);
    headerlist = curl_slist_append(headerlist, auth_line.data());

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_POST, 1);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, strlen(post_data));
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callBackFunk);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (string*)&chunk);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
    curl_easy_setopt(curl, CURLOPT_PROXY, "");
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
  }
  if (res != CURLE_OK) {
    cout << "curl error" << endl;
    exit (1);
  }

  return chunk;
}

int main (int argc,char *argv[])
{
  cerr << "error\n";

  char url_target[] = "https://kapi.kakao.com/v2/api/talk/memo/default/send";
  string post_data = "template_object={";
  post_data += "\"object_type\": \"text\",";
  post_data += "\"text\": \""+ string(argv[2]) +"\",";
  post_data += "\"link\": {";
  post_data += "\"web_url\": \"https://developers.kakao.com\",";
  post_data += "\"mobile_web_url\": \"https://developers.kakao.com\"";
  post_data += "},\"button_title\": \"바로 확인\"}";

  cout<<post_data<<"\n";
  char * auth = argv[1];

  string str_out = url_post_proc (url_target,post_data.data(),auth);

  cout << str_out << "\n";

  cerr << "error\n";

  return 0;
}
