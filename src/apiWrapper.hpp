#ifndef APIWRAPPER_H
#define APIWRAPPER_H

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>
#include <curlpp/Infos.hpp>
#include <curl/curl.h>
#include <string.h>

class apiWrapper
{
private:
	curlpp::Easy request;
    std::string base_url;
public:
	apiWrapper(/* args */);
	~apiWrapper();
	int requestData(std::string name);
};

#endif