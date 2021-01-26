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
