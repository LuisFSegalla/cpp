#include "card.hpp"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
card::card(std::string input)
{
    std::ifstream f(input);
    nlohmann::json g;
    f >> g;
    info["name"] = g["name"];
    info["uri"] = g["uri"];
    info["cardmarket_url"] = g["purchase_uris"]["cardmarket"];
    info["mana_cost"] = g["mana_cost"];
    info["cmc"] = g["cmc"].dump();
}

card::~card()
{
}

void card::print()
{
    for(const auto& elem : info)
    {
       std::cout << elem.first << " | " << elem.second << "\n";
    }
}

std::string card::getName()
{
    return info["name"];
}