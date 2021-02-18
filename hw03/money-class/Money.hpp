// Money.hpp
// Uddeep Karki, 02/18/2021
//
// For CS202 HW03
// Money class

#ifndef MONEY_CLASS_MONEY_HPP
#define MONEY_CLASS_MONEY_HPP

#include <iostream>

// Money stores amount in cents

class Money {

public:
    // Constructors
    Money(); // Default constructor
    Money(int, int); // Parameterized constructor for taking dollar and cent value
    Money(double);

    Money& operator+=(const Money&rhs);
    Money& operator-=(const Money&rhs);
    Money& operator*=(double number);
    Money& operator/=(double number);


private:
    int _totalCents;

    friend bool operator== (const Money& lhs, const Money& rhs);

    friend bool operator< (const Money& lhs, const Money& rhs);


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

std::ostream& operator<<(std::ostream& os, const Money& myMoney) ;
#endif //MONEY_CLASS_MONEY_HPP
