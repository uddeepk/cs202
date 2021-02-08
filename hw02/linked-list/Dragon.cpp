//
// Uddeep Karki
// Hw02
// Dragon.cpp
// This is the source file for the Dragon header
// It contains the definitions of the constructors, and member funcitons for the class
//

#include "Dragon.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

Dragon::Dragon (vector <string> &dragonAttributes): _breed(dragonAttributes[0]),
                _eyeColor(dragonAttributes[1]), _skinColor(dragonAttributes[2]),
                _nativeLocation(dragonAttributes[3]), _affiliation(dragonAttributes[4]),
                _length(static_cast<unsigned int>(std::stoi(dragonAttributes[5]))),
                _name(dragonAttributes[6]) {
    // Constructor with a vector
}

Dragon::Dragon ( string breed, string eyeColor, string skinColor, string nativeLocation,
                 string affiliation, unsigned int length, string name):
                 _breed(breed), _eyeColor(eyeColor), _skinColor(skinColor),
                 _nativeLocation(nativeLocation), _affiliation(affiliation),
                 _length(length), _name(name) {
    // Constructor with the constructors passed
}

bool Dragon::operator<(const Dragon &dragon2) {
    if( _breed < dragon2._breed) {
        return true;
    }
    if (_breed == dragon2._breed && _name < dragon2._name) {
        return true;
    }

    return false;
}