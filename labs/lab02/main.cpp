/*
 * lab02
 * Uddeep Karki
 * CS202
 * 01/19/2021
 *
 * Lab 02- Classes, Constructors, and the Destructors
 */
#include "Foo.hpp"
#include <iostream>
#include <vector>
using std::cout;

void dispFudge (const std::vector <Foo> &vecFoos ) ;

int main() {
    Foo f; //Local variable of an object of class
    cout << "\n" ;
    Foo b(f); //Creates a local variable that is a copy of another object of your class
    cout << "\n" ;
    Foo f2 ("hello"); //Calls the other constructor
    cout << "\n" ;
    Foo f3 ( "world") ;
    cout << "\n" ;
    passByValue(f2);
    cout << "\n";
    displayMessageFiveTimes ( f2 ); //Pass by reference
    cout << "\n";
    Foo f4 = f2 ; // Calling copy constructor
    cout << "\n" ;
    Foo f5 = combinedNewFoo ( f2, f3 ) ;
    cout << "\n" ;
    cout << "Data in the returned object : " << f5.getMessage() ;
    cout << "\n" ;
    std::vector <std::string> testMessage { "This", "is" , "a vector", "of" , "objects."};
    std::vector <Foo> vecFudge;
    for ( const auto &str : testMessage) {
        vecFudge.push_back(Foo(str)) ; //Notice other constuctors and copy constructors called

    }
    cout << "\n" ;
    dispFudge(vecFudge);
    cout << "\n" ;
    cout << "This is the end of code! " << std::endl;
    // C++ has garbage collection to enforce the scope of the variable. Notice the output
    // Destructors are being called.
    return 0;
}

void dispFudge ( const std::vector <Foo> &vecFoos ) {
    cout << "This is method is called by passing by reference a const vector of foo and displays them. :";
    for ( const auto &obj : vecFoos ) {
        cout << obj.getMessage() << "|";
    }
}