#include <iostream>
#include <fstream>
#include "src/card.hpp"
#include "src/apiWrapper.hpp"
#include "src/collection.hpp"
using namespace std;


int main(int argc, char *argv[])
{

	//Split main into separate processes. First you should run a process to get all the cards form your collection
	//then run a separate one to process them.

	// if(argc < 2)
	// {
	// 	std::cerr << "Example 04: Wrong number of arguments" << std::endl 
	// 		<< "Example 04: Usage: example04 url" 
	// 		<< std::endl;
	// 	return EXIT_FAILURE;
	// }
	// std::string filename ;

	// if(argc >= 2)
	// {
	// 	filename = argv[1];
	// }
	// else{
	// 	std::cout << "Could not open the file" << std::endl;
	// 	return -1;
	// }
	// apiWrapper myCurl;
	// if(argc == 3)
	// {
	// 	std::vector<std::string> myListOfCards;
	// 	std::ifstream inputFile(filename);
	// 	std::string card;
	// 	while (std::getline(inputFile, card))
	// 	{
	// 		std::cout << "Card being read = " << card << std::endl;
	// 		myListOfCards.push_back(card);
	// 	}
	// 	myCurl.requestData(myListOfCards);
		
	// }
	// else
	// {
	// 	myCurl.requestData(filename);
	// }

	collection myCollection;

	std::shared_ptr<card> myCard1(new card("../output/Korvold_Fae_Cursed_King.json"));
	// myCard1->print();
	std::shared_ptr<card> myCard2(new card("../output/Loot,_the_Key_to_Everything.json"));
	// myCard2->print();
	std::shared_ptr<card> myCard3(new card("../output/Massacre_Girl,_Known_Killer.json"));
	// myCard3->print();

	myCollection.addCard(myCard1);
	myCollection.addCard(myCard2);
	myCollection.addCard(myCard3);


	myCollection.printCollection();

	return 0;
}
