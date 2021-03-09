/*
 * main.cpp
 * Uddeep Karki
 * 2/17/21
 * Contains main(...) to run the program for hw03
 */

#include <iostream>
#include <fstream>
#include "TokenAndPosition.hpp"
#include "StopWatch.hpp"

using std::istringstream;
using std::ifstream;
using std::string;

int main(int argc, char** argv) {
    ifstream inputFile ;
    string fileName, commandArgument;
    StopWatch myAwesomeStopWatch;

    // 2 or 3 arguments
    if ( argc == 2 || argc == 3) {
        // 3 arguments
        if ( argc == 3) {
            // is 3rd argument --lineonly
            commandArgument = argv[2];
            if(commandArgument != "--lineonly" ) {
                std::cerr << "Unrecognized command " << commandArgument << std::endl;
                return 1;
            }
        }
        fileName = argv[1];
        inputFile.open(fileName);
        // is fstream working?
        if(!inputFile) {
            std::cerr << "Error with input file! " << std::endl;
            if(inputFile.fail())
                std::cerr << "Check file location, or filename. " << std::endl;
            return 1;
        }
        myAwesomeStopWatch.Start();
        auto vecTokens { readLines(inputFile)};
        // Check command argument
        if( commandArgument != "--lineonly")
            printTokens(std::cout, vecTokens);
        myAwesomeStopWatch.Stop();
        std::cout << "Time Taken: " << myAwesomeStopWatch.getCurrentTimeInMilliseconds() << "ms\n";

    } else {
        std::cerr << "Incorrect number of arguments! " << std::endl;
        return 1;
    }
    return 0;
}
