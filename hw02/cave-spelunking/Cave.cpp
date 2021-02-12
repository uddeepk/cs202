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
    std::string inputLine;
    getline(is, inputLine);
    currentRoom = std::stoi(inputLine);
    int n = 0;
    vector <string> adjacentCaveRooms;

    std::map <CaveNodePtr , string> caveRoomAndAdjacentRooms;
    while (is.peek() != EOF) {
        string shortDescription, longDescription;

        inputLine.clear();
        getline(is, inputLine);
        if(inputLine.empty()) {
            continue;
        }
        shortDescription = inputLine;

        inputLine.clear();// Making easy to check failure of is.
        getline(is, inputLine);

        if(inputLine.empty()) {
            std::cerr << "Error in data!" << std::endl;
            exit(3);
        }

        longDescription = inputLine;

        inputLine.clear();
        getline(is, inputLine);
        if(inputLine.empty()) {
            std::cerr << "Error in data!" << std::endl;
            exit(3);
        }
        bool visited ;
        CaveNodePtr tempCaveNodePtr = std::make_shared<CaveNode>(shortDescription, longDescription, visited, n);
        caveRooms.push_back(tempCaveNodePtr) ;

        inputLine.clear();

        getline(is, inputLine);
        if(inputLine.empty()) {
            std::cerr << "Error in data!" << std::endl;
            exit(3);
        }
        adjacentCaveRooms.push_back(inputLine);

        caveRoomAndAdjacentRooms[tempCaveNodePtr] = inputLine;
        ++n;
    }
    if (caveRoomAndAdjacentRooms.size() == 0) {
        std::cerr << "Error in Data." ;
        exit(3);
    }
    for (auto &[roomPtr, adjacentRoomsIndex]:caveRoomAndAdjacentRooms ) {
        std::istringstream iss (adjacentRoomsIndex);

        int connectedRoom;
        while (iss >> connectedRoom) {
            connect(roomPtr->roomNumber, connectedRoom); // This is redundant. I can easily use the roomPtr
        }
    }
}

void Cave::connect(int room1, int room2) {
    auto firstRoom = caveRooms[room1];
    auto secondRoom = caveRooms[room2];

    if(std::find(firstRoom->adjacentRooms.begin(), firstRoom->adjacentRooms.end(), secondRoom)
    == firstRoom->adjacentRooms.end()) { // can I just use the address instead of the == operator?
        // ROom not yet recorded for adjacent room.
        firstRoom->adjacentRooms.push_back(secondRoom);
    }
}

void Cave::getDescription() {
    auto presentCaveRoom = caveRooms[currentRoom];
    std::cout << presentCaveRoom->shortdesc << std::endl;

    if ( !presentCaveRoom->visited )
        printLongDesc(currentRoom);

    presentCaveRoom->visited = true;
    // I'm putting part of menu here
    int n = 0;
    for ( const auto &adjRoom : presentCaveRoom->adjacentRooms) {
        std::cout << n << ": " << adjRoom->shortdesc << "\n";
        ++n;
    }
}

void Cave::printLongDesc(int room) const {
    beautifyOutput(std::cout, caveRooms[currentRoom]->longdesc) << std::endl;
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

void Cave::saveRooms(std::ostream &os) const {
    os << currentRoom ;

    for(const auto &caveData : caveRooms) {
        os << "\n";
        os << caveData->shortdesc << "\n";
        os << caveData->longdesc << "\n";
        os << caveData->visited << "\n";

        for(const auto &room : caveData->adjacentRooms) {
            os << room->roomNumber << " ";
        }
    }
}

std::ostream& beautifyOutput ( std::ostream &os, const std::string &s) {
    for(size_t index = 0 ; index < s.length() ; ++index) {
        if(index % 74 == 0)
            os << "\n";
        os << s[index] ;

    }
    return os;
}

void getMenu() {
    std::cout << "6: Save Rooms\n";
    std::cout << "9: Quit\n";
}
