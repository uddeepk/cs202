/*
 * TokenAndPosition.cpp
 * Uddeep Karki
 * 2/17/21
 * Source file for TokenAndPosition class
 */


#include "TokenAndPosition.hpp"
#include <sstream>
#include <iomanip>

using std::vector;
using std::string;
using std::istream;
using std::ostream;
using std::istringstream;

TokenAndPosition::TokenAndPosition(const string &token, const int &line, const unsigned int &column):_token(token), _line(line),_column(column)  {}

// Takes a string and divides it into a vector of string tokens for hw03 program 1
vector <string> lineToTokens (const string &line) {
    vector <string> myTokens ;
    istringstream iss {line} ;
    while (true) {
        if(!iss)
            break;
        string tempBuffer;
        iss >> tempBuffer;
        if(tempBuffer.empty())
            continue;
        myTokens.push_back(tempBuffer);
    }
    return myTokens;
}

// Takes stream, and extracts lines from it to send to lineToTokens.
// Then use find member in string class to assigne positions to tokens and initialize the TokenAndPosition objects.
// After this, it is pushed back into a vector which is returned
vector <TokenAndPosition> readLines (istream &is) {
    vector <TokenAndPosition> myTP ; //The variable that will hold the return value
    string inputBuffer;
    for( int lineNumber = 1 ; getline( is, inputBuffer) ; ++lineNumber) {
        if( inputBuffer == "\r" || inputBuffer.empty())
            continue;
        vector <string> tokensInLine = lineToTokens(inputBuffer);
        unsigned int column = 0;
        for( const auto &token: tokensInLine) {
            unsigned int currentColumn = inputBuffer.find(token, column);
            // note about above, ensuring that find provides actual match instead of populist match.
            column = currentColumn + 1; // because positions start at 1, and to move forward 1 position
            myTP.push_back(TokenAndPosition{token, lineNumber, column});
        }
    }
    return myTP;
}

// takes a vector of tokens and uses the overloaded operator << to print the tokens
void printTokens ( ostream &os, const std::vector<TokenAndPosition> &tokens) {
    for( const auto &currentToken: tokens) {
        os << currentToken;
    }
}

// overloaded ostream& operator<< to display the TokenAndPosition objects in the required format for hw03
ostream& operator<<(ostream &os, const TokenAndPosition &token) {
    os << "Line " << std::setw(8) << token._line;
    os << ", Column " << std::setw(4) << token._column;
    os << ": \"" << token._token << "\"" << std::endl;
    return os;
}
