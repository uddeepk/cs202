#include <iostream>
#include "Person.hpp"
//iso cppfaq
//C++FAQ and C++ Core Guidelines
using std::cout;
using std::endl;

int main() {
    //std::cout << "Hello, World!" << std::endl;
    Person myPerson("Leon");
    cout << myPerson << endl;

    cout << "Getting New Person by adding two Persons\n";
    Person myPerson2("Theodore"), myPerson3("Julian");
    Person myPerson4 = myPerson2 + myPerson3;
    cout << "\n";

    cout << myPerson4 << endl;

    return 0;
}
