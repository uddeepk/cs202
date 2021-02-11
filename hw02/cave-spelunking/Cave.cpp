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
    while (true) {
        string shortDescription, longDescription;
        if(!is)
            break;
        getline(is, inputLine);//shortd
        if(isdigit(inputLine[0])) {
            std::cout << "Found number, next step break\n";
            break;
        }
        getline(is, inputLine);//longd
        CaveNodePtr tempCaveNodePtr = std::make_shared<CaveNode>(shortDescription, longDescription);
        caveRooms.push_back(tempCaveNodePtr) ;
//        std::cout << tempCaveNodePtr << " " << caveRooms[0] << std::endl;
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
        }
        int connectedRoom;
        while (iss >> connectedRoom) {
            std::cout << connectedRoom << " ";
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


//bool operator==(const Cave::CaveNode &room1, const Cave::CaveNode &room2) {
//    return (room1.shortdesc == room2.shortdesc && room1.longdesc == room2.longdesc);
//}
