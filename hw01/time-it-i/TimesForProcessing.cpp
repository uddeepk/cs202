//
// Created by Uddeep Karki on 2/3/21.
// Source file for the header. Notice that it has methods to pretty print using iostream and iomanip
//

#include "TimesForProcessing.hpp"
#include <iostream>
#include <iomanip>

TimesForProcessing::TimesForProcessing(int trialNumber):_trialNumber(trialNumber) {}

std::ostream& TimesForProcessing::printField (std::ostream &myOutputStream, std::vector<double> &v) {

    for ( const auto myData : v) {
        myOutputStream << std::setw(11) << myData;
    }
    return myOutputStream;
}
std::ostream& TimesForProcessing::printField (std::ostream &myOutputStream, std::vector<int> &v) {

    for ( const auto myData : v) {
        myOutputStream << std::setw(13) << myData;
    }
    return myOutputStream;
}
std::ostream& TimesForProcessing::displayData (std::ostream &os) {
    // Trial number  X
    // Number of objects x x x x
    // Time to Process   x x x x
    // Time to Search    x x x x
    // Time to Sort
    // Time to Binary
    // Time to Shuffle
    std::vector <int> numberOfObjects = { 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
    os << "Trial " << _trialNumber << "\n";
    os << std::setw(12) << "Size";
    printField(os, numberOfObjects) << "\n";
    os << std::setw(12) << "Processing";
    printField (os, _timeForFillingVector) << "\n";
    os << std::setw(12) << "Search";
    printField (os, _timeForSearch) << "\n";
    os << std::setw(12) << "Sort";
    printField(os, _timeForSort) << "\n";
    os << std::setw(12) << "BinarySearch";
    printField (os, _timeForBinary_Search) << "\n";
    os << std::setw(12) << "Shuffle";
    printField (os, _timeForShuffle) << "\n";

    return os;
}