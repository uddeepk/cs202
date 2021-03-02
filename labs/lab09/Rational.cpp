//
// Created by uddeepk on 3/2/21.
//

#include "Rational.hpp"

Rational::Rational(int num, int den):_numerator(num), _denominator(den){

}

std::ostream &operator<<(std::ostream &os, const Rational &rhs) {
    os << rhs._numerator << "/" << rhs._denominator;
    return os;
}

Rational operator+(const Rational &lhs, const Rational &rhs) {
    auto temp {lhs};
    temp += rhs;
    return temp;
}

Rational &Rational::operator+=(const Rational &rhs) {
    _numerator = _numerator * rhs._denominator + rhs._numerator * _denominator;
    _denominator = _denominator * rhs._denominator;
    return *this;
}


