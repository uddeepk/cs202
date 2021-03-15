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
    string fileName, commandArgument;
    std::ifstream myFile;
    std::vector<MyParagraph> vecParagraphs;
    switch(argc) {
        case 3:
            //Normal run
            // Check if arguments are valid
            // check fstream
            fileName = argv[1];
            myFile.open (fileName);
            if (!myFile) {
                std::cerr << "Check file and filename!" << std::endl;
                return 1;
            }
            // else
            vecParagraphs = makeVecOfMyParagraph(myFile);

            // check arguments
            commandArgument = argv[2];
            if ( std::all_of(commandArgument.begin(), commandArgument.end(), [](char c) { return isdigit(c);})) {
                // Is a numeric argument
                prettyPrint(vecParagraphs, std::stoi(commandArgument));
            }
            else {
                // is html ??
                if ( commandArgument == "--html") {
                    // yes print with paragraph tags
                }
                else {
                    // no then print error message
                    std::cerr << "Invalid argument! Final argument should be a number or --html" << std::endl;
                    return 1;
                }
            }
            break;
        default:
            //Error message
            std::cerr << "Invalid number of arguments!" << std::endl;
            return 1;
            break; // not required
    }

    return 0;
}
