#include <iostream>
#include <chrono>
#include "StopWatch.hpp"
#include <memory>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>

struct TimesForProcessing {
    TimesForProcessing(int trialNumber);

    int _trialNumber;
    std::vector <double> _timeForFillingVector;
    std::vector <double> _timeForSearch;
    std::vector <double> _timeForSort;
    std::vector <double> _timeForBinary_Search;
    std::vector <double> _timeForShuffle;

    std::ostream &displayData(std::ostream &os) ;
    std::ostream &printField ( std::ostream &myOutputStream, std::vector <double> &v);
    std::ostream &printField ( std::ostream &myOutputStream, std::vector <int> &v);
};
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
using std::cout;
using std::endl;

void getVector ( std::vector <unsigned int> &vecOfNumbers, std::mt19937 &myGenerator,
                 size_t numberOfObjects) ;

void getNeedle (std::vector <unsigned int> &myNeedle, const std::vector <unsigned int> & v);

int main() {

    auto uniqueStopWatchPtr = std::make_unique<StopWatch>();
    std::vector <std::unique_ptr<TimesForProcessing>> myRecordedTimes ;
    //utilizing unique pointer just to do it.

    //std::cin.get();

    //test, search, binary_search, and two other algorithms in STL algorithm
    // on random integers or doubles created with mt19937 RNG.
    // Measure time for each algorithm atleast five times each for groups of 10 to 10 ^ 9


    int n = 0;

    while ( n < 5) {
        auto myCurrentRecordedTime = std::make_unique<TimesForProcessing> (n) ;

        //mt19937 random number generator seeded
        std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());

        std::vector<unsigned int> vecOfNumbers; //to store all the data
        size_t numberOfObjects = 10;

        for (int i = 1; i <= 9; ++i) { // bcuz 10^1 to 10^9
            cout << "Size " << numberOfObjects << " : \n";
            if ( i == 3 )
            break;
            //Get Vector
            uniqueStopWatchPtr->Start();
            getVector(vecOfNumbers, generator, numberOfObjects);
            uniqueStopWatchPtr->Stop();
            myCurrentRecordedTime->_timeForFillingVector.push_back(uniqueStopWatchPtr->getCurrentTimeInMilliseconds());
            //Get time for algorithm 5 times ??

            //get needle for search
            std::vector<unsigned int> needle;

            getNeedle(needle, vecOfNumbers);

            //search needle in hay stack

            uniqueStopWatchPtr->Start();
            std::search(vecOfNumbers.begin(), vecOfNumbers.end(), needle.begin(), needle.end());
            uniqueStopWatchPtr->Stop();

            myCurrentRecordedTime->_timeForSearch.push_back(uniqueStopWatchPtr->getCurrentTimeInMilliseconds());



            //sorting for binary_search and also using it as a run
            uniqueStopWatchPtr->Start();
            std::sort(vecOfNumbers.begin(), vecOfNumbers.end());
            uniqueStopWatchPtr->Stop();

            myCurrentRecordedTime->_timeForSort.push_back(uniqueStopWatchPtr->getCurrentTimeInMilliseconds());

            //binary_search with sorted vector
            //get random number, i am using first element of the needle
            auto myNumberForBinarySearch = *(needle.begin());

            uniqueStopWatchPtr->Start();
            std::binary_search(vecOfNumbers.begin(), vecOfNumbers.end(), myNumberForBinarySearch);
            uniqueStopWatchPtr->Stop();

            myCurrentRecordedTime->_timeForBinary_Search.push_back(uniqueStopWatchPtr->getCurrentTimeInMilliseconds());

            // SHuffle
            std::random_device rd;
            std::mt19937 myTempGenerator(rd());

            uniqueStopWatchPtr->Start();
            std::shuffle(vecOfNumbers.begin(), vecOfNumbers.end(), myTempGenerator);
            uniqueStopWatchPtr->Stop();

            myCurrentRecordedTime->_timeForShuffle.push_back(uniqueStopWatchPtr->getCurrentTimeInMilliseconds());

            numberOfObjects *= 10;
            cout << "\n";
            if (numberOfObjects > 10000000)
                break;
        }
        myRecordedTimes.push_back(std::move(myCurrentRecordedTime));
        ++n;
    }

    for (const auto &record : myRecordedTimes) {
        record->displayData(std::cout);
    }
    return 0;
}

void getVector ( std::vector <unsigned int> &vecOfNumbers, std::mt19937 &myGenerator,
                 size_t numberOfObjects) {
    for ( auto i = vecOfNumbers.size() ; i < numberOfObjects ; ++i) {
        vecOfNumbers.push_back(myGenerator());
    }
}

void getNeedle (std::vector <unsigned int> &myNeedle, const std::vector <unsigned int> & v) {
    // Makes a random needle
    std::random_device rnd;
    std::mt19937 myGenerator(rnd());

    auto needleStartIndex = v.begin() + ( myGenerator() % v.size() );

    auto needleEndIndex = needleStartIndex + myGenerator() % (v.end() - needleStartIndex) ;

    myNeedle.insert (myNeedle.begin(), needleStartIndex, needleEndIndex);

    if(myNeedle.empty())
        getNeedle(myNeedle, v);

}