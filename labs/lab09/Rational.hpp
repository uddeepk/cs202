//
// Created by uddeepk on 3/2/21.
//

#ifndef LAB09_RATIONAL_HPP
#define LAB09_RATIONAL_HPP

#include <iostream>

class Rational {
friend std::ostream& operator << (std::ostream&, const Rational& rhs);
//friend Rational operator+ (const Rational &lhs, const Rational &rhs);
public:
    Rational (int, int = 1 );
    Rational & operator+= (const Rational& rhs);
private:
    int _numerator;
    int _denominator;
};
Rational operator+ (const Rational &lhs, const Rational &rhs);

#endif //LAB09_RATIONAL_HPP
