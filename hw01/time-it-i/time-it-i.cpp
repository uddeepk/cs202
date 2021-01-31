#include <iostream>
#include <chrono>
#include "StopWatch.hpp"
#include <memory>
#include <vector>

int main() {

    auto uniqueStopWatchPtr = std::make_unique<StopWatch>();
    //utilizing unique pointer to remember to utilize them.

    //std::cin.get();

    //test, search, binary_search, and two other algorithms in STL algorithm
    // on random integers or doubles created with mt19937 RNG.
    // Measure time for each algorithm atleast five times each for groups of 10 to 10 ^ 9

    std::vector<std::vector<double>> vecOfVecOfDbls ; //to store all the data

    std::cout << uniqueStopWatchPtr->getCurrentTimeInMilliseconds() << std::endl;
    return 0;
}
