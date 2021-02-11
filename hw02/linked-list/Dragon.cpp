//
// Uddeep Karki
// Hw02
// Dragon.cpp
// This is the source file for the Dragon header
// It contains the definitions of the constructors, and member funcitons for the class
//

#include "Dragon.hpp"
#include <string>
#include <iostream>

using std::string;

Dragon::Dragon ( string breed, string eyeColor, string skinColor, string nativeLocation,
                 string affiliation, unsigned int length, string name):
                 _breed(breed), _eyeColor(eyeColor), _skinColor(skinColor),
                 _nativeLocation(nativeLocation), _affiliation(affiliation),
                 _length(length), _name(name) {
    // Constructor with the constructors passed
}

Dragon::Dragon( const Dragon& d1):
                _breed(d1._breed), _eyeColor(d1._eyeColor), _skinColor(d1._skinColor),
                _nativeLocation(d1._nativeLocation), _affiliation(d1._affiliation),
                _length(d1._length), _name(d1._name) {

}
Dragon::~Dragon() {
    // Hi! :)
}
bool Dragon::operator<(const Dragon &dragon2) {
    //I only care about breed and name. The other stats are average...
    if( _breed < dragon2._breed) {
        return true;
    }
    if (_breed == dragon2._breed) {
        if(_name < dragon2._name || _length < dragon2._length)
            return true;
    }
    return false;
}
std::ostream& Dragon::myPrintDragon (std::ostream& os) {
    os << "\nBreed: " << _breed << "\n";
    os << "Eye Color: " << _eyeColor << "\n";
    os << "Skin Color: " << _skinColor << "\n";
    os << "Native Location: " << _nativeLocation << "\n";
    os << "Affiliation: " << _affiliation << "\n";
    os << "Length: " << _length << "\n";
    os << "Name: " << _name << "\n";
    return os;
}

bool operator==( const Dragon& d1, const Dragon&d2) {
    return (d1._breed == d2._breed && d1._breed == d2._breed && d1._eyeColor == d2._eyeColor && d1._skinColor == d2._skinColor
            && d1._nativeLocation==d2._nativeLocation && d1._affiliation == d2._affiliation && d1._length == d2._length &&
            d1._name == d2._name);
}