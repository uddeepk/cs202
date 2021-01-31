#include <iostream>
#include <chrono>
#include "StopWatch.hpp"
#include <memory>
#include <vector>
#include <random>
#include <algorithm>

using std::cout;
using std::endl;

void getVector ( std::vector <unsigned int> &vecOfNumbers, std::mt19937 &myGenerator,
                 size_t numberOfObjects) ;

void getNeedle (std::vector <unsigned int> &myNeedle, const std::vector <unsigned int> & v);

int main() {

    auto uniqueStopWatchPtr = std::make_unique<StopWatch>();
    //utilizing unique pointer to remember to utilize them.

    //std::cin.get();

    //test, search, binary_search, and two other algorithms in STL algorithm
    // on random integers or doubles created with mt19937 RNG.
    // Measure time for each algorithm atleast five times each for groups of 10 to 10 ^ 9

    //mt19937 random number generator seeded
    std::mt19937 generator (std::chrono::system_clock::now().time_since_epoch().count());

    std::vector<unsigned int> vecOfNumbers ; //to store all the data
    size_t numberOfObjects = 10;

    for ( int i = 1 ; i <= 9 ; ++i) { // bcuz 10^1 to 10^9
        if ( i == 3 )
            break;
        //Get Vector
        uniqueStopWatchPtr->Start();
        getVector(vecOfNumbers, generator, numberOfObjects);
        uniqueStopWatchPtr->Stop();
        //Get time for algorithm 5 times ??

        //get needle for search
        std::vector<unsigned int> needle ;

        getNeedle(needle, vecOfNumbers);

        //search needle in hay stack

        auto it = std::search(vecOfNumbers.begin(), vecOfNumbers.end(), needle.begin(), needle.end());

        if(it != vecOfNumbers.end())
            cout <<"Successful search\n";
        else
            cout <<"Unsuccessful search\n";

        //cout << vecOfNumbers.size() << ", " << uniqueStopWatchPtr->getCurrentTimeInSeconds()<< endl;
        numberOfObjects *= 10;
    }


    //std::cout << generator() << std::endl;
    //std::cout <<generator() << std::endl;
    //std::cout << uniqueStopWatchPtr->getCurrentTimeInMilliseconds() << std::endl;
    return 0;
}

void getVector ( std::vector <unsigned int> &vecOfNumbers, std::mt19937 &myGenerator,
                 size_t numberOfObjects) {
    for ( auto i = vecOfNumbers.size() ; i < numberOfObjects ; ++i) {
        vecOfNumbers.push_back(myGenerator());
    }
}

void getNeedle (std::vector <unsigned int> &myNeedle, const std::vector <unsigned int> & v) {
    std::random_device rnd;
    std::mt19937 myGenerator(rnd());

    auto needleStartIndex = v.begin() + ( myGenerator() % v.size() );

    auto needleEndIndex = needleStartIndex + myGenerator() % (v.end() - needleStartIndex) ;

    myNeedle.insert (myNeedle.begin(), needleStartIndex, needleEndIndex);

}