#include "Person.hpp"
#include <iostream>
#include <vector>

using std::cout;

int main() {
    Person p1 ; //Local variable of an object
    cout << "\n";
    Person p2(p1); //Creates a loca variable that is a copy of another object.
    cout << "\n";
    Person p3 ( "Andy"); //Calls other constructor
    cout << "\n";
    passByValue(p3);
    cout << "\n";
    displayNameFiveTimes(p3);
    cout << "\n";
    Person p4 ( "Steve");
    cout << "\n";
    Person p5 = combineTwoNames(p4, p3);
    cout << "\n";
    std::vector<std::string> testNames {"name1", "name2", "name3", "name4", "name5"};
    std::vector <Person> vecPer;
    for(const auto &str : testNames) {
        vecPer.push_back(Person(str));
    }
    cout << "\n";

    return 0;
}
