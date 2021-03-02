//
// Created by uddeepk on 3/2/21.
//
#include <iostream>
#include <sstream>
using std::ostringstream;

#include "Rational.hpp"
#include "Complex.hpp"
#include "catch.hpp"

//TEST_CASE("Rationals can be costructed and printed") {
//    Rational oneHalf {1, 2};
//    ostringstream oss ;
//    oss << oneHalf ;
//    REQUIRE(oss.str() == "1/2");
//
//}
//
//TEST_CASE("Rationals can be added with + and +=") {
//    Rational oneHalf {1, 2};
//    Rational one {1};
//    Rational x = oneHalf + one;
//    ostringstream oss ;
//    oss << x;
//    REQUIRE(oss.str() == "3/2");
//    x += oneHalf;
//    oss.str("");
//    oss.clear();
//    oss << x;
//    REQUIRE(oss.str() == "2");
//
//}

TEST_CASE("Complex numbers can be constructed") {
    Complex a { 2, 5};
    ostringstream oss ;
    oss << a ;
    REQUIRE(oss.str() == "2 + 5i");
    Complex b { 3, -2};
    oss.str("");
    oss.clear();
    oss << b;
    REQUIRE(oss.str() == "3 - 2i");
}
TEST_CASE("Complex numbers can be added with += and +") {
    Complex a (0);
    Complex b(1);
    b += a;
    ostringstream oss ;
    oss << b ;
    REQUIRE(oss.str() == "1 + 0i");
    oss.str("");
    oss.clear();
    Complex c(3, 4);
    Complex d = b + c;
    oss << d;
    REQUIRE(oss.str() == "4 + 4i");
    oss.str("");
    oss.clear();
    Complex x = c + 3;
    oss << x;
    REQUIRE(oss.str() == "6 + 4i");
}

TEST_CASE("Test case from question") {
    ostringstream oss;
    oss << 1 + Complex(2,3) ;
    REQUIRE(oss.str() == "3 + 3i");
}