//
// Created by uddeepk on 3/12/21.
//

#include "MyParagraph.hpp"
#include "TokenAndPosition.hpp"
//#include <algorithm>
#include <sstream>

using std::string;
using std::vector;
using std::istream;
using std::ostream;
using std::istringstream;
using std::cout;

MyParagraph::MyParagraph(const string &contents):_contents(contents) {

}

void MyParagraph::print(int wrapPosition) const{
    auto printTokens = lineToTokens(_contents);
    for (auto it = printTokens.begin() ; it != printTokens.end() ; ) {
        std::ostringstream oss ;
        while ( oss.tellp()  <= (wrapPosition - it->length()) ) {
            oss << *it << " ";
            ++it;
            if ( it == printTokens.end())
                break;
        }
        cout << oss.str() << "\n";
    }
}
void MyParagraph::printv2(int wrapPosition) const {
    auto printTokens = lineToTokens(_contents);
    int lineCharCounter = 0;
    for ( const auto &token : printTokens) {
        if ( (lineCharCounter + token.length() ) > 40 ) {
            cout << "\n";
            lineCharCounter = 0;
        }
        cout << token << " " ;
        lineCharCounter += token.length() + 1;
    }

}

void prettyPrint( const vector<MyParagraph> &myVecOfMyParagraph, int wrapPoint) {
    for ( const auto &currentParagraph : myVecOfMyParagraph) {
        currentParagraph.printv2(wrapPoint);
        cout << "\n";
    }
};

vector<MyParagraph> makeVecOfMyParagraph (istream &is) {
    // read buffer
    string readBuffer;
    // the return value
    vector <MyParagraph> myVecOfMyParagraph ;
    // temporary collection of tokens
    vector <string> tokensOfParagraphs;

    while(getline(is, readBuffer)) {
//        std::cout << readBuffer;
        if(readBuffer.empty() || readBuffer == "\r") {
            // The first one is a new paragraph
            if(!tokensOfParagraphs.empty()) {
                string previousParagraph(tokensToParagraph(tokensOfParagraphs));
                myVecOfMyParagraph.push_back(MyParagraph(previousParagraph));
                tokensOfParagraphs.clear();
            }
            // Eat up the other new lines
            continue ; // ?
        }
        vector tempTokens = lineToTokens(readBuffer);
        tokensOfParagraphs.insert(tokensOfParagraphs.end(), tempTokens.begin(), tempTokens.end());
    }
    string lastParagraph(tokensToParagraph(tokensOfParagraphs));
    myVecOfMyParagraph.push_back(MyParagraph(lastParagraph));
    return myVecOfMyParagraph;
}

string tokensToParagraph(const vector<string> &tokens) {
    string paragraphOut;
    for (const auto &word : tokens) {
        paragraphOut += word + " "; // will have extra space at the end
    }
    return paragraphOut;
}
