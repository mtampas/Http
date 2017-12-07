#include <iostream>
#include <restclient-cpp/restclient.h>
#include "restclient-cpp/connection.h"
#include "settings.hpp"
#include <json/json.h>
#include "tinyxml2.h"

using namespace std;


int count_word(string body, string word){

    int count = 0;
    size_t nPos = body.find(word, 0);
    while (nPos != string::npos)
    {
        count++;
        nPos = body.find(word, nPos+1);
    }

    return count;

}

int main() {

    cout<<"Program http_requests started\n";

    RestClient::init();
    settings settings;
    settings.init();

    //RestClient::Connection* conn = new RestClient::Connection("https://login.live.com/login.srf?wa=wsignin1.0&rpsnv=13&ct=1511522876&rver=6.7.6640.0&wp=MBI_SSL&wreply=https%3a%2f%2foutlook.live.com%2fowa%2f%3fauthRedirect%3dtrue%26realm%3doutlook.com%26RpsCsrfState%3df1449ae9-e0a2-fe2a-7644-f67e98ddc9b1&id=292841&whr=outlook.com&CBCXT=out&lw=1&fl=dob%2cflname%2cwld&cobrandid=90015");
    RestClient::Connection* conn = new RestClient::Connection(settings.get_url());
    conn->SetTimeout(5);

    //important ?
    conn->FollowRedirects(true);
    //set Headers
    RestClient::HeaderFields headers;
    headers["Accept"] = "application/json";
    //headers[""]

    conn->SetHeaders(headers);

    RestClient::Response r = conn->get("");
    cout<<r.code<<endl;
    cout<<r.body<<endl;

    //JSON PARSING
//    Json::Value root;
//    istringstream str(r.body);
//    str >> root;

    //XML PARSING
//    tinyxml2::XMLDocument doc;
//    doc.ToText();

    //cout<<"Words : "<<count_word(str, "\"Ειδήσεις\"");

    return 0;
}