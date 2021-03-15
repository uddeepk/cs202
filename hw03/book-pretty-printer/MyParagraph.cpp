//
// Created by uddeepk on 3/12/21.
//

#include "MyParagraph.hpp"
#include "TokenAndPosition.hpp"
#include <sstream>

using std::string;
using std::vector;
using std::istream;
using std::ostream;
using std::istringstream;
using std::cout;

MyParagraph::MyParagraph(const string &contents):_contents(contents) {

}

ostream & operator<<(ostream& os, const MyParagraph &paragraph ) {
    os << paragraph._contents;
    return os;
}
ostream &MyParagraph::print(ostream& os, int wrapPosition) const {
    auto printTokens = lineToTokens(_contents);
    for (auto it = printTokens.begin() ; it != printTokens.end() ; ) {
        std::ostringstream oss ;
        do {
            oss << *it << " ";
            ++it;
            if ( it == printTokens.end())
                break;
        } while ((it->length() + oss.tellp())  <= (wrapPosition ) );
        os << oss.str() << "\n";
    }
    return os;
}
ostream &MyParagraph::printv2(ostream& os, int wrapPosition) const {
    auto printTokens = lineToTokens(_contents);
    int lineCharCounter = 0;
    for ( const auto &token : printTokens) {
        if ( (lineCharCounter + token.length() ) > wrapPosition ) {
            os << "\n";
            lineCharCounter = 0;
        }
        os << token << " " ;
        lineCharCounter += token.length() + 1;
    }
    return os;
}

ostream &prettyPrint(ostream &os, const vector<MyParagraph> &myVecOfMyParagraph, int wrapPoint) {
    for ( const auto &currentParagraph : myVecOfMyParagraph) {
        currentParagraph.printv2(os, wrapPoint);
        os << "\n";
    }
    return os;
};

ostream &prettyPrintHtml(ostream &os, const vector <MyParagraph> &myVecOfMyParagraph) {
    for (const auto &currentParagraph : myVecOfMyParagraph) {
        os << "<p>";
        os << currentParagraph;
        os << "</p>" << "\n";
    }
    return os;
}

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
