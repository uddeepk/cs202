//
// Created by uddeepk on 2/1/21.
//

#include "Book.hpp"
#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include <cstring>
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
        std::cerr << _fileName << " missing ! Please fix or change source code!" << endl;
        exit (3); //if istream fails then program exits.
    }
    string inputLine ;

    // Into a single string, because, why not.

    watch.Start();
    while (getline(myFile, inputLine)) { // How to change this to std::getline ???
        if(!inputLine.empty())
            _wholeBookString += inputLine + "\n"; // In case I need output
    }
    watch.Stop();
    //cout << _wholeBookString ;
    _readTimes.push_back(watch.getCurrentTimeInMilliseconds());
    myFile.close();

    myFile.open(_fileName);
    watch.Start();
    while (getline(myFile, inputLine)) {
        if(!inputLine.empty())
            _bookTextVector.push_back(inputLine);
    }
    watch.Stop();
    _readTimes.push_back(watch.getCurrentTimeInMilliseconds());
    myFile.close();

    //list
    myFile.open(_fileName);
    watch.Start();
    while (getline(myFile, inputLine)) {
        if(!inputLine.empty())
            _bookTextList.push_back(inputLine);
    }
    watch.Stop();
    _readTimes.push_back(watch.getCurrentTimeInMilliseconds());
    myFile.close();

    //deque-
    myFile.open(_fileName);
    watch.Start();
    while (getline(myFile, inputLine)) {
        if(!inputLine.empty())
            _bookTextDeque.push_back(inputLine);
    }
    watch.Stop();
    _readTimes.push_back(watch.getCurrentTimeInMilliseconds());
    myFile.close();

}

void Book::findRandomString(StopWatch &watch) {
    //First get random string.
    // Make random index and use vector because I feel it easiest.
    std::random_device rnd;
    std::mt19937 myGenerator (rnd());

    std::string myRandomString = _bookTextVector[myGenerator() % _bookTextVector.size()];

    //String :)
    watch.Start();
    _wholeBookString.find(myRandomString) ;
    watch.Stop();
    _findTimes.push_back(watch.getCurrentTimeInMilliseconds());

    //Vector
    watch.Start();
    std::find(_bookTextVector.begin(), _bookTextVector.end(), myRandomString) ;
    watch.Stop();
    _findTimes.push_back(watch.getCurrentTimeInMilliseconds());

    //List
    watch.Start();
    std::find( _bookTextList.begin() , _bookTextList.end(), myRandomString) ;
    watch.Stop();
    _findTimes.push_back(watch.getCurrentTimeInMilliseconds());

    //Deque
    watch.Start();
    std::find ( _bookTextDeque.begin(), _bookTextDeque.end(), myRandomString) ;
    watch.Stop();
    _findTimes.push_back(watch.getCurrentTimeInMilliseconds());

}

void Book::sortContainers(StopWatch &watch) {

    watch.Start();
    std::sort(_bookTextVector.begin(), _bookTextVector.end());
    watch.Stop();
    _sortTimes.push_back(watch.getCurrentTimeInMilliseconds());

    watch.Start();
    _bookTextList.sort();
    watch.Stop();
    _sortTimes.push_back(watch.getCurrentTimeInMilliseconds());

    watch.Start();
    std::sort(_bookTextDeque.begin(), _bookTextDeque.end());
    watch.Stop();
    _sortTimes.push_back(watch.getCurrentTimeInMilliseconds());

}