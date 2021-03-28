/*
 * Box.hpp
 * Uddeep Karki
 * Mar 28, 2021
 * Source for Box. Hw04
 */

#include "Box.hpp"

Box::Box(int width, int height):_width(width), _height(height) {

}

int Box::getWidth() {
    return _width;
}

int Box::getHeight() {
    return _height;
}

void Box::setWidth(int width) {
    _width = width;
}

void Box::setHeight(int height) {
    _height = height;
}

