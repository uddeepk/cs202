//
// Created by Chris Hartman on 2/18/21.
// Modified by Uddeep Karki on Apr 17, 2021 for hw 05
//

#ifndef CS202CLASSEXAMPLE_RATIONAL_HPP
#define CS202CLASSEXAMPLE_RATIONAL_HPP

#include <iostream>
#include <numeric>

// class invariant:
// _denominator is always > 0
template<typename T>
class Rational {
    template<typename U>
    friend std::ostream &operator<<(std::ostream &, const Rational<U> &rhs);

    template<typename U>
    friend Rational<U> operator+(const Rational<U> &lhs, const Rational<U> &rhs);

    template<typename U>
    friend Rational<U> operator-(const Rational<U> &lhs);

    template<typename U>
    friend bool operator==(const Rational<U> &lhs, const Rational<U> &rhs);

    template<typename U>
    friend bool operator<(const Rational<U> &lhs, const Rational<U> &rhs);

public:
    Rational();

    Rational(T, T= 1); //NOLINT(google-explicit-constructor): Allow implicit conversion from int
    Rational &operator+=(const Rational &rhs);

    Rational &operator-=(const Rational &rhs);

    Rational &operator*=(const Rational &rhs);

    Rational &operator/=(const Rational &rhs);

    Rational &operator++();        //prefix ++
    Rational operator++(int); //postfix ++
    Rational &operator--();        //prefix --
    Rational operator--(int); //postfix --
private:
    void reduce();

    T _numerator;
    T _denominator;
};

template<typename T>
Rational<T>::Rational(): _numerator(0), _denominator(1) {

}

template<typename T>
Rational<T>::Rational(T num, T den) : _numerator(num), _denominator(den) {
    reduce();
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const Rational<T> &rhs) {
    os << rhs._numerator;
    if (rhs._denominator != 1)
        os << "/" << rhs._denominator;
    return os;
}

template<typename T>
Rational<T> operator+(const Rational<T> &lhs, const Rational<T> &rhs) { //canonical
    auto temp{lhs};
    temp += rhs;
    return temp;
}

template<typename T>
Rational<T> &Rational<T>::operator+=(const Rational<T> &rhs) {
    // a/b + c/d = (ad+bc)/ad
    _numerator = _numerator * rhs._denominator + rhs._numerator * _denominator;
    _denominator *= rhs._denominator;
    reduce();
    return *this;
}

template<typename T>
void Rational<T>::reduce() {
    auto gcd = std::gcd(_numerator, _denominator);
    _numerator /= gcd;
    _denominator /= gcd;
    if (_denominator < 0) {
        _numerator *= -1;
        _denominator *= -1;
    }
}

template<typename T>
Rational<T> operator-(const Rational<T> &lhs) {
    return {-lhs._numerator, lhs._denominator};
}

template<typename T>
Rational<T> &Rational<T>::operator-=(const Rational<T> &rhs) { //Canonical
    *this = *this - rhs; //uses Rational::operator- to define operator-=
    return *this;
}

template<typename T>
Rational<T> &Rational<T>::operator*=(const Rational<T> &rhs) {
    _numerator *= rhs._numerator;
    _denominator *= rhs._denominator;
    reduce();
    return *this;
}

template<typename T>
Rational<T> &Rational<T>::operator/=(const Rational<T> &rhs) {
    *this *= {rhs._denominator, rhs._numerator};
    return *this;
}

template<typename T>
Rational<T> operator-(const Rational<T> &lhs, const Rational<T> &rhs) {
    return lhs + -rhs;
}

// pass lhs by value because we were going to copy it anyway
template<typename T>
Rational<T> operator*(Rational<T> lhs, const Rational<T> &rhs) { //Canonical
    return lhs *= rhs;
}

// pass lhs by value because we were going to copy it anyway
template<typename T>
Rational<T> operator/(Rational<T> lhs, const Rational<T> &rhs) { //Canonical
    return lhs /= rhs;
}

template<typename T>
Rational<T> &Rational<T>::operator++() {//prefix ++
    return *this += 1;
}

template<typename T>
Rational<T> Rational<T>::operator++(int) {//postfix ++
    auto copy{*this};
    ++(*this);
    return copy;
}

template<typename T>
Rational<T> &Rational<T>::operator--() {//prefix --
    return *this -= 1;
}

template<typename T>
Rational<T> Rational<T>::operator--(int) {//postfix --
    auto copy{*this};
    --(*this);
    return copy;
}

template<typename T>
bool operator==(const Rational<T> &lhs, const Rational<T> &rhs) {
    return lhs._numerator == rhs._numerator && lhs._denominator == rhs._denominator;
}

template<typename T>
bool operator<(const Rational<T> &lhs, const Rational<T> &rhs) {
    return lhs._numerator * rhs._denominator < rhs._numerator * lhs._denominator;
}

template<typename T>
bool operator!=(const Rational<T> &lhs, const Rational<T> &rhs) {//canonical
    return !(rhs == lhs);
}

template<typename T>
bool operator>(const Rational<T> &lhs, const Rational<T> &rhs) {//canonical
    return rhs < lhs;
}

template<typename T>
bool operator<=(const Rational<T> &lhs, const Rational<T> &rhs) {//canonical
    return !(rhs > lhs);
}

template<typename T>
bool operator>=(const Rational<T> &lhs, const Rational<T> &rhs) {//canonical
    return !(rhs < lhs);
}


#endif//CS202CLASSEXAMPLE_RATIONAL_HPP
