//
// Created by uddeepk on 2/9/21.
//

#include "catch.hpp"
#include "Dragon.hpp"
#include <list>

TEST_CASE("Queue: First-In First-Out", "[queue]") {

    //Creating queue using std::list
    std::list<Dragon> myQueueOfDragons = {
            Dragon ("Norwegian Ridgeback", "Orange", "Black", "Norway", "Romanian Dragon Sanctuary", 40, "Norbert"),
            Dragon("Swedish Short-Snout", "Yellow", "Silvery Blue", "Sweden", "Romanian Dragon Sanctuary", 22, "Fafnir"),
            Dragon("Hungarian Horntail", "Yellow", "Black", "Hungary", "Romanian Dragon Sanctuary", 50, "Susu")

    };

    REQUIRE(myQueueOfDragons.front()._name == "Norbert");

    SECTION("Push a value to the back of the list") {
        //myQueueOfDragons.push_back(Dragon("Chinese Fireball", "Yellow", "Scarlet", "China", "Romanian Dragon Sanctuary", 25, "Tailong"));
        REQUIRE(myQueueOfDragons.front()._name == "Norbert");
        REQUIRE(myQueueOfDragons.back()._name == "Tailong");
    }

}