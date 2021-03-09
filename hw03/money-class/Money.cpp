/*
 * Money.cpp
 * Uddeep Karki
 * Mar 8, 2021
 * Source File for Money class
 */

#include "Money.hpp"
#include <cmath>
#include <iomanip>

Money::Money(int cents, int dollars):_totalCents(dollars * 100 + cents) {}

Money::Money(double dollarAndCents):_totalCents(std::round(dollarAndCents * 100)) {}


bool operator== (const Money& lhs, const Money& rhs) {
    return lhs._totalCents == rhs._totalCents;
}
bool operator!= (const Money& lhs, const Money& rhs) {
    return !(lhs == rhs);
}
bool operator< (const Money& lhs, const Money& rhs) {
    return lhs._totalCents < rhs._totalCents;
}
bool operator>= (const Money& lhs, const Money& rhs) {
    return !(lhs < rhs);
}
bool operator> (const Money& lhs, const Money& rhs) {
    return rhs < lhs;
}
bool operator <= (const Money& lhs, const Money& rhs) {
    return !(lhs > rhs);
}

Money& Money::operator+=(const Money& rhs) {
    _totalCents += rhs._totalCents;
    return *this;
}
Money& Money::operator-=(const Money& rhs) {
    _totalCents -= rhs._totalCents;
    return *this;
}
Money& Money::operator*=(double number) {
    _totalCents *= number;
    return *this;
}
Money& Money::operator/=(double number) {
    _totalCents /= number;
    return *this;
}
//TODO: Check the two following operator
Money operator+(const Money& lhs, const Money& rhs) {
    Money sumMoney {lhs};
    return (sumMoney+= lhs);
}
Money operator-(const Money& lhs, const Money& rhs) {
    Money differenceMoney {lhs};
    return (differenceMoney -= rhs);
}
Money operator*(const Money& lhs,  double number) {
    auto tempMoney (lhs);
    return (tempMoney *= number);
}
Money operator*(double number, const Money& rhs) {
    return rhs * number;
}
Money operator/ (const Money& lhs, double number) {
    auto tempMoney ( lhs );
    return (tempMoney /= number);
}

std::ostream& operator<<(std::ostream& os, const Money& myMoney) {
    auto cents = myMoney._totalCents;
    // positive or negative
    if(cents < 0) {
        os << "-";
        cents *= (-1);
    }
    // extract dollar
    os << "$" << cents / 100 ;
    // extract cents
    os << "." << std::setfill('0') << std::setw(2) << cents % 100;
    return os;
}
