//
// Created by uddeepk on 2/1/21.
//

#include "Book.hpp"
#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>

using std::cout; using std::endl;
using std::string;
using std::ifstream;

Book::Book ( std::string fileName):_fileName(fileName) {
}

void Book::readTheBook (StopWatch &watch)  {
    //Read method
    //Read all three ways at the same time ??
    ifstream myFile ;

    //vector
    myFile.open(_fileName);
    if (myFile.fail()) {
        std::cerr << _fileName << " missing !" << endl;
        exit (3);
    }
    string inputLine ;

    // Into a single string, because, why not.

    watch.Start();
    while (myFile >> inputLine) {
        _wholeBookString += inputLine + " " ;
    }
    watch.Stop();
    myFile.close();

    myFile.open(_fileName);
    watch.Start();
    while (myFile >> inputLine) {
        if(!inputLine.empty())
            _bookTextVector.push_back(inputLine);
    }
    watch.Stop();
    cout << "Time to read into vector :" << watch.getCurrentTimeInMilliseconds() << endl;
    myFile.close();

    //list
    myFile.open(_fileName);
    watch.Start();
    while (myFile >> inputLine) {
        if(!inputLine.empty())
            _bookTextList.push_back(inputLine);
    }
    watch.Stop();
    cout << "Time to read into List :" << watch.getCurrentTimeInMilliseconds() << endl;
    myFile.close();

    //deque-
    myFile.open(_fileName);
    watch.Start();
    while (myFile >> inputLine) {
        if(!inputLine.empty())
            _bookTextList.push_back(inputLine);
    }
    watch.Stop();
    cout << "Time to read into Deque :" << watch.getCurrentTimeInMilliseconds() << endl;

    myFile.close();
    //If read in the same section, the output can be compared for the same book.

}

void Book::findRandomString(StopWatch &watch) {
    //First get random string.
    // Make random index and use vector because I feel it easiest.
    std::random_device rnd;
    std::mt19937 myGenerator (rnd());

    std::string myRandomString = _bookTextVector[myGenerator() % _bookTextVector.size()];
    cout << myRandomString << endl;
    watch.Start();
    std::size_t foundHere = _wholeBookString.find(myRandomString) ;
    watch.Stop();
    cout << foundHere << endl;
    watch.Start();

    watch.Stop();

}