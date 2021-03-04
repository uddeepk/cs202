//
// Created by uddeepk on 3/2/21.
//

#ifndef LAB09_RATIONAL_HPP
#define LAB09_RATIONAL_HPP

#include <iostream>

// class invariant
// _denominator is always > 0
class Rational {
friend std::ostream& operator << (std::ostream&, const Rational& rhs);
//friend Rational operator+ ( Rational lhs, const Rational &rhs); // friend because used in combination with the ohter operators
friend Rational operator- (const Rational &rhs);
friend bool operator== (const Rational &lhs, const Rational &rhs);
friend bool operator< (const Rational &lhs, const Rational &rhs);

public:
    Rational (int, int = 1 );
    Rational & operator+= (const Rational& rhs);
    Rational & operator-= (const Rational& rhs);
    Rational & operator*= (const Rational& rhs);
    Rational & operator/= (const Rational& rhs);
    Rational & operator++ ();
    Rational operator++ (int); // dummy parameter, postfix
    Rational & operator-- ();
    Rational operator-- (int);
private:
    void reduce();

    int _numerator;
    int _denominator;
};
Rational operator+ (Rational lhs, const Rational &rhs);
Rational operator- (const Rational &lhs, const Rational &rhs);
Rational operator* ( Rational lhs, const Rational &rhs);
Rational operator/ ( Rational lhs, const Rational &rhs);


bool operator!= (const Rational &lhs, const Rational &rhs);
bool operator> (const Rational &lhs, const Rational &rhs);
bool operator<= (const Rational &lhs, const Rational &rhs);
bool operator>= (const Rational &lhs, const Rational &rhs);


//int gcd ( int a, int b);
#endif //LAB09_RATIONAL_HPP
