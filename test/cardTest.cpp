#define BOOST_TEST_MODULE CardTestModule
#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include <fstream>
#include "../src/card.hpp"

BOOST_AUTO_TEST_CASE(cardClassTest)
{
    std::shared_ptr<card> myCard1(new card("./output/korvold_fae_cursed_king.json"));
    std::string errMessage = "Names are different!";
    BOOST_CHECK_MESSAGE(myCard1->getName() == "Not Korvold, Fae-Cursed King", errMessage);
}