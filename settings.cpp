//
// Created by administrator on 6/12/2017.
//

#include "settings.hpp"
#include <fstream>
#include <json/json.h>
#include <jansson.h>

settings::settings(){

}

settings::settings(const string& file) {

    const std::string defaultIniFile = "config.ini";

    if( file.empty() )
        m_file = defaultIniFile;
    else {
        m_file = file;
    }

}


void settings::init() {

    // read a JSON file
    std::ifstream ifs("config.ini");
    Json::Value js, js2;
    Json::Reader reader;
    ifs >> js2;

    string strJson = "{    \"hit_url\" : \"www.google.gr\" }";
    bool parsingSuccessful = reader.parse(strJson.c_str(), js);

    if (!parsingSuccessful) {
        std::cout << "Failed to parse"
                  << reader.getFormattedErrorMessages();
    }

    cout << js2.get("hit_url", "A Default Value if not exists").asString() << endl;
    Hit_Url = js2.get("hit_url", "A Default Value if not exists").asString();

}

void settings::set_url(string url){

    Hit_Url = url;
}

string settings::get_url(){

    return Hit_Url;
}


