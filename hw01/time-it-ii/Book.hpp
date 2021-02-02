//
// Created by uddeepk on 2/1/21.
//

#ifndef TIME_IT_II_BOOK_HPP
#define TIME_IT_II_BOOK_HPP

#include "../time-it-i/StopWatch.hpp"
#include <string>
#include <vector>
#include <list>
#include <deque>

struct Book {
    // Members Using struct and making all public to easily see use of stopwatch
    std::string _fileName; //can use this like ifstream.open( _fil..me)
    std::string _wholeBookString;
    std::vector <std::string> _bookTextVector;
    std::list <std::string> _bookTextList;
    std::deque <std::string> _bookTextDeque;

    std::vector <double> _readTimes;
    std::vector <double> _findTimes ;
    //Constructors
    Book () = delete ; //disabling the default constructor
    Book (std::string fileName);

    void readTheBook(StopWatch &watch);
    void findRandomString (StopWatch &watch);
    void sortContainers(StopWatch &watch);
};


#endif //TIME_IT_II_BOOK_HPP
