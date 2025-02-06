#include "deck.hpp"
#include "card.hpp"
#include <vector>
#include <string>
#include <iostream>

deck::deck()
{
    std::cout << "Simple constructor for Deck Class" << std::endl;
    myDeck = new(std::vector<std::shared_ptr<card>>);
}

deck::~deck()
{
    std::cout << "Simple destructor for Deck Class" << std::endl;
    delete myDeck;
}

void deck::addCard(std::shared_ptr<card> newCard)
{
    myDeck->push_back(newCard);
}

void deck::deleteCard(std::string cardName)
{
    std::cout << "deleteCard method" << std::endl;

    std::vector<std::shared_ptr<card>>::iterator it;
    
    for (it = myDeck->begin(); it != myDeck->end(); it++)
    {
        if(!cardName.compare(it->get()->getName()))
        {
            myDeck->erase(it);
            break;
        }
    }
}

void deck::printDeck()
{
    std::vector<std::shared_ptr<card>>::iterator it;
    
    std::cout << name << ":" << std::endl;

    for (it = myDeck->begin(); it != myDeck->end(); it++)
    {
        std::cout << it->get()->getName();
        if(it->get()->getDeck()->getName() == name)
        {
            std::cout << " | Card already in the deck" << std::endl; 
        }
        else
        {
            std::cout << " | Card in " << it->get()->getDeck()->getName() << std::endl;
        }
    }
}

void deck::setName(std::string deckName)
{
    name = deckName;
}


std::string deck::getName()
{
    return name;
}

int deck::getNumCards()
{
    return myDeck->size();
}