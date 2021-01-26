#include "Person.hpp"
#include <iostream>
#include <vector>

using std::cout; using std::endl;

int main() {
    /*
    int x;
    int y;
    int *xPtr = &x;
    x = 13;
    cout << x << "\n";
    cout << xPtr << "\n";
    cout << *xPtr << "\n";
    cout << &y << "\n";
    ++xPtr;
    cout << xPtr << "\n";
    *xPtr = 14;
    cout << y << "\n";

    int array[10] = { 1, 2, 3, 4};
    int * aPtr = array;
    ++aPtr;
    cout << *aPtr << "\n";
    */
    ////////////////////////////////////////////////////////////////////////////////////
    // Lab 02 work

    //Write a program that uses your class from Lab 2 that reports when it is created, copied,
    // and destroyed. In this program you should

    // 1.Create a raw pointer to a dynamically allocated object of your class. Is this object ever
    // destroyed?

    Person * per1 = new Person( "Bart");

    cout << per1->getName() << endl;
    // The object is not destroyed. Noticed no destructor called.

    // 2. Create a unique_ptr to an object of your class. Note when the object is created, and
    // that it is eventually destroyed. This object should be created with your
    // "other constructor," which takes a parameter.
    //
    // 3.Transfer ownership of that object to a different unique_ptr. Note that the object itself
    // is not copied.
    //
    // 4.Demonstrate the calling of a member function of your object through the unique_ptr.
    //
    // 5.Make a shared_ptr to a dynamically allocated object of your class.
    //
    // 6.Make another shared_ptr that points at the same object. Note that the object does not
    // get destroyed until both shared_ptrs go out of scope.
    //
    //Before each step, print a line to the console explaining what you're doing,
    //like "Creating raw pointer.", "Creating unique_ptr.", "Transferring ownership to
    //new unique_ptr.", "Calling a member function.", "Creating shared_ptr.",
    //"Creating another shared_ptr to the same object."

    //Be sure to use make_shared and make_unique, do not call the constructors for shared_ptr
    // and unique_ptr directly.


    return 0;
}
