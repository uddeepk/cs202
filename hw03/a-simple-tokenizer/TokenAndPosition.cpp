//
// Created by uddeepk on 2/17/21.
//

#include "TokenAndPosition.hpp"
#include <sstream>

using std::vector;
using std::string;
using std::istream;
using std::istringstream;
//vector <string> lineToTokens ( const string &line) {
//
//}

vector<TokenAndPosition> readLines (istream &is) {
    // Need line counter
    string inputBuffer;
    vector<TokenAndPosition> myTokens;
    while (getline(is, inputBuffer)) {
        istringstream iss(inputBuffer);

        string tempBuffer;

        iss >> tempBuffer;
        std::cout << iss.tellg() << std::endl;

    }
    return myTokens;
}