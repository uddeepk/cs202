/*
 * main.cpp
 * Uddeep Karki
 * 3/12/2021
 * main source file for homework 3 additional program 1 book pretty printer
 */

#include <iostream>
#include <fstream>
#include "MyParagraph.hpp"
#include <algorithm>

using std::string;
using std::cout;

int main(int argc, char* argv[]) {
    // Passing fstream

    // BUt first we have to check if the correct number of arguments were passed
    if( argc == 3) {
        //Normal run
        // Check if arguments are valid
        // check fstream
        string fileName = argv[1];
        std::ifstream myFile(fileName);
        if (!myFile) {
            std::cerr << "Check file and filename!" << std::endl;
            return 1;
        }
        // else
        auto vecParagraphs {makeVecOfMyParagraph(myFile)};

        // check arguments
        string commandArgument = argv[2];
        if (std::all_of(commandArgument.begin(), commandArgument.end(), [](char c) { return isdigit(c); })) {
            // Is a numeric argument
            int characterPosition = std::stoi(commandArgument);
            prettyPrint(cout, vecParagraphs, characterPosition);
        } else {
            // is html ??
            if (commandArgument == "--html") {
                // yes print with paragraph tags
                prettyPrintHtml(cout, vecParagraphs);
            } else {
                // no then print error message
                std::cerr << "Invalid argument! Final argument should be a number or --html" << std::endl;
                return 1;
            }
        }
    }
    else {
        //Error message
        std::cerr << "Too " << (argc < 3 ?  "few": "many") << " arguments!" << std::endl;
        return 1;
    }

    return 0;
}
