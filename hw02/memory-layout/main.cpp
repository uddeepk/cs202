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
    int* j = new int{123};
    std::cout << "&j = " << &j << "\n";
    delete j;
}
void printMemoryAddress(int* i, std::string variableName ) {
    //std::cout << "i = " << *i << "\n";
    std::cout << "address of " << variableName <<" = " << i << "\n";
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

void recursieCrash (int* i, int n) {
    if(n == 5)
        return;
    int* j = new int{5};
    std::cout << i << " " << j << "\n" ;

    recursieCrash(i, ++n);
}

void allocatingToStack ( int i, int j, int k, int l, int m) {
    int* iptr = &i;
    int* jptr = &j;
    int* kptr = &k;
    int* lptr = &l;
    int* mptr = &m;
    // the unary * operator dereferences the pointer
    std::cout << "i = " << *iptr << "\n";
    std::cout << "&i = " << iptr << "\n";
    std::cout << "j = " << *jptr << "\n";
    std::cout << "&j = " << jptr << "\n";
    std::cout << "k = " << *kptr << "\n";
    std::cout << "&k = " << kptr << "\n";
    std::cout << "l = " << *lptr << "\n";
    std::cout << "&l = " << lptr << "\n";
    std::cout << "m = " << *mptr << "\n";
    std::cout << "&m = " << mptr << "\n";
//    std::cout << "j = " << *jptr << "\n";
//    std::cout << "&j = " << jptr << "\n";
}
namespace {
    int insideNamespace = 1;
    int secondNamespace = 23;
}
static int g_anAnswerToLife = 42;
static int g_secondAnswerToLife = 42;
int main() {
    std::cout << "Static\n" ;
    printPointer(insideNamespace);
    printMemoryAddress(&insideNamespace, "insideNamespace");
    printMemoryAddress(&secondNamespace, "secondNamespace");
    std::cout << "\n";
    printPointer(g_anAnswerToLife);
    printMemoryAddress(&g_anAnswerToLife, "anAnswerToLife");
    printPointer(g_secondAnswerToLife);
    printMemoryAddress(&g_secondAnswerToLife, "secondAnswerToLife");

    std::cout << "\n";

    std::cout << "Variables in main module\n" ;
    int x = 3;
    int y = 4;
    printPointer(x, y);
    printMemoryAddress(&x, "x");
    printMemoryAddress(&y, "y");
    std::cout << "\n";



    std::cout << "\n";
    std::cout << "Variables initialized with new:\n";
    int* myDynamicInteger = new int{55};
    printPointer(*myDynamicInteger);
    printMemoryAddress(myDynamicInteger, "myDynamicInteger");
    int* myDynamicInteger2 = new int{69};
    printPointer(*myDynamicInteger2);
    printMemoryAddress(myDynamicInteger2, "myDynamicInteger2");
    int* myDynamicInteger3 = new int{69};
    printPointer(*myDynamicInteger3);
    printMemoryAddress(myDynamicInteger3, "myDynamicInteger3");
    delete myDynamicInteger;
    delete myDynamicInteger2;
    delete myDynamicInteger3;

    std::cout << "\n";

    std::cout << "Array\n";
    int myIntegerArray [10] = {1, 2, 3 };
    for ( size_t index = 0 ; index < 10 ; ++index) {
        std::string referenceName = "myIntegerArray[" + std::to_string(index) + "]";
        printMemoryAddress(&myIntegerArray[index], referenceName);
    }

    //std::cout << (myIntegerArray[1] - myIntegerArray[0]);

    std::cout << "\n";
    std::cout << "Array using new\n";
    int* myIntegerArray2 = new int [10];
    for ( size_t index = 0 ; index < 10 ; ++index) {
        std::string referenceName = "myIntegerArray2[" + std::to_string(index) + "]";
        printMemoryAddress(&myIntegerArray2[index], referenceName);
    }
    delete [] myIntegerArray2;

    std::cout << "\n" ;
    std::cout << "Recursively \n";
    int myInt = 13;
    recursieCrash(&myInt, 0);
    //Figure out how to turn off compiler optimiztion
    std::cout << "\n";
    std::cout << "When passing many varibales copy by value, notice how they"
                 " get allocated on the stack\n" ;
    allocatingToStack(x, y, myInt, g_anAnswerToLife, g_secondAnswerToLife);
    return 0;
}
