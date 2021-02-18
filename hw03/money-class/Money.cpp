//
// Created by uddeepk on 2/18/21.
//

#include "Money.hpp"
#include <math.h>

Money::Money():_totalCents(0) {}

Money::Money(int dollars, int cents):_totalCents(dollars * 100 + cents) {}

Money::Money(double dollarAndCents):_totalCents(round(dollarAndCents * 100)) {}


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
    return !(lhs < rhs);
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
    // positive or negative
    // extract dollar
    // extract cents
}
