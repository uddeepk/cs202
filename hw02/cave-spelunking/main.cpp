#include <iostream>
#include <vector>
#include <string>
#include "Cave.hpp"
#include <sstream>

int main() {
    Cave myCave;

    std::istringstream iss ("Longd\nShortd\nLongD2\nShortD2\nLong3\nShort3\n0 1\n1 2");

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
    }

//    std::istringstream iss2 ( "5 6 7") ;
//
//    int test;
//    while( iss2 >> test) {
//        std::cout << test << " " ;
//    }

    return 0;
}
