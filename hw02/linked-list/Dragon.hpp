//Uddeep Karki
//Hw02
//Dragon.hpp
//This is the header for the Dragon class. It has 7 attributes.
//The basis of the stats are from the Harry Potter Universe


#ifndef LINKED_LIST_DRAGON_HPP
#define LINKED_LIST_DRAGON_HPP

#include <string>

struct Dragon {
    Dragon () = delete; // disabling default constructor
    Dragon ( std::string breed, std::string eyeColor, std::string skinColor,
    std::string nativeLocation, std::string affiliation, unsigned int length, std::string name);
    Dragon (const Dragon &); // Copy constructor
    ~Dragon();
    // Overload < operator for using sort on std::list container
    bool operator<(const Dragon &dragon2);

    std::ostream& myPrintDragon (std::ostream&);
    //Half dozen fields
    const std::string _breed;
    const std::string _eyeColor;
    const std::string _skinColor;
    const std::string _nativeLocation; //Country it is native in
    const std::string _affiliation; //Preservation areas set for protection and study of dragons
    //Height
    unsigned int _length; //Length of an average adult
    const std::string _name;
};

bool operator==( const Dragon& d1, const Dragon&d2);

#endif //LINKED_LIST_DRAGON_HPP
