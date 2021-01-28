//int g_constructed, g_destroyed;

#include "Person.hpp"
#include <iostream>
#include <vector>
#include <memory>


using std::cout; using std::endl;

int main() {
    //extern int g_constructed;
    //extern int g_destroyed;
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

    cout << "1. Creating Raw pointer by copying an object!\n ";
    Person per0 = Person ("Bart");
    Person * per1 = new Person( per0 );

    //cout << per1->getName() << "\n";

    //cout << per1 << endl; // per1 ptr points to this memory.

    //delete per1; //deleting object at pointer because objects at raw pointer do not get deleted auto
    //per1 = nullptr; //making it point to null
    // ****The object is not destroyed. Noticed no destructor called.

    cout << "\n";

    // 2. Create a unique_ptr to an object of your class. Note when the object is created, and
    // that it is eventually destroyed. This object should be created with your
    // "other constructor," which takes a parameter.

    cout << "2. Creating unique_ptr to an object of Person class!\n";

    //std::unique_ptr <Person> uPtrPer = std::make_unique<Person> (Person("Andy")); //Calls the copy constructor
    auto uPtrPer =  std::make_unique <Person> ("Andy"); //Notice Template used only once, less redundant. More efficient
    //auto uPtrPer (std::make_unique <Person> ("Andy")); //Why not???
    //std::unique_ptr <Person> uPtrPer(new Person("Andy")); //Works. ask why not.
    //auto uPtrPer = std::make_unique <Person> (Person("Andy")); //uses copy constructor inefficient ?

    cout <<"\n";
    // 3.Transfer ownership of that object to a different unique_ptr. Note that the object itself
    // is not copied.

    cout << "3. Transferring ownership of that object to a different unique_ptr\n";
    //auto uPtrPer2 = uPtrPer; //gives error
    //std::unique_ptr uPtrPer2 (uPtrPer);
    auto uPtrPer2 = std::move(uPtrPer);

    cout<< "\nThe unique pointer points to Person _" << uPtrPer2->getName() << "_ at address" <<uPtrPer2
    <<"\nAlso, notice that the original unique_ptr points to " << uPtrPer
    <<" which is the address of a nullptr. \n"; //points to address of 0 or "nullptr" after std::move

    cout << "\n";
    // 4.Demonstrate the calling of a member function of your object through the unique_ptr.
    cout << "4. Demonstrating the calling of a member function of the object through unique_ptr!\n";
    //Isn't it the same as calling member function from a raw pointer???

    cout << uPtrPer2->getName() << "\n";

    cout << "\n";
    // 5.Make a shared_ptr to a dynamically allocated object of your class.
    cout << "5. Making a shared_ptr to a dynamically allocated object of Person class!\n";

    auto shPtrPer = std::make_shared<Person> ("Theodore"); // we can also use '=' assignment.

    auto shPtrPer2 = shPtrPer;

    cout << shPtrPer << " is the address of the first shared_ptr to Person _" << shPtrPer->getName()
    << "_\n";

    cout << "\n" ;
    // 6.Make another shared_ptr that points at the same object. Note that the object does not
    // get destroyed until both shared_ptrs go out of scope.
    cout << "6. Making another shared_ptr that points at the same object!\n";
    auto shPtrPer3 (shPtrPer);
    //auto shPtrPer3 = std::make_shared<Person>(*shPtrPer);
    cout <<shPtrPer3 << " is the address of the shared_ptr pointing to same Person named "
    << shPtrPer->getName(); //Checking memory address
    cout << "\n\n***End of Code***\n\n";
    //Before each step, print a line to the console explaining what you're doing,
    //like "Creating raw pointer.", "Creating unique_ptr.", "Transferring ownership to
    //new unique_ptr.", "Calling a member function.", "Creating shared_ptr.",
    //"Creating another shared_ptr to the same object."

    //Be sure to use make_shared and make_unique, do not call the constructors for shared_ptr
    // and unique_ptr directly.


    return 0;
}
