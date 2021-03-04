//
// Created by uddeepk on 3/2/21.
//

#include "Rational.hpp"
#include <numeric>

Rational::Rational(int num, int den):_numerator(num), _denominator(den){
    reduce();
}

std::ostream & operator<<(std::ostream &os, const Rational &rhs) {
    os << rhs._numerator;
    if ( rhs._denominator != 1)
        os << "/" << rhs._denominator;
    return os;
}

Rational operator-(const Rational &rhs) {
    return Rational(-rhs._numerator, rhs._denominator);
}

Rational & Rational::operator+=(const Rational &rhs) {
    _numerator = _numerator * rhs._denominator + rhs._numerator * _denominator;
    _denominator = _denominator * rhs._denominator;
    reduce();
    return *this;
}

Rational &Rational::operator-=(const Rational &rhs) {
    *this += -rhs;
    reduce();
    return *this;
    //return *this;
}

Rational &Rational::operator*= (const Rational& rhs) {
    _numerator *= rhs._numerator;
    _denominator *= rhs._denominator;
    reduce();
    return *this;
}
Rational &Rational::operator/= (const Rational& rhs) {
    *this *= Rational {rhs._denominator, rhs._numerator};
    return *this;
}
void Rational::reduce() {
    auto gcd = std::gcd(_numerator, _denominator);
    _numerator /= gcd;
    _denominator /= gcd;
    if(_denominator < 0) {
        _numerator *= (-1);
        _denominator *= (-1);
    }
}

Rational operator+(Rational lhs, const Rational &rhs) {
    lhs += rhs;
    return lhs;
}

Rational operator- (const Rational &lhs, const Rational &rhs) {
    return lhs + -rhs;
}

Rational operator* ( Rational lhs, const Rational &rhs) {
    // Pass by value because we would copy it anyway
    lhs *= rhs;
    return lhs;
}

Rational operator/ (Rational lhs, const Rational &rhs) {
    lhs /= rhs;
    return lhs;
}

Rational & Rational::operator++ () {
    return *this += 1;
}
Rational Rational::operator++ (int) {
    auto copy { *this };
    ++(*this);
    return copy;
}

Rational & Rational::operator--() {
    return *this -= 1;
}

Rational Rational::operator--(int) {
    auto copy {*this};
    --(*this);
    return copy;
}

bool operator== (const Rational &lhs, const Rational &rhs) {
    return (lhs._numerator == lhs._numerator && lhs._denominator == rhs._denominator);
}
bool operator< (const Rational &lhs, const Rational &rhs) {
    return (lhs._numerator * rhs._denominator < rhs._numerator * lhs._denominator);
}

bool operator!= (const Rational &lhs, const Rational &rhs) {
    return !(lhs == rhs);
}

bool operator>= ( const Rational &lhs, const Rational &rhs) {
    return !(lhs < rhs);
}

bool operator> (const Rational &lhs, const Rational &rhs) {
    return rhs < lhs;
}

bool operator<= (const Rational &lhs, const Rational &rhs) {
    return !(rhs < lhs);
}
//
//int gcd (int a, int b) {
//    while(b != 0) {
//        a %= b;
//        std::swap(a,b);
//    }
//    return a;
//}