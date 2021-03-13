//
// Created by uddeepk on 3/12/21.
//

#ifndef BOOK_PRETTY_PRINTER_MYPARAGRAPH_HPP
#define BOOK_PRETTY_PRINTER_MYPARAGRAPH_HPP

#include <vector>
#include <string>


class MyParagraph {
public:
    //Constructor
    MyParagraph(const std::string &) ;
    void print(int) const;
    void printv2(int wrapPosition) const;
private:
    std::string _contents;
};
std::vector<MyParagraph> makeVecOfMyParagraph (std::istream &is);
std::string tokensToParagraph(const std::vector<std::string> &tokens);
void prettyPrint (const std::vector <MyParagraph> &yVecOfMyParagraph, int wrapPoint) ;

#endif //BOOK_PRETTY_PRINTER_MYPARAGRAPH_HPP
