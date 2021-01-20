//
// Created by uddeepk on 1/19/21.
//

#ifndef LAB02_FOO_HPP
#define LAB02_FOO_HPP

#include <string>

class Foo {
public:
    Foo() ;
    Foo(const Foo &obj);
    Foo(std::string const &str); //Do I need str
    //void reverseText ( Foo obj); //Passing by value
    ~Foo() ; //destructor

    std::string getMessage () const;
private:
    std::string _message;
};
void passByValue( Foo obj) ;
void displayMessageFiveTimes ( Foo &obj);
Foo combinedNewFoo ( const Foo &obj1, const Foo &obj2 ) ;
#endif //LAB02_FOO_HPP
