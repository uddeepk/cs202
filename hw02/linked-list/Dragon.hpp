//Uddeep Karki
//Hw02
//Dragon
//This is the header for the Dragon class. It has 6? attributes.
//The basis of the stats are from the Harry Potter Universe


#ifndef LINKED_LIST_DRAGON_HPP
#define LINKED_LIST_DRAGON_HPP

#include <string>
#include <vector>

struct Dragon {
    Dragon () = delete; // disabling default constructor
    Dragon ( std::vector <std::string> &dragonAttributes) ; //constructor with vector
    Dragon ( std::string breed, std::string eyeColor, std::string skinColor,
    std::string nativeLocation, std::string affiliation, unsigned int length);


    //Half dozen fields
    const std::string _breed;
    const std::string _eyeColor;
    const std::string _skinColor;
    const std::string _nativeLocation; //Country it is native in
    const std::string _affiliation; //Preservation areas set for protection and study of dragons
    //Height
    const unsigned int _length; //Length of an average adult


};


#endif //LINKED_LIST_DRAGON_HPP
