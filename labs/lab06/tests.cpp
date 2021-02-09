//
// Created by uddeepk on 2/9/21.
//
#include "../../catch.hpp"



//unsigned int Factorial(unsigned int number) {
//    return number <= 1 ? 1 : Factorial(number-1)*number;
//}
//
//TEST_CASE("Factorials are computed", "[factorial]") {
//REQUIRE( Factorial(0) == 1 );
//REQUIRE( Factorial(1) == 1 );
//REQUIRE( Factorial(2) == 2 );
//REQUIRE( Factorial(3) == 6 );
//}

#include "Vector3f.hpp"

bool operator==(const Vector3f& a, const Vector3f& b) {
    return (a._x == b._x)    && (a._y == b._y) && (a._z == b._z);
}
bool operator!=(const Vector3f& a, const Vector3f& b) {
    return (a._x != b._x) || (a._y != b._y) || (a._z != b._z) ;
}

TEST_CASE("Defult constructor", "[default]") {
    Vector3f a; // default
    REQUIRE( a._x == Approx(0));
    REQUIRE( a._y == Approx(0));
    REQUIRE( a._z == Approx(0));
}
TEST_CASE("Other constructor", "[other-ctor]") {
    Vector3f a (42, -9.92, .00081); // SOmething here with double to float.... //9.92 is a double
    REQUIRE( a._x == Approx(42));
    REQUIRE( a._y == Approx(-9.92)); //9.92 is a doulbe, a._y will be converted to a double for ...//Had to approx or // Question for later.
    REQUIRE( a._z == Approx(0.00081));
}
TEST_CASE("Equality of vectors", "[equality]") {
    Vector3f a; // default (0, 0, 0)
    Vector3f b; // default (0, 0, 0)
    REQUIRE( a == b );

    Vector3f c( 1.3, 0.99, -42.0);
    Vector3f d( 1.3, 0.99, -42.0);
    REQUIRE( a == b );
}

TEST_CASE("Inequality of vectors", "[inequality]") {
    Vector3f a;
    Vector3f b(500, 0,984);
    REQUIRE( a != b);
}
