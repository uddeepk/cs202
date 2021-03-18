#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include "Person.hpp"
//functionC() contains exactly one statement.
//functionB() declares an object of your class that notifies you of construction and destruction
//The output of the program is
    //Starting main()
    //Your object constructed message
    //Starting functionB()
    //Your object destruction message
    //Caught an exception: functionC() threw std::runtime_error
    //Ended normally.

void functionC(){
    //your code here
}

void functionB(){
 // your code here
    cout << "Starting functionB()" << endl;
    functionC();
    cout << "Ending functionB()" << endl;
}

void functionA(){
    functionB();
    // your code here
    cout << "Caught an exception: " << e.what() << endl;
    // your code here
}
int main() {
    cout << "Starting main()" << endl;
    functionA();
    cout << "Ended normally." << endl;
    return 0;
}
