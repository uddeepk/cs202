#include <iostream>
#include <vector>
#include <string>
#include "Cave.hpp"
#include <sstream>

int main() {
    Cave myCave;

    std::istringstream iss ("short1\nlong1\n0\n1 2\nshort2\nlong2\n0\n 2\nshort3\nlong3\n0\n 1\n");

    myCave.readRooms(iss);

    while(true) {
        int userInput ;

        //Print description
        myCave.getDescription();
        //Provide menu

        //Recive action and execute
        std::cout << "Enter your choice: " ;
        std::cin >> userInput;
        if(userInput == 9)
            break;

        if(userInput >=0 && userInput < 3) {
            myCave.gotoAdjacentRoom(userInput); // validity checks inside the method ? cool
        }
    }

//    std::istringstream iss2 ( "5 6 7") ;
//
//    int test;
//    while( iss2 >> test) {
//        std::cout << test << " " ;
//    }

    return 0;
}
