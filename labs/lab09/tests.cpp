//
// Created by uddeepk on 3/2/21.
//
#include <iostream>
#include <sstream>
using std::ostringstream;

#include "Rational.hpp"
#include "Complex.hpp"
#include <numeric>
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

TEST_CASE("Rational Unary operator - ") {
    Rational minusOne { -1};
    Rational minusOneSevenths { 1, -7};
    ostringstream oss ;
    oss << minusOne;
    REQUIRE(oss.str() == "-1");
    oss.str("");
    oss << -minusOne;
    REQUIRE(oss.str() == "1");
    oss.str("");
//    oss.clear(); //only need clear to clear error flags
    oss << -minusOneSevenths;
    REQUIRE(oss.str() == "1/7");
}

TEST_CASE("Rational -= and - opeartor") {
    Rational a { 2 , 5};
    Rational b { 1, 5};
    a -= b;
    ostringstream oss;
    oss << a;
    REQUIRE(oss.str() == "1/5");
    Rational c { 1, 11};
    oss.str("");
    oss << a - c;
    REQUIRE(oss.str() == "6/55");
    oss.str("");
    oss << 1 - a;
    REQUIRE(oss.str() == "4/5");
    oss.str("");
    Rational f = a + 1;
}
TEST_CASE("Rational * and *= opeartor") {
    Rational a { 2 , 5};
    Rational b { 1, 5};
    a *= b;
    ostringstream oss;
    oss << a;
    REQUIRE(oss.str() == "2/25");
    Rational c { 1, 11};
    oss.str("");
    oss << a * c;
    REQUIRE(oss.str() == "2/275");
    oss.str("");
    oss << 1 * a;
    REQUIRE(oss.str() == "2/25");
    oss.str("");
    Rational f = a + 1;

    Rational x { 1,3};
    const Rational oneHalf {1 , 2};
    oss.str("");
    oss << oneHalf * oneHalf * oneHalf;
    REQUIRE( oss.str() == "1/8");

}

TEST_CASE("Comparison operators") {
    ostringstream out;
    Rational oneThird{1,3};
    Rational oneHalf{1,2};

    REQUIRE(oneHalf != oneThird);
    REQUIRE(oneHalf > oneThird);
}

TEST_CASE("increment nd decrement") {
    ostringstream out;
    Rational x{1,3};
    ++x;
    REQUIRE(x == Rational{4,3});
    --x;
    REQUIRE(x == Rational{1,3});
    x++;
    REQUIRE(x == Rational{4,3});
    x--;
    REQUIRE(x == Rational{1,3});
    REQUIRE(++x == Rational{4,3});
    REQUIRE(x++ == Rational{4,3});
    REQUIRE(x == Rational{7,3});
}

TEST_CASE("Check GCD " ) { //Used std::gcd instead
    using std::gcd;
    REQUIRE(gcd(3,0)==3);
    REQUIRE(gcd(0,3) == 3);
    REQUIRE(gcd(12,6) == 6);
    REQUIRE(gcd(25,7) == 1);
}


//TEST_CASE("Complex numbers can be constructed") {
//    Complex a { 2, 5};
//    ostringstream oss ;
//    oss << a ;
//    REQUIRE(oss.str() == "2 + 5i");
//    Complex b { 3, -2};
//    oss.str("");
//    oss.clear();
//    oss << b;
//    REQUIRE(oss.str() == "3 - 2i");
//}
//TEST_CASE("Complex numbers can be added with += and +") {
//    Complex a (0);
//    Complex b(1);
//    b += a;
//    ostringstream oss ;
//    oss << b ;
//    REQUIRE(oss.str() == "1 + 0i");
//    oss.str("");
//    oss.clear();
//    Complex c(3, 4);
//    Complex d = b + c;
//    oss << d;
//    REQUIRE(oss.str() == "4 + 4i");
//    oss.str("");
//    oss.clear();
//    Complex x = c + 3;
//    oss << x;
//    REQUIRE(oss.str() == "6 + 4i");
//}
//
//TEST_CASE("Test case from question") {
//    ostringstream oss;
//    oss << 1 + Complex(2,3) ;
//    REQUIRE(oss.str() == "3 + 3i");
//}