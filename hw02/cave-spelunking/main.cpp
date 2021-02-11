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
        //Print description

        //Provide menu

        //Recive action and execute
    }

//    std::istringstream iss2 ( "5 6 7") ;
//
//    int test;
//    while( iss2 >> test) {
//        std::cout << test << " " ;
//    }

    return 0;
}
