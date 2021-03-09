#include <iostream>
#include <fstream>
#include "TokenAndPosition.hpp"
#include "StopWatch.hpp"

using std::istringstream;
using std::ifstream;
using std::string;

int main(int argc, char** argv) {
//    std::istringstream testIss("Hello, World! \n ifthere asdf");
//    auto myTestTokens  {readLines(testIss)};
//    printTokens(std::cout , myTestTokens);
//    testIss.clear();
//    testIss.str("n 1 6 berry\n\n"
//            " vc 255 0 0");
//    auto myTestTokens2 { readLines(testIss)};
//    printTokens(std::cout , myTestTokens2);

    ifstream inputFile ;
    string fileName, commandArgument;
//    bool withPrinting = true;



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
        // is fstream working?
        fileName = argv[1];
        inputFile.open(fileName);
        if(!inputFile) {
            std::cerr << "Error with input file! " << std::endl;
            if(inputFile.fail())
                std::cerr << "Check file location, or filename. " << std::endl;
            if (inputFile.eof())
                std::cerr << "No data in file. " << std::endl;
            return 1;
        }
        auto vecTokens { readLines(inputFile)};
        // Check command argument
        if( commandArgument != "--lineonly")
            printTokens(std::cout, vecTokens);
    } else {
        std::cerr << "Incorrect number of arguments! " << std::endl;
        return 1;
    }




    // Incorrect number of args

    return 0;
}
