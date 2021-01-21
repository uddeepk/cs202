//
// Created by uddeepk on 1/21/21.
//

#include "Person.hpp"
#include <iostream>
using std::cout;
using std::endl;
Person::Person() {
    cout << "Called Person default constructor! ";
}

Person::Person (const Person &per):_name(per._name) {
    cout << "Copy constructor called! " ;
}

Person::Person(const std::string &str):_name(str) {
    cout <<"Other constructor called! " ;
}

Person::~Person() {
    cout << "Destructor is called! ";
}
std::string Person::getName() const {
    return _name;
}
void passByValue(Person per) {
    cout << "passByValue is called, object massed by value. Name of Person is " << per.getName() ;
}

void displayNameFiveTimes (Person &per) {
    cout <<"Passed object by reference. " ;
    for ( int i = 0 ; i < 5 ; ++i) {
        cout << per.getName() << " ";
    }

}

Person combinedNewName ( const Person &per1, const Person &per2) {
    cout << "Passes objects by const references and returns an object. ";
    return Person ( per1.getName() + " " + per2.getName());
}