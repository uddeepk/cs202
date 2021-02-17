//
// Created by uddeepk on 2/9/21.
//
#include "catch.hpp"



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



TEST_CASE("Default constructor", "[default]") {
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
///////////////////////////////////////////////////////////////////////////////////////////////////////
//Tring to find the best way to use SECTION. Is the following redundant compared to the first ?
//What case do we use SECTION? Revisit later.

TEST_CASE("Practice with Sections", "[hypotamoose]") {
    Vector3f a; // default
    SECTION("Testing default constructor") {
        REQUIRE(a._x == Approx(0));
        REQUIRE(a._y == Approx(0));
        REQUIRE(a._z == Approx(0));
    }
    Vector3f b (42, -9.92, .00081);
    SECTION("Testing other constructor") {
        REQUIRE( b._x == Approx(42));
        REQUIRE( b._y == Approx(-9.92)); //9.92 is a double, a._y will be converted to a double for ...//Had to approx or // Question for later.
        REQUIRE( b._z == Approx(0.00081));
    }

}

TEST_CASE("Add","[add]") {
    Vector3f a(1, 2, 3), b(3, 4, 5);
    auto c = a + b;

    REQUIRE( c._x == Approx(4));
    REQUIRE( c._y == Approx(6));
    REQUIRE( c._z == Approx(8));

}

TEST_CASE( "SUBTRACT", "[subtract]") {
    Vector3f a(1, 2, 3), b(3, 4, 5);
    auto c = a - b;

    REQUIRE( c._x == Approx(-2));
    REQUIRE( c._y == Approx(-2));
    REQUIRE( c._z == Approx(-2));
}

TEST_CASE( "Scale", "[scale]") {
    Vector3f a(1, 2, 3);
    auto b = a * 3;

    REQUIRE( b._x == Approx(3));
    REQUIRE( b._y == Approx(6));
    REQUIRE( b._z == Approx(9));

}

TEST_CASE("Negate", "[negate]") {
    Vector3f a(1, 2, 3);
    a.negate();

    REQUIRE( a._x == Approx(-1));
    REQUIRE( a._y == Approx(-2));
    REQUIRE( a._z == Approx(-3));
}

TEST_CASE("Dot product","[dot]") {
    Vector3f a(1, 2, 3), b(3, 4, 5);
    auto dotProduct = a.dot(b);

    REQUIRE( dotProduct == Approx(26));
}

TEST_CASE( "Cross Product", "[cross]") {
    Vector3f a(1, 2, 3), b(3, 4, 5);
    auto c = a.cross(b);
    auto expectedCrossProduct = Vector3f(-2, 4, -2);

    REQUIRE(c == expectedCrossProduct);

    // Require...
}

TEST_CASE( "Length", "[length]") {
    Vector3f a(1, 2, 3);
    auto lengthA =a.length();

    REQUIRE( lengthA == Approx(sqrt(14)));
}

TEST_CASE( "Unit Vector", "[unit]") {
    Vector3f a(1, 2, 3);
    auto unitVectorA = a.unit();

    REQUIRE( unitVectorA._x == Approx (1 / sqrt(14)));
    REQUIRE( unitVectorA._y == Approx (2 / sqrt(14)));
    REQUIRE( unitVectorA._z == Approx (3 / sqrt(14)));

}