#include "Person.hpp"
#include <iostream>
#include <vector>

using std::cout;

void passByValue(Person per) {
    cout << "passByValue is called, object massed by value. Name of Person is " << per.getName() << ". " ;
}

void displayNameFiveTimes (Person &per) {
    cout <<"Passed object by reference. " ;
    for ( int i = 0 ; i < 5 ; ++i) {
        cout << per.getName() << " ";
    }

}

Person combineTwoNames ( const Person &per1, const Person &per2) { //Pas by const ref
    cout << "Passes objects by const references and returns an object. ";
    return Person ( per1.getName() + " " + per2.getName()); //returns object by value
}

int main() {
    Person p1 ; //Local variable of an object
    cout << "\n";
    Person p2(p1); //Creates a loca variable that is a copy of another object.
    cout << "\n";
    Person p3 ( "Andy"); //Calls other constructor
    cout << "\n";
    cout << "** Passing by value:";
    passByValue(p3);
    cout << "\n";
    cout << "**Pass by ref: ";
    displayNameFiveTimes(p3);
    cout << "\n";
    Person p4 ( "Steve");
    cout << "\n";
    cout << "**Pass by const ref";
    Person p5 = combineTwoNames(p4, p3);
    cout << "\n";
    std::vector<std::string> testNames {"name1", "name2", "name3", "name4", "name5"};
    std::vector <Person> vecPer;
    cout << "Pushing into vector" << std::endl;
    for(const auto &str : testNames) {
        vecPer.push_back(Person(str));
    }
    cout << "\n";
    cout << "End of code " << std::endl;
    return 0;
}
