/*
 * Uddeep Karki
 * CS202 HW2
 * Program 2: Memory Layout
 *
 * This C++ prgoram tells the order in which static storage, the stack, and the free store are
 * laid out in memory.
 * Which direction does the stack grow? upward toward higher addresses or downward towards
 * lower addresses?
 * In an array on the free store, are elements with higher indices allocated at higher or lower
 * addresses?
 *
 * Code
 * Static data
 * Free store
 * Stack
 */


#include <iostream>

void printPointer(int i) {
    int* iptr = &i;
    // the unary * operator dereferences the pointer
    std::cout << "i = " << *iptr << "\n";
    std::cout << "&i = " << iptr << "\n";
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
