/*
 * Box.hpp
 * Uddeep Karki
 * Mar 28, 2021
 * Source for Box. Hw04
 */

#include "Box.hpp"
using std::ostream;

Box::Box(int width, int height):_width(width), _height(height) {

}

int Box::getWidth() const{
    return _width;
}

int Box::getHeight() const{
    return _height;
}

void Box::setWidth(int width) {
    _width = width;
}

void Box::setHeight(int height) {
    _height = height;
}

ostream& operator<< (ostream &os, const Box &b) {
    b.print(os);
    return os;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FilledBox source, definitions

FilledBox::FilledBox(): Box(1, 1) {
}

FilledBox::FilledBox(int width, int height): Box(width, height) {
}

void FilledBox::print(std::ostream &os) const {
    for(int i = 0 ; i < this->getHeight() ; ++i) {
        for (int j = 0 ; j < this ->getWidth() ; ++j) {
            os << "x" ;
        }
        os << "\n";
    }
}

std::string FilledBox::type() const {
    return "FilledBox";
}

// FilledBox source end

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//HollowBox source, definitions

