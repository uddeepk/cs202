//
// Created by uddeepk on 2/9/21.
//

#ifndef LAB06_VECTOR3F_HPP
#define LAB06_VECTOR3F_HPP


class Vector3f {

public:
    Vector3f();
    Vector3f(float x, float y, float z);

    float _x;
    float _y;
    float _z;


    Vector3f add(const Vector3f&) const;
    Vector3f sub(const Vector3f&) const;
    void scale(const float scalar) ;
    void negate ();
    float dot(const Vector3f& rhs);
    Vector3f cross(const Vector3f& rhs);
    float length();
    Vector3f unit();

};
bool operator==(const Vector3f& a, const Vector3f& b) ;

bool operator!=(const Vector3f& a, const Vector3f& b);

Vector3f operator+ (const Vector3f& lhs, const Vector3f& rhs);
Vector3f operator- (const Vector3f& lhs, const Vector3f& rhs);
Vector3f operator* (const Vector3f& vec3, const float scalar);
Vector3f operator* (const float scalar, const Vector3f& vec3);
Vector3f operator/ (const Vector3f& vec3, const float scalar);

#endif //LAB06_VECTOR3F_HPP
