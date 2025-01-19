#include "userWrapper.h"

#include <iostream>
#include <SpotifyAPI.h>
#include <curl/curl.h>
#include <utils/CurlUtils.h>
#include <fstream>
#include <json.h>

userWrapper::userWrapper() : SpotifyAPI()
{
    std::cout << "Constructor!" << std::endl;

    std::ifstream userInfo("../keys/clientInfo.json", std::ifstream::binary);
    nlohmann::json userJson = nlohmann::json::parse(userInfo); 

    std::string refreshToken = userJson["refreshToken"];
    std::string clientId = userJson["clientId"];
    std::string clientSecret = userJson["clientSecret"];


    CURL * curl;
    curl = curl_easy_init ( ) ;
    if(!curl)
    {
        std::cerr << "Could not initiate cURL" << std::endl;
    }

    try{
        CURL * curl;
        curl = curl_easy_init () ;
        if(!curl)
        {
            throw 1;
        }
    }
    catch(int err)
    {
        std::cout << "Could not initialise curl" << std::endl;
    }

    std::string readBuffer;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

    curl_easy_setopt(curl, CURLOPT_URL, "https://accounts.spotify.com/api/token");
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);  // Can't authenticate the certificate, so disable authentication.
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
    std::string postData = "grant_type=refresh_token&refresh_token="+refreshToken+"&client_id=" + clientId + "&client_secret="+clientSecret;
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData.c_str());

    int rc = curl_easy_perform(curl);
    if (rc != CURLE_OK)
        throw CurlException(rc);
    curl_easy_cleanup(curl);

    nlohmann::json json = nlohmann::json::parse(readBuffer);
    std::string accessToken = json["access_token"];

    this->setAuthToken(accessToken);
    me = this->GetMe();
}

userWrapper::~userWrapper(){
    std::cout << "Destructor!" << std::endl;
}

void userWrapper::printUser(){
    // std::cout << "User Name = " << me->GetDisplayName() << std::endl;
};