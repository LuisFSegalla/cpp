#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>
#include <curlpp/Infos.hpp>
#include <curl/curl.h>
#include <string.h>
#include "apiWrapper.hpp"


/// Callback must be declared static, otherwise it won't link...
static size_t WriteCallback(char* ptr, size_t size, size_t nmemb, void *f)
{
	FILE *file = (FILE *)f;
	return fwrite(ptr, size, nmemb, file);
};

apiWrapper::apiWrapper(){
	std::cout << "Building the wrapper!" << std::endl;
    base_url = "https://api.scryfall.com/cards/named?fuzzy=";
}

apiWrapper::~apiWrapper(){
// 	std::cout << "Calling the destructor!" << std::endl;
}

int apiWrapper::requestData(std::string name){
	try{
		curlpp::options::WriteFunctionCurlFunction
			myFunction(WriteCallback);

		std::string filename =  name + ".json";
		replace(begin(filename), end(filename),' ', '_');

		std::cout << "filename = " << filename << std::endl;

		std::string tmp = name;
		replace(begin(tmp), end(tmp), ' ', '+');
		std::string url = base_url + tmp;

		std::cout << "url = " << url << std::endl;

		FILE *file = stdout;
		if(filename.c_str() != NULL)
		{
			file = fopen(filename.c_str(), "a");
			if(file == NULL)
			{
			  fprintf(stderr, "%s/n", strerror(errno));
			  return EXIT_FAILURE;
			}
		} 

		curlpp::OptionTrait<void *, CURLOPT_WRITEDATA> 
			myData(file);

		request.setOpt(myFunction);
		request.setOpt(myData);

		using namespace curlpp::Options;
		request.setOpt(curlpp::Options::Verbose(false));

        request.setOpt(curlpp::Options::UserAgent("PriceChecker/1.0"));
        
		request.setOpt(curlpp::Options::Url(url));

		request.perform();
	}
	catch ( curlpp::LogicError & e ) {
		std::cout << e.what() << std::endl;
	}
	catch ( curlpp::RuntimeError & e ) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}


int apiWrapper::requestData(std::vector<std::string> nameList){
	std::vector<std::string>::iterator name;
	for(name = nameList.begin(); name != nameList.end(); name++)
	{
		std::cout << *name << std::endl;
		try{
			curlpp::options::WriteFunctionCurlFunction
				myFunction(WriteCallback);

			std::string filename = "../output/" +  *name + ".json";
			replace(begin(filename), end(filename),' ', '_');

			std::string tmp = *name;
			replace(begin(tmp), end(tmp), ' ', '+');
			std::string url = base_url + tmp;

			std::cout << "url = " << url << std::endl;

			FILE *file = stdout;
			if(filename.c_str() != NULL)
			{
				file = fopen(filename.c_str(), "w");
				if(file == NULL)
				{
					fprintf(stderr, "%s/n", strerror(errno));
					return EXIT_FAILURE;
				}
			} 

			curlpp::OptionTrait<void *, CURLOPT_WRITEDATA> 
				myData(file);

			request.setOpt(myFunction);
			request.setOpt(myData);

			using namespace curlpp::Options;
			request.setOpt(curlpp::Options::Verbose(false));

			request.setOpt(curlpp::Options::UserAgent("PriceChecker/1.0"));
			
			request.setOpt(curlpp::Options::Url(url));

			request.perform();
		}
		catch ( curlpp::LogicError & e ) {
			std::cout << e.what() << std::endl;
		}
		catch ( curlpp::RuntimeError & e ) {
			std::cout << e.what() << std::endl;
		}


	}
	return 0;
}