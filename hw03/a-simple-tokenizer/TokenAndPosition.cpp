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
TokenAndPosition::TokenAndPosition(const std::string &token, int &line, unsigned int column):_token(token), _line(line),_column(column)  {}

vector<TokenAndPosition> readLines (istream &is) {
    // Need line counter
    int lineCounter = 1;
    string inputBuffer;
    vector<TokenAndPosition> myTokens;
    while (getline(is, inputBuffer)) {
        istringstream iss(inputBuffer);


        while (true) {
            // Traverse white space ??
            while( iss.peek() == ' ')
                iss.get();

            string tempBuffer;
            unsigned int position = iss.tellg() ; //unsigned int to modify the value
            iss >> tempBuffer;

            if(tempBuffer == "\r" || tempBuffer.empty())
                break;

            std::cout << lineCounter << " " << (position + 1)<< " " << tempBuffer << std::endl;
            myTokens.push_back(TokenAndPosition(tempBuffer, lineCounter,position + 1  ));
            if(!iss)
                break;
        }
        ++lineCounter;
    }
    return myTokens;
}