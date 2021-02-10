//
// Created by uddeepk on 2/9/21.
//

#include "catch.hpp"
#include "Dragon.hpp"
#include <list>

TEST_CASE("Queue: First-In First-Out", "[queue]") {
    //Creating queue using std::list
    std::list<Dragon> myListOfDragons = {
            Dragon("Norwegian Ridgeback", "Orange", "Black", "Norway", "Romanian Dragon Sanctuary", 40, "Norbert"),
            Dragon("Swedish Short-Snout", "Yellow", "Silvery Blue", "Sweden", "Romanian Dragon Sanctuary", 22, "Fafnir"),
            Dragon("Hungarian Horntail", "Yellow", "Black", "Hungary", "Romanian Dragon Sanctuary", 50, "Susu")

    };

    REQUIRE(myListOfDragons.front()._name == "Norbert");

}