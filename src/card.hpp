#ifndef CARD_H
#define CARD_H

#include<string>
#include<map>
#include<any>


class card
{
private:
    std::string filename;
    std::map<std::string, std::string> info;
public:
    card(std::string input);
    ~card();
    void print();
};


#endif