//
// Created by uddeepk on 2/9/21.
//

#include "Vector3f.hpp"
#include <math.h>
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

Vector3f Vector3f::add (const Vector3f& rhs) const {
    return Vector3f(_x + rhs._x, _y + rhs._y , _z + rhs._z);

}

Vector3f Vector3f::sub (const Vector3f& rhs) const{
    return Vector3f(_x - rhs._x, _y - rhs._y , _z - rhs._z);


}

void Vector3f::scale(const float scalar)  {
    _x *= scalar;
    _y *= scalar;
    _z *= scalar;
}
void Vector3f::negate() {
    this->scale(-1);
}
//Vector3f operator* (const float scalar, const Vector3f& rhs) {
//
//}

//Vector3f scale

float Vector3f::dot(const Vector3f& rhs) {
    return (_x * rhs._x + _y * rhs._y + _z*rhs._z);
}

Vector3f Vector3f::cross(const Vector3f& rhs) {
    return Vector3f(_y*rhs._z - _z * rhs._y , _z * rhs._x - _x * rhs._z, _x * rhs._y - _y * rhs._x);
}

float Vector3f::length() {
    return sqrt(this->dot(*this));
}

Vector3f Vector3f::unit() {
    auto a {(*this)};
    a.scale(1/this->length());
    return a;
}

Vector3f operator+ (const Vector3f& lhs, const Vector3f& rhs) {
    return lhs.add(rhs);
}
Vector3f operator- (const Vector3f& lhs, const Vector3f& rhs) {
    return lhs.sub(rhs);
}
Vector3f operator* (const Vector3f& vec3, const float scalar) {
    auto a { vec3};
    a.scale(scalar);
    return a;
}
Vector3f operator* (const float scalar, const Vector3f& vec3) {
    return vec3 * scalar;
}
Vector3f operator/ (const Vector3f& vec3, const float scalar) {
    auto a{vec3};
    a.scale(1/scalar);
    return a;
}