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

    //Push a value to the back of the list
    myQueueOfDragons.push_back(Dragon("Chinese Fireball", "Yellow", "Scarlet", "China", "Romanian Dragon Sanctuary", 25, "Tailong"));
    //REQUIRE(myQueueOfDragons.front()._name == "Norbert");
    REQUIRE(myQueueOfDragons.back()._name == "Tailong");


    //Pop a value from the front of the list
    myQueueOfDragons.pop_front(); //Norbert got taken away
    REQUIRE(myQueueOfDragons.front()._name == "Fafnir");

}

TEST_CASE("Stack:Last-in First Out", "[stack]") {
    //Make stack using std::list
    std::list <Dragon> myStackOfDragons = {
            Dragon("Common Welsh Green", "Hazel", "Green", "Wales", "Romanian Dragon Sanctuary", 18, "Beca"),
            Dragon("Antipodean Opaleye", "Multicolored", "Pearly", "New Zealand", "N/A", 40, "Julunggul"),
            Dragon("Herbridean Black", "Purple", "Dark", "Scotland", "Banchory Bangers", 30, "Stewart")
    };
    REQUIRE(myStackOfDragons.back()._name == "Stewart");
    myStackOfDragons.push_back(Dragon("Ukranian Ironbelly", "Deep red", "Metallic grey-silver", "Ukraine", "N/A", 60, "Neville"));

    //"Pop a value from the back of the list
    REQUIRE(myStackOfDragons.back()._name == "Neville");
    myStackOfDragons.pop_back();
    REQUIRE(myStackOfDragons.back()._name == "Stewart");

}