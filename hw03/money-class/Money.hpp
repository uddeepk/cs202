/*
 * Money.hpp
 * Uddeep Karki
 * Mar 8, 2021
 * Header for Money class
 */

#ifndef MONEY_CLASS_MONEY_HPP
#define MONEY_CLASS_MONEY_HPP

#include <iostream>

// Money stores amount in cents

class Money {

public:
    // Constructors
    Money(int = 0 , int = 0); // user defined default constructor for taking dollar and cent value
    Money(double);

    Money& operator+=(const Money&rhs);
    Money& operator-=(const Money&rhs);
    Money& operator*=(double number);
    Money& operator/=(double number);


private:
    int _totalCents;

    friend bool operator== (const Money& lhs, const Money& rhs);
    friend bool operator< (const Money& lhs, const Money& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Money& myMoney) ;


//    friend Money operator+ (const Money& lhs, const Money& rhs);
//
//    friend Money operator* (const Money& lhs, double number);
//    friend Money operator* (double number, const Money& rhs);
};
bool operator!= (const Money& lhs, const Money& rhs);

bool operator<= (const Money& lhs, const Money& rhs);
bool operator> (const Money& lhs, const Money& rhs);
bool operator>= (const Money& lhs, const Money& rhs);

Money operator+ (const Money& lhs, const Money& rhs);
Money operator- (const Money& lhs, const Money& rhs);
Money operator* (const Money& lhs, double number);
Money operator* (double number, const Money& rhs);
Money operator/ (const Money& lhs, double number);

#endif //MONEY_CLASS_MONEY_HPP
