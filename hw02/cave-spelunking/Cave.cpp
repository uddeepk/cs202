//
// Created by uddeepk on 2/11/21.
//

#include "Cave.hpp"
//#include <vector>
//#include <string>

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
    }

}