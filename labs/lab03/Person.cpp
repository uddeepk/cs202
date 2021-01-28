//
// Created by uddeepk on 1/21/21.
//

#include "Person.hpp"
#include <iostream>


using std::cout;
using std::endl;
Person::Person():_name("Stranger") {
    cout << "Constructed a Person named _Anon_ via Default Constructor!\n";
}

Person::Person (const Person &per):_name("copyOf"+per._name) {
    cout << "Constructed a Person named _" << _name << "via Copy Constructor!\n" ;
}

Person::Person(const std::string &str):_name(str) {
    cout <<"Constructed a Person named _" << _name << "_ via (const std::string &) Constructor!\n" ;
}

Person::~Person() {
    cout << "Destroyed a Person named _" << _name << "_ via Destructor!\n" ;
}
std::string Person::getName() const {
    return _name;
}
void Person::setName(std::string newName) {
    _name = newName;
}