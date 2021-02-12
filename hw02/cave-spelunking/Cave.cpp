//
// Created by uddeepk on 2/11/21.
//

#include "Cave.hpp"
#include <sstream>
#include <algorithm>
#include <map>

using std::vector;
using std::string;
using std::istream;

void Cave::readRooms(istream &is) {

    int n = 0;
    vector <string> adjacentCaveRooms;

    std::map <CaveNodePtr , string> caveRoomAndAdjacentRooms;
    while (is.peek() != EOF) {
        string shortDescription, longDescription;

//        if(!is)
//            break;
        std::string inputLine ;
        getline(is, inputLine);
        if(inputLine.empty()) {
            std::cerr << "Error in data!" << std::endl;
            return;
        }//shortd

//        if(isdigit(inputLine[0])) {
//            std::cout << "Found number, next step break\n";
//            break;
//        }
        shortDescription = inputLine;

        inputLine.clear();// Making easy to check failure of is.
        getline(is, inputLine);

        if(inputLine.empty()) {
            std::cerr << "Error in data!" << std::endl;
            return;
        }

        longDescription = inputLine;

        inputLine.clear();
        getline(is, inputLine);
        if(inputLine.empty()) {
            std::cerr << "Error in data!" << std::endl;
            return;
        }
        bool visited ;
        CaveNodePtr tempCaveNodePtr = std::make_shared<CaveNode>(shortDescription, longDescription, visited, n);
        caveRooms.push_back(tempCaveNodePtr) ;

        inputLine.clear();

        getline(is, inputLine);
        if(inputLine.empty()) {
            std::cerr << "Error in data!" << std::endl;
            return;
        }
        adjacentCaveRooms.push_back(inputLine);
        ++n;
        //std::cout << tempCaveNodePtr->longdesc << " " << caveRooms[0]->longdesc << std::endl;
    }
//    std::cout << caveRooms[2] << std::endl;
    // Now we can use connect
    //std::cout << inputLine ;
    //Note that it already contains a string of numbers.
    if(caveRooms.size() != adjacentCaveRooms.size()) {
        std::cerr << "Error in the data, wrong number of rooms to info of adjacent rooms";
        exit(3);
    }

//    do {
    for ( int theRoomNumber = 0 ; theRoomNumber < n ; ++theRoomNumber ) {
        std::istringstream iss (adjacentCaveRooms[theRoomNumber]);

        //int theRoomNumber ;
        //iss >> theRoomNumber;
//        if ( !iss) {
//            //Error
//            std::cerr << "Error in data!!" << std::endl;
//            break;
//        }
        int connectedRoom;
        while (iss >> connectedRoom) {
            //std::cout << connectedRoom << " ";
            connect(theRoomNumber, connectedRoom);
        }

    } //while (getline(is, inputLine));


}

void Cave::connect(int room1, int room2) {
    auto firstRoom = caveRooms[room1];
    auto secondRoom = caveRooms[room2];

    if(std::find(firstRoom->adjacentRooms.begin(), firstRoom->adjacentRooms.end(), secondRoom)
    == firstRoom->adjacentRooms.end()) { // can I just use the address instead of the == operator?
        // ROom not yet recorded for adjacent room.
        firstRoom->adjacentRooms.push_back(secondRoom);
    }

    if(std::find(secondRoom->adjacentRooms.begin(), secondRoom->adjacentRooms.end(), firstRoom)
    == secondRoom->adjacentRooms.end()) {
        secondRoom->adjacentRooms.push_back(firstRoom);
    }

}

void Cave::getDescription() {
    auto presentCaveRoom = caveRooms[currentRoom];

    if ( presentCaveRoom->visited )
        std::cout << presentCaveRoom->shortdesc << std::endl;
    else
        printLongDesc(currentRoom);

    presentCaveRoom->visited = true;
    // I'm putting menu here
    int n = 0;
    for ( const auto &adjRoom : presentCaveRoom->adjacentRooms) {
        std::cout << n << ": " << adjRoom->shortdesc << "\n";
        ++n;
    }
}

void Cave::printLongDesc(int room) const {
    std::cout << caveRooms[currentRoom]->longdesc << std::endl;
}

void Cave::gotoAdjacentRoom(int roomIndex) {
    auto presentCaveRoom = caveRooms[currentRoom];

    if(roomIndex >= presentCaveRoom->adjacentRooms.size()) {

        std::cerr << "You look and realize that it is not a path! \n";
        std::cout << "You look around the room again for viable paths" << std::endl;
        return;
    }
    auto destinationRoom = presentCaveRoom->adjacentRooms[roomIndex];
    currentRoom = destinationRoom->roomNumber;

}