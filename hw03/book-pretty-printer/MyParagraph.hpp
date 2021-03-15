//
// MyParagraph.Hpp
// Uddeep Karki
// 3/12/21.
// Header for the MyParagraph class for CS202 HW03
//

#ifndef BOOK_PRETTY_PRINTER_MYPARAGRAPH_HPP
#define BOOK_PRETTY_PRINTER_MYPARAGRAPH_HPP

#include <vector>
#include <string>


class MyParagraph {
public:
    //Constructor
    MyParagraph(const std::string &) ;
    std::ostream &print(std::ostream &os , int) const;
    std::ostream &printv2(std::ostream&os, int wrapPosition) const;
private:
    std::string _contents;
friend std::ostream& operator<< (std::ostream& os, const MyParagraph &paragraph);
};
std::vector<MyParagraph> makeVecOfMyParagraph (std::istream &is);
std::string tokensToParagraph(const std::vector<std::string> &tokens);
std::ostream &prettyPrint (std::ostream &os, const std::vector <MyParagraph> &myVecOfMyParagraph, int wrapPoint) ;
std::ostream &prettyPrintHtml ( std::ostream &os, const std::vector <MyParagraph> &myVecOfMyParagraph);

#endif //BOOK_PRETTY_PRINTER_MYPARAGRAPH_HPP
