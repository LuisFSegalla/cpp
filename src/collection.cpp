#include "collection.hpp"
#include "card.hpp"
#include "apiWrapper.hpp"
#include <iostream>

collection::collection()
{
    qtdCards = 0;
    qtdDecks = 0;
    std::cout << "Called constructor of collection class!" << std::endl;
}

collection::~collection()
{
    std::cout << "Called destructor of collection class!" << std::endl;
}

void collection::addCard(std::shared_ptr<card> newCard)
{
    myCards.push_back(std::move(newCard));
    qtdCards++;
}

void collection::printCollection()
{
    std::vector<std::shared_ptr<card>>::iterator it;

    for(it=myCards.begin(); it != myCards.end(); it++)
    {
        std::cout << it->get()->getName() << std::endl;
    }
}