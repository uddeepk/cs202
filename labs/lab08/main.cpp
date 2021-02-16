#include <iostream>
#include "Person.hpp"


using std::cout;
using std::endl;

std::ostream& funcStaticLocalVariable (std::ostream &os) {
    static int myStaticLocalVariable = 0;
    os<< ++myStaticLocalVariable << endl;
    return os;
}

namespace {
    int myVariableSeenInFile = 0; // namespace means that you don't need static.
}




int main() {
    cout << "The current value of Person::_instances is " << Person::getInstances() << endl;
    cout << "\n";

    cout << "***Testing the static local variable***\n";

    for ( int i = 0 ; i < 5 ; ++i ) {
        cout << "The value of my static local variable is " ;
        funcStaticLocalVariable(cout) ;
    }
    cout << endl;
    Person myPerson ("Bree") ;

    cout << "The current value of Person::_instances is " << Person::getInstances() << endl;


    return 0;
}
