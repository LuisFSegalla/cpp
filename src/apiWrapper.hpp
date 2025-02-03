#ifndef APIWRAPPER_H
#define APIWRAPPER_H

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>
#include <curlpp/Infos.hpp>
#include <curl/curl.h>
#include <string.h>


/*
	Simple wrapper on the curlpp library and Scryfall's api.
	Taked either a card name of a list of cards and request data from it. 
	The cards' data is the written to a JSON file that can be fed to the card class 
	to expose some of it's data to the application.
*/

class apiWrapper
{
private:
	curlpp::Easy request;
    std::string base_url;
public:
	apiWrapper();
	~apiWrapper();
	int requestData(std::string name);
	int requestData(std::vector<std::string> name_list);
};

#endif