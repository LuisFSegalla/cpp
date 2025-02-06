#ifndef CARD_H
#define CARD_H

#include "deck.hpp"

#include<string>
#include<map>
#include<any>

class deck; //forward declaration of deck class so the compiler doesn't get confused?

/*
    Base construction block of the application. 
    Holds information of a single card parsed from a JSON file. The file can be obtained using the apiWrapper class
    that gets the information using Scryfall's API.
*/

class card
{
private:
    std::string filename;
    std::map<std::string, std::string> info;
    deck *inDeck;


public:
    card(std::string input);
    ~card();
    void print();
    std::string getName();
    void setDeck(deck *d);
    deck* getDeck();

};


#endif