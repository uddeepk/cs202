#include <iostream>
#include <string>
#include "Cave.hpp"
#include <fstream>
using std::cout;
using std::endl;

int main() {
    Cave myCave;

    std::ifstream myCaveLayout;
    while (true){
        std::cout << "Do you want to start a new game ? (yes/no) ";
        std::string userChoice;
        getline(std::cin, userChoice);
        if ( userChoice == "no") {
            myCaveLayout.open("saved-cave-layout.txt");
            if(myCaveLayout.fail()) {
                std::cerr << "Save file corrupt." << endl;
                cout << "Starting new game" << endl;
                myCaveLayout.open("cave-layout.txt");
            }
            break;
        } else if (userChoice == "yes") {
            myCaveLayout.open("cave-layout.txt");
            break;
        } else {
            std::cout << "Please pick the proper choice" <<std::endl;
        }
    }
    if(!myCaveLayout) {
        if(myCaveLayout.eof()) {
            std::cerr << "File empty" << endl;
        }
        if(myCaveLayout.fail()) {
            std::cerr << "Check FIle" << endl;
        }
        exit (3);
    }

    std::string welcomeMessage;
    getline(myCaveLayout, welcomeMessage);
    beautifyOutput(cout, welcomeMessage) << endl;

    myCave.readRooms(myCaveLayout);

    myCaveLayout.close();

    while(true) {
        int userInput ;

        //Print description
        myCave.getDescription();
        //Provide menu
        getMenu();

        //Recive action and execute
        std::cout << "Enter your choice: " ;
        std::cin >> userInput;
        if(userInput == 9)
            break;

        if(userInput >=0 && userInput < 3) {
            myCave.gotoAdjacentRoom(userInput); // validity checks inside the method ? cool
        }
    }

    return 0;
}
