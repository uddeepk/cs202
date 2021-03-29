/*
 * box.hpp
 * Uddeep Karki
 * Mar 28, 2021
 * Source for Box. Hw04
 */

#include "box.hpp"

using std::ostream;
using std::unique_ptr;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Box Code
Box::Box(int width, int height) : _width(width), _height(height) {

}

// getter methods
int Box::getWidth() const {
    return _width;
}

int Box::getHeight() const {
    return _height;
}

//setter methods
void Box::setWidth(int width) {
    _width = width;
}

void Box::setHeight(int height) {
    _height = height;
}

ostream &operator<<(ostream &os, const Box &b) {
    b.print(os);
    return os;
}
//Box source ends

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// FilledBox source, definitions

FilledBox::FilledBox() : Box(1, 1) {
}

FilledBox::FilledBox(int width, int height) : Box(width, height) {
}

// puts the box into output stream passed
void FilledBox::print(ostream &os) const {
    for (int row = 0; row < this->getHeight(); ++row) {
        for (int col = 0; col < this->getWidth(); ++col) {
            os << "x";
        }
        os << "\n";
    }
}

std::string FilledBox::type() const {
    return "Filled";
}

// FilledBox source end

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//HollowBox source, definitions

HollowBox::HollowBox() : Box(1, 1) {
}

HollowBox::HollowBox(int width, int height) : Box(width, height) {
}

void HollowBox::print(ostream &os) const {
    for (int row = 0; row < this->getHeight(); ++row) {
        for (int col = 0; col < this->getWidth(); ++col) {
            if (row == 0 || row == this->getHeight() - 1 || col == 0 || col == this->getWidth() - 1)
                os << "x";
            else
                os << " ";
        }
        os << "\n";
    }
}

std::string HollowBox::type() const {
    return "Hollow";
}
// HollowBox source ends

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//CheckeredBox source starts

CheckeredBox::CheckeredBox() : Box(1, 1) {
}

CheckeredBox::CheckeredBox(int width, int height) : Box(width, height) {
}

void CheckeredBox::print(ostream &os) const {
    for (int row = 0; row < this->getHeight(); ++row) {
        for (int col = 0; col < this->getWidth(); ++col) {
            if ((row + col) % 2) // because its 1 :)
                os << " ";
            else
                os << "x";
        }
        os << "\n";
    }
}

std::string CheckeredBox::type() const {
    return "Checkered";
}
//CheckeredBox source ends

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// boxFactory factory function.
    // returns a unique_ptr to specified box depending on the argument
unique_ptr<Box> boxFactory(char c, int w, int h) {
    unique_ptr<Box> myBox = nullptr;
    switch (c) {
        case 'f':
            myBox = std::make_unique<FilledBox>(w, h);
            break;
        case 'h':
            myBox = std::make_unique<HollowBox>(w, h);
            break;
        case 'c':
            myBox = std::make_unique<CheckeredBox>(w, h);
            break;
        default:
//          // Do nothing. Can't construct a Box that is abstract
            break;
    }
    return myBox;
}