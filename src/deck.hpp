#ifndef DECK_H
#define DECK_H

#include "card.hpp"
#include <string>
#include <vector>
#include <memory>

class card; //forward declaration of card class so the compiler doesn't get confused?

/*
    This class will represent a single Magic the Gathering Commander deck.
*/

class deck
{
private:
    std::vector<std::shared_ptr<card>> *myDeck;
    std::string name;
public:
    deck();
    deck(std::string pathToDeck);
    ~deck();
    void addCard(std::shared_ptr<card> newCard);
    void deleteCard(std::string cardName);
    void moveCard(std::string cardName, deck *newDeck);
    void printDeck();
    void setName(std::string deckName);
    std::string getName();
    int getNumCards();
};


#endif