//
// Created by uddeepk on 2/9/21.
//

#include "Vector3f.hpp"

Vector3f::Vector3f(): _x(0), _y(0), _z(0) {
}

Vector3f::Vector3f(float x, float y, float z): _x(x), _y(y), _z(z) {

}

bool operator==(const Vector3f& a, const Vector3f& b) {
  return (a._x == b._x)    && (a._y == b._y) && (a._z == b._z);
}
bool operator!=(const Vector3f& a, const Vector3f& b) {
    return (a._x != b._x) || (a._y != b._y) || (a._z != b._z) ;
}

