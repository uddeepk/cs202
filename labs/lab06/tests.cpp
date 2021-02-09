//
// Created by uddeepk on 2/9/21.
//
#include "catch.hpp"

unsigned int Factorial(unsigned int number) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

TEST_CASE("Factorials are computed", "[factorial]") {
REQUIRE( Factorial(0) == 1 );
REQUIRE( Factorial(2) == 2);
}