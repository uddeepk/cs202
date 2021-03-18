//
// Created by uddeepk on 1/21/21.
//

#include "Person.hpp"
#include <iostream>
using std::cout;
using std::endl;

int Person::_instances = 0;

int Person::getInstances() {
    return _instances;
}
Person::Person() {
    cout << "Called Person default constructor! \n";
    ++_instances;
    // change for this lab follows. check for _instances > 5 then throw exception
    if(_instances > 5 )
        throw std::runtime_error("More than 5 people were being created");
}

Person::Person (const Person &per):_name(per._name) {
    cout << "Copy constructor called! \n" ;
    ++_instances;
}

Person::Person(const std::string &str):_name(str) {
    cout <<"Other constructor called! \n" ;
    ++_instances;
}

Person::~Person() {
    cout << "Destructor is called! \n";
    --_instances;
    cout << "The current value of Person::_instances is " << Person::getInstances() << endl;
}
std::string Person::getName() const {
    return _name;
}
void passByValue(Person per) {
    cout << "passByValue is called, object massed by value. Name of Person is \n" << per.getName() << ". " ;
}

void displayNameFiveTimes (Person &per) {
    cout <<"Passed object by reference. \n" ;
    for ( int i = 0 ; i < 5 ; ++i) {
        cout << per.getName() << " ";
    }

}

Person combineTwoNames ( const Person &per1, const Person &per2) {
    cout << "Passes objects by const references and returns an object. \n";
    return Person ( per1.getName() + " " + per2.getName());
}

std::ostream& operator<<(std::ostream &os, const Person &p) {
    os << "This is a Person: " << p._name ;
    return os;
}

Person operator+(const Person &person1,  const Person &person2) {
    return Person(person1._name + " " + person2._name);
//    return Person();
}
//Person Person::operator+(  const Person &person2) { // Only preferred if changin the original values in the object
//    return Person (_name + person2._name);
//}