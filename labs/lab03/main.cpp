#include "Person.hpp"
#include <iostream>
#include <vector>

using std::cout;

int main() {
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
    return 0;
}
