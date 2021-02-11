//
// Created by uddeepk on 2/11/21.
//

#include "Cave.hpp"
#include <sstream>
#include <algorithm>

using std::vector;
using std::string;
using std::istream;

void Cave::readRooms(istream &is) {
    std::string inputLine ;
    int n = 0;
    while (true) {
        string shortDescription, longDescription;

        if(!is)
            break;

        if(!getline(is, inputLine)) {
            std::cerr << "Error in data!" << std::endl;
            return;
        }//shortd

        if(isdigit(inputLine[0])) {
            std::cout << "Found number, next step break\n";
            break;
        }
        shortDescription = inputLine;

        inputLine = "";// Making easy to check failure of is.

        if(!getline(is, inputLine)) {
            std::cerr << "Error in data!" << std::endl;
            return;//longd
        }

        longDescription = inputLine;

        CaveNodePtr tempCaveNodePtr = std::make_shared<CaveNode>(shortDescription, longDescription, n);
        caveRooms.push_back(tempCaveNodePtr) ;
        ++n;
        //std::cout << tempCaveNodePtr->longdesc << " " << caveRooms[0]->longdesc << std::endl;
    }
//    std::cout << caveRooms[2] << std::endl;
    // Now we can use connect
    //std::cout << inputLine ;
    //Note that it already contains a string of numbers.
    do {
        std::istringstream iss (inputLine);

        int theRoomNumber ;
        iss >> theRoomNumber;
        if ( !iss) {
            //Error
            std::cerr << "Error in data!!" << std::endl;
            break;
        }
        int connectedRoom;
        while (iss >> connectedRoom) {
            //std::cout << connectedRoom << " ";
            connect(theRoomNumber, connectedRoom);
        }

    }while (getline(is, inputLine));


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