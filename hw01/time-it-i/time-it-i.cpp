/*
 * Uddeep Karki
 * Hw01
 * CS 202
 * time-it-i
 * This program tests the processing times of 4 different algorithms on vectors of different sizes.
 * It runs through 5 trials of the program and pretty prints it at the end.
 *
 */

#include <iostream>
#include <chrono>
#include "StopWatch.hpp"
#include <memory>
#include <vector>
#include <random>
#include <algorithm>
#include "TimesForProcessing.hpp"



void getVector ( std::vector <unsigned int> &vecOfNumbers, std::mt19937 &myGenerator,
                 size_t numberOfObjects) ;

void getNeedle (std::vector <unsigned int> &myNeedle, const std::vector <unsigned int> & v);

int main() {

    auto uniqueStopWatchPtr = std::make_unique<StopWatch>();
    std::vector <std::unique_ptr<TimesForProcessing>> myRecordedTimes ;

    int n = 0;

    while ( n < 5) {
        auto myCurrentRecordedTime = std::make_unique<TimesForProcessing> (n) ;

        //mt19937 random number generator seeded
        std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());

        std::vector<unsigned int> vecOfNumbers; //to store all the data
        size_t numberOfObjects = 10;

        for (int i = 1; i <= 9; ++i) { // bcuz 10^1 to 10^9

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