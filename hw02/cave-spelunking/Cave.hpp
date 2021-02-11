//
// Created by uddeepk on 2/11/21.
//

#ifndef CAVE_SPELUNKING_CAVE_HPP
#define CAVE_SPELUNKING_CAVE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Cave {
//    friend bool operator==( const CaveNode &room1, const CaveNode &room2);
public:
    void getDescription();

    //what is the number of rooms in the cave?
    int size() const; // shouldn't it be int

    //return current room number
    int getCurrentRoom() const;

    // got to room in the cave complex
    void gotoRoom(int room);

    // which adjacent room? 0,1, or 2?
    void gotoAdjacentRoom(int roomIndex);

    // connect two rooms together
    void connect(int room1, int room2);

    // print the short description of the room
    void printLongDesc(int room) const;

    //save rooms to an output stream
    void saveRooms(std::ostream& os) const;

    // read rooms from an input stream
    void readRooms (std::istream& is);

private:
    struct CaveNode {
        CaveNode(std::string sdesc, std::string ldesc):shortdesc(sdesc), longdesc(ldesc) {} ;
        std::vector<std::shared_ptr<CaveNode>> adjacentRooms;
        std::string shortdesc; // a short description of this room
        std::string longdesc; // a long description of this room
        bool visited = false;
    };

    using CaveNodePtr = std::shared_ptr<CaveNode>;

    std::vector<CaveNodePtr> caveRooms;
    int currentRoom = 0; // Lets suppose this as the entrance and default value for ease.
};


#endif //CAVE_SPELUNKING_CAVE_HPP
