//
// Created by uddeepk on 3/2/21.
//

#include "Complex.hpp"
using std::ostream;

Complex::Complex(double real, double imaginary):_real(real), _imaginary(imaginary) {

}

ostream & operator<< ( std::ostream& os, const Complex &rhs) {
    os << rhs._real ;
    double imaginaryPart = rhs._imaginary;
    if ( rhs._imaginary < 0 ) {
        os << " - " ;
        imaginaryPart *= (-1);
    } else {
        os << " + " ;
    }
    os << imaginaryPart << "i";
    return os;
}

Complex &Complex::operator+=(const Complex &rhs) {
    _real += rhs._real;
    _imaginary += rhs._imaginary;
    return *this;
}

Complex operator+(Complex lhs, const Complex &rhs) {
    lhs += rhs;
    return lhs;
}
//
//Complex operator+(const Complex &lhs, double rhs) {
//    Complex tempRhs {rhs};
//    return lhs + tempRhs;
//}
//
//Complex operator+(double lhs, const Complex &rhs) {
//    return rhs + lhs;
//}