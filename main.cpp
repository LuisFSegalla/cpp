#include <iostream>
// #include <curlpp/cURLpp.hpp>
// #include <curlpp/Easy.hpp>
// #include <curlpp/Options.hpp>
// #include <curlpp/Exception.hpp>
// #include <curlpp/Infos.hpp>
// #include <curl/curl.h>
// #include <algorithm>
// #include <string.h>
#include "src/card.hpp"
#include "src/apiWrapper.hpp"
using namespace std;


int main(int argc, char *argv[])
{

	if(argc < 2)
	{
		std::cerr << "Example 04: Wrong number of arguments" << std::endl 
			<< "Example 04: Usage: example04 url" 
			<< std::endl;
		return EXIT_FAILURE;
	}
	std::string filename ;
	if(argc >= 2)
	{
		filename = argv[1];
	}
	else{
		std::cout << "Could not open the file" << std::endl;
		return -1;
	}

	apiWrapper myCurl;
	myCurl.requestData(filename);
	// card myCard("card.json");
	// myCard.print();

	return 0;
}