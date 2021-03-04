//
// Created by uddeepk on 3/2/21.
//

#ifndef LAB09_COMPLEX_HPP
#define LAB09_COMPLEX_HPP

#include <iostream>

class Complex {
    friend std::ostream& operator<< ( std::ostream&, const Complex & );
public:
    Complex(double , double = 0 );
    Complex& operator+= (const Complex &rhs);
private:
    double _real{0};
    double _imaginary{0};

};
Complex operator+(Complex lhs, const Complex &rhs) ;
//Complex operator+(const Complex &lhs, double rhs); // I don't need this
//Complex operator+(double lhs, const Complex &rhs); // Same. seems compiler performs an implicit conversion


#endif //LAB09_COMPLEX_HPP
