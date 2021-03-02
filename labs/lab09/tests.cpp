//
// Created by uddeepk on 3/2/21.
//
#include <iostream>
#include <sstream>
using std::ostringstream;

#include "Rational.hpp"
#include "catch.hpp"

TEST_CASE("Rationals can be costructed and printed") {
    Rational oneHalf {1, 2};
    ostringstream oss ;
    oss << oneHalf ;
    REQUIRE(oss.str() == "1/2");

}

TEST_CASE("Rationals can be added with + and +=") {
    Rational oneHalf {1, 2};
    Rational one {1};
    Rational x = oneHalf + one;
    ostringstream oss ;
    oss << x;
    REQUIRE(oss.str() == "3/2");
    x += oneHalf;
    oss.str("");
    oss.clear();
    oss << x;
    REQUIRE(oss.str() == "2");

}