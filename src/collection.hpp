#ifndef COLLECTION_H
#define COLLECTION_H

#include "card.hpp"
#include <string>
#include <vector>
#include <memory>

/*
    collection class hold information about all the cards the user has. 
    Cards can be added individually or via a text file containinig every card that needs to be added at once.
*/

class collection
{
private:
    std::vector<std::shared_ptr<card>> myCards;
    unsigned int qtdCards;
    unsigned int qtdDecks;
public:
    collection();
    collection(std::string pathToDeck);
    ~collection();
    void addCard(std::shared_ptr<card> newCard);
    void addDeck(std::string pathToDeck);
    void printCollection();
};


#endif