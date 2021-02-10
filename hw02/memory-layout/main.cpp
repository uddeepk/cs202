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
 * Code segment aka text segment, where compiled program sits in memory. Typically read only
 * Static data or data segment, variables that exist throughout program execution.
 *      Global variables, adn variables declared as static
 * Free store uesd for dynamicallly allocated memroy ??
 * Stack segment contains the system stack, used for temporary storage. Simple DS with
 *      LIFO access. Items only removed from "top" of the stack.
 */


#include <iostream>

void printPointer(int i) {
    int* iptr = &i;
    // the unary * operator dereferences the pointer
    std::cout << "i = " << *iptr << "\n";
    std::cout << "&i = " << iptr << "\n";
}
void printMemoryAddress(int* i ) {
    //std::cout << "i = " << *i << "\n";
    std::cout << "address in memory = " << i << "\n";
}
void printPointer(int i, int j) {
    int* iptr = &i;
    int* jptr = &j;
    // the unary * operator dereferences the pointer
    std::cout << "i = " << *iptr << "\n";
    std::cout << "&i = " << iptr << "\n";
    std::cout << "j = " << *jptr << "\n";
    std::cout << "&j = " << jptr << "\n";
}
namespace {
    int xxx = 1;
}
static int g_anAnswerToLife = 42;

int main() {
    std::cout << "Static decreasing" ;
    printPointer(g_anAnswerToLife);
    printMemoryAddress(&g_anAnswerToLife);

    printPointer(xxx);
    printMemoryAddress(&xxx);
    std::cout << "\n";

    int x = 3;
    int y = 4;
    printMemoryAddress(&x);
    printMemoryAddress(&y);
    std::cout << "\n";

    printPointer(x, y);

    std::cout << "\n";

    int* myDynamicInteger = new int{55};
    printPointer(*myDynamicInteger);
    printMemoryAddress(myDynamicInteger);
    int* myDynamicInteger2 = new int{69};
    printPointer(*myDynamicInteger2);
    printMemoryAddress(myDynamicInteger2);
    int* myDynamicInteger3 = new int{69};
    printPointer(*myDynamicInteger3);
    printMemoryAddress(myDynamicInteger3);
    std::cout << "\n";
    std::cout << "Array\n";
    int myIntegerArray [10] = {1, 2, 3 };
    printMemoryAddress(&myIntegerArray[0]);
    printMemoryAddress(&myIntegerArray[1]);
    std::cout << (myIntegerArray[1] - myIntegerArray[0]);

    std::cout << "\n";
    std::cout << "Array using new\n";
    int* myIntegerArray2 = new int [10];
    printMemoryAddress(myIntegerArray2);
    printMemoryAddress(++myIntegerArray2);
}
