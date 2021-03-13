//
// Created by uddeepk on 3/12/21.
//

#include "MyParagraph.hpp"
#include "TokenAndPosition.hpp"
//#include <algorithm>

using std::string;
using std::vector;
using std::istream;

MyParagraph::MyParagraph(const string &contents):_contents(contents) {

};

vector<MyParagraph> makeVecOfMyParagraph (istream &is) {
    // read buffer
    string readBuffer;
    // the return value
    vector <MyParagraph> myVecOfMyParagraph ;
    // temporary collection of tokens
    vector <string> tokensOfParagraphs;

    while(getline(is, readBuffer)) {
        if(readBuffer.empty() || readBuffer == "\r") {
            // The first one is a new paragraph
            if(!tokensOfParagraphs.empty()) {
                string lastParagraph(tokensToParagraph(tokensOfParagraphs));
                myVecOfMyParagraph.push_back(MyParagraph(lastParagraph));
                tokensOfParagraphs.clear();
            }
            // Eat up the other new lines
            continue ; // ?
        }
        vector tempTokens = lineToTokens(readBuffer);
        tokensOfParagraphs.insert(tokensOfParagraphs.end(), tempTokens.begin(), tempTokens.end());
    }
}

string tokensToParagraph(const vector<string> &tokens) {
    string paragraphOut;
    for (const auto &word : tokens) {
        paragraphOut += word + " "; // will have extra space at the end
    }
    return paragraphOut;
}
