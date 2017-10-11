#include <iostream>
#include <restclient-cpp/restclient.h>
#include "restclient-cpp/connection.h"
#include "restclient-cpp/restclient.h"

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

    RestClient::Connection* conn = new RestClient::Connection("http://google.com");
    conn->SetTimeout(5);

    //important ?
    conn->FollowRedirects(true);
    //set Headers
    RestClient::HeaderFields headers;
    headers["Accept"] = "applciation/json";
    conn->SetHeaders(headers);

    RestClient::Response r = conn->get("");



    cout<<r.code<<endl;
    cout<<r.body<<endl;

    cout<<"Words : "<<count_word(r.body, "\"Ειδήσεις\"");

    return 0;
}