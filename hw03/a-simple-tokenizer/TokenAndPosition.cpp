//
// Created by uddeepk on 2/17/21.
//

#include "TokenAndPosition.hpp"
#include <sstream>
#include <iomanip>

using std::vector;
using std::string;
using std::istream;
using std::ostream;
using std::istringstream;
//vector <string> lineToTokens ( const string &line) {
//
//}
TokenAndPosition::TokenAndPosition(const string &token, const int &line, const unsigned int &column):_token(token), _line(line),_column(column)  {}

vector<TokenAndPosition> readLines (istream &is) {
    // Need line counter
    int lineCounter = 1;
    string inputBuffer;
    vector<TokenAndPosition> myTokens;
    while (getline(is, inputBuffer)) {
        istringstream iss(inputBuffer);

        while (true) {
            // Traverse white space
            while( iss.peek() == ' ')
                iss.get();

            string tempBuffer;

            //unsigned int to store the position in stream. note, it can be modified
            unsigned int position = iss.tellg() ;
            iss >> tempBuffer;

            if(tempBuffer == "\r" || tempBuffer.empty())
                break;

            std::cout << lineCounter << " " << (position + 1)<< " " << tempBuffer << std::endl;
            myTokens.push_back(TokenAndPosition(tempBuffer, lineCounter, position + 1  ));
            if(!iss)
                break;
        }
        ++lineCounter;
    }
    return myTokens;
}

void printTokens ( ostream &os, const std::vector<TokenAndPosition> &tokens) {
    for( const auto &currentToken: tokens) {
        os << currentToken;
    }
}

ostream operator<<(ostream &os, const TokenAndPosition &token) {
    os << "Line " << std::setw(8) << token._line;
    os << ", Column " << std::setw(4) << token._column;
    os << ": " << token._token << std::endl;
}
