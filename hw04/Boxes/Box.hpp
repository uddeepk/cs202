/*
 * Box.hpp
 * Uddeep Karki
 * Mar 28, 2021
 * Header for Box. Hw04
 */

#ifndef BOXES_BOX_HPP
#define BOXES_BOX_HPP

#include <iostream>

class Box {
public:
    Box (int width, int height);
    int getWidth() const;
    int getHeight() const;
    void setWidth(int);
    void setHeight(int);

    virtual void print(std::ostream &os) const= 0;
    virtual std::string type() const = 0; // = 0 means pure virtual abstraction, and requires overwriting

    virtual ~Box() = default;
private:
    int _width;
    int _height;

    friend std::ostream& operator<< (std::ostream &os, const Box &b);
};


#endif //BOXES_BOX_HPP
