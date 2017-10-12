#include <iostream>
#include <restclient-cpp/restclient.h>
#include "restclient-cpp/connection.h"
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

    RestClient::Connection* conn = new RestClient::Connection("https://login.live.com/login.srf?wa=wsignin1.0&rpsnv=13&ct=1507812714&rver=6.7.6640.0&wp=MBI_SSL&wreply=https%3a%2f%2foutlook.live.com%2fowa%2f%3fauthRedirect%3dtrue%26nlp%3d1%26RpsCsrfState%3d30c35200-b0e2-6931-7b4f-533878ba0e18&id=292841&CBCXT=out&fl=wld&cobrandid=90015");
    conn->SetTimeout(5);

    //important ?
    conn->FollowRedirects(true);
    //set Headers
    RestClient::HeaderFields headers;
    headers["Accept"] = "application/json";
    conn->SetHeaders(headers);

    RestClient::Response r = conn->get("");
    cout<<r.code<<endl;

    //JSON PARSING
//    Json::Value root;
//    istringstream str(r.body);
//    str >> root;

    //XML PARSING
//    tinyxml2::XMLDocument doc;
//    doc.SaveFile(r.body, false);

    //cout<<"Words : "<<count_word(str, "\"Ειδήσεις\"");

    return 0;
}