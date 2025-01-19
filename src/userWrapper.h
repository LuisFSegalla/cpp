#ifndef USERWRAPPER_H
#define USERWRAPPER_H

#include <SpotifyAPI.h>
#include<string>

class userWrapper : public SpotifyAPI
{
private:
    std::string refreshToken;
    std::string clientId;
    std::string clientSecret;
    // SpotifyAPI *api;
    std::shared_ptr<User> me;
public:
    userWrapper();
    ~userWrapper();
    void printUser();
};


#endif
