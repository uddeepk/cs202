#include <iostream>
using std::cin;
using std::cout;
using std::endl;

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
