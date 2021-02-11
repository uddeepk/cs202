//
// Created by uddeepk on 2/9/21.
//

#include "catch.hpp"
#include "Dragon.hpp"
#include <list>
#include <sstream>

std::ostream& myDragonOutput ( std::ostream& os, const std::list <Dragon>& myList) {
    for(auto dragon : myList) {
        dragon.myPrintDragon(os);
    }
    return os;
}

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

TEST_CASE("Insert and Find","[list]") {

    //My list to use insert and find
    std::list <Dragon> myListOfDragons = {
            Dragon("Ukranian Ironbelly", "Deep red", "Metallic grey-silver", "Ukraine", "N/A", 60, "Neville"),
            Dragon("Hungarian Horntail", "Yellow", "Black", "Hungary", "Romanian Dragon Sanctuary", 50, "Susu"),
            Dragon("Chinese Fireball", "Yellow", "Scarlet", "China", "Romanian Dragon Sanctuary", 25, "Tailong"),
            Dragon("Norwegian Ridgeback", "Orange", "Black", "Norway", "Romanian Dragon Sanctuary", 40, "Norbert"),
    };

    std::list <Dragon> myExpectedListOfDragons = {
            Dragon("Chinese Fireball", "Yellow", "Scarlet", "China", "Romanian Dragon Sanctuary", 25, "Tailong"),
            Dragon ("Herbridean Black", "Purple", "Dark", "Scotland", "Banchory Bangers", 30, "Stewart"),
            Dragon("Hungarian Horntail", "Yellow", "Black", "Hungary", "Romanian Dragon Sanctuary", 50, "Susu"),
            Dragon("Norwegian Ridgeback", "Orange", "Black", "Norway", "Romanian Dragon Sanctuary", 40, "Norbert"),
            Dragon("Ukranian Ironbelly", "Deep red", "Metallic grey-silver", "Ukraine", "N/A", 60, "Neville")
    };
    //Sorting instead of putting items in order.
    myListOfDragons.sort();

    //My Dragon to be inserted
    Dragon myInsertDragon ("Herbridean Black", "Purple", "Dark", "Scotland", "Banchory Bangers", 30, "Stewart");

    auto appropriatePlaceInList = myListOfDragons.begin();

    for( ;
    appropriatePlaceInList != myListOfDragons.end() && *appropriatePlaceInList < myInsertDragon ;
    ++appropriatePlaceInList) {
        // Taking advantage of the precedence in the && operator.
        // Run until one of the conditions becomes false
    }

    myListOfDragons.insert(appropriatePlaceInList, myInsertDragon);

    // Utilizing the operator overload for == we can do the following.
    REQUIRE(myListOfDragons == myExpectedListOfDragons);
}

//Print the list out
TEST_CASE("Print the list out","[print]") {
    Dragon mySingleDragon ("Antipodean Opaleye", "Multicolored", "Pearly", "New Zealand", "N/A", 40, "Julunggul");
    std::ostringstream oss;
    mySingleDragon.myPrintDragon(oss);

    //Test Single Case
    std::string mySingleDragonOutputString = "\nBreed: Antipodean Opaleye\n"
                                             "Eye Color: Multicolored\n"
                                             "Skin Color: Pearly\n"
                                            "Native Location: New Zealand\n"
                                            "Affiliation: N/A\n"
                                            "Length: 40\n"
                                            "Name: Julunggul\n";

    REQUIRE(oss.str() == mySingleDragonOutputString);

    oss.str(""); // making oss empty again.

    std::list <Dragon> myListOfDragons = {
            Dragon("Chinese Fireball", "Yellow", "Scarlet", "China", "Romanian Dragon Sanctuary", 25, "Tailong"),
            Dragon ("Herbridean Black", "Purple", "Dark", "Scotland", "Banchory Bangers", 30, "Stewart"),
            Dragon("Hungarian Horntail", "Yellow", "Black", "Hungary", "Romanian Dragon Sanctuary", 50, "Susu"),
            Dragon("Norwegian Ridgeback", "Orange", "Black", "Norway", "Romanian Dragon Sanctuary", 40, "Norbert"),
            Dragon("Ukranian Ironbelly", "Deep red", "Metallic grey-silver", "Ukraine", "N/A", 60, "Neville")
    };


    //Here we use an ostringstream object to store the ostream values that the myDragonOutput
    //returns. Then we have the loop below to create a string to match the ideal output.
    //Thus, using the .str() function in the std::ostringstream, we can easily compare the
    //actual output and the expected output.


    //Use ostringstream object to store the output from the

    myDragonOutput(oss, myListOfDragons);

    //Creating Expected output
    std::string myExpectedOutput ;

    for (auto const &dragon : myListOfDragons) {
        myExpectedOutput = myExpectedOutput +
                "\nBreed: " + dragon._breed + "\n" +
                "Eye Color: " + dragon._eyeColor + "\n" +
                "Skin Color: " + dragon._skinColor + "\n" +
                "Native Location: " + dragon._nativeLocation + "\n" +
                "Affiliation: " + dragon._affiliation + "\n" +
                "Length: " + std::to_string(dragon._length) + "\n" +
                "Name: " + dragon._name + "\n";
    }

    //Comparing the actual output to the expected output.
    REQUIRE(oss.str() == myExpectedOutput);

}