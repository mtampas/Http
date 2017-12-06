//
// Created by administrator on 6/12/2017.
//

#ifndef HTTP_REQUESTS_SETTINGS_H
#define HTTP_REQUESTS_SETTINGS_H

#include <iostream>
using namespace std;

class settings {

public:
    settings();
    void init();

    void set_url(string url){

        Hit_Url = url;
    }

    string get_url(){

        return Hit_Url;
    }
    string m_file = "";
private:

    settings(const std::string& file);
    string Hit_Url = "";

};


#endif //HTTP_REQUESTS_SETTINGS_H
