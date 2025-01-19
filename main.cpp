// // #include <SpotifyAPI.h>
// #include <fstream>
// #include <curl/curl.h>
// #include <utils/CurlUtils.h>
// #include <models/CurrentlyPlayingTrack.h>
// #include <fstream>
// #include <json.h>
#include "userWrapper.h"
#include <iostream>

int main()
{

    // static SpotifyAPI api = SpotifyAPI();


    // std::ifstream userInfo("../keys/clientInfo.json", std::ifstream::binary);
    // nlohmann::json userJson = nlohmann::json::parse(userInfo);


    // std::cout << "User info form file = " << userJson << std::endl;

    // std::string refreshToken = userJson["refreshToken"];
    // std::string clientId = userJson["clientId"];
    // std::string clientSecret = userJson["clientSecret"];




    // CURL * curl;
    // curl = curl_easy_init ( ) ;
    // if(!curl)
    // {
    //     std::cerr << "Could not initiate cURL" << std::endl;
    //     return 0;
    // }

    // std::string readBuffer;
    // curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    // curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

    // curl_easy_setopt(curl, CURLOPT_URL, "https://accounts.spotify.com/api/token");
    // curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);  // Can't authenticate the certificate, so disable authentication.
    // curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
    // std::string postData = "grant_type=refresh_token&refresh_token="+refreshToken+"&client_id=" + clientId + "&client_secret="+clientSecret;
    // curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData.c_str());

    // int rc = curl_easy_perform(curl);
    // if (rc != CURLE_OK)
    //     throw CurlException(rc);
    // curl_easy_cleanup(curl);

    // nlohmann::json json = nlohmann::json::parse(readBuffer);
    // std::string accessToken = json["access_token"];

    // api.setAuthToken(accessToken);


    userWrapper api;
    // api.printUser();
    // std::shared_ptr<Album> album = api.GetAlbum("4R6FV9NSzhPihHR0h4pI93");
    // std::cout << "Album name = " << album->GetName().c_str() << std::endl;
    

    return 0;
}