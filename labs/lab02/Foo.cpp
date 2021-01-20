//
// Created by uddeepk on 1/19/21.
//

#include "Foo.hpp"
#include <iostream>
using std::cout;
using std::endl;
Foo::Foo() {
    cout << "Called the Foo default constructor. " ;
}

Foo::Foo(const Foo &bar):_message(bar._message) {
    cout <<"Copy constructor is called! " ;
}

Foo::Foo(const std::string &str):_message(str) {
    cout <<"Other constructor is called! " ;
}

Foo::~Foo() {
    cout << "Destructor is called! " ;
}

void passByValue(Foo obj) {
    cout << "passByValue is called and Object is passed by value. Message in object is " << obj.getMessage() ;
}

std::string Foo::getMessage() const{
    return _message;
}

void displayMessageFiveTimes (Foo &obj) {
    cout << "Passing object by reference. " ;
    for ( int i = 0 ; i < 5 ; ++i) {
        cout << obj.getMessage() << " " ;
    }
}

Foo combinedNewFoo ( const Foo& obj1, const Foo& obj2 ) {
    cout << "Passes oject by const references and returns an object. ";
    return Foo ( obj1.getMessage() + " " + obj2.getMessage()) ;
}

