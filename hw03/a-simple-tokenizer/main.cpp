#include <iostream>
#include <sstream>

#include <fstream>
#include "TokenAndPosition.hpp"

using std::istringstream;
using std::ifstream;

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
    bool withPrinting = true;
    // 3 args
    if ( argc == 3) {
        // is 3rd argument --lineonly
        if(argv[2] == "--lineonly" )
            withPrinting = false;
        else {
            std::cerr << "Invalid argument!" << std::endl;
            return 1;
        }
    }
    // 2 or more args
    if ( argc == 2 || argc == 3) {
        // is fstream working?
        inputFile.open(argv[1]);
        if(!inputFile) {
            std::cerr << "Error with input file! " << std::endl;
            if(inputFile.fail())
                std::cerr << "Check file location, or filename. " << std::endl;
            if (inputFile.eof())
                std::cerr << "No data in file. " << std::endl;
            return 1;
        }

    }




    // Incorrect number of args

    return 0;
}
