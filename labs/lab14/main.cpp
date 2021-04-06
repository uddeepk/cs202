/*
 * main.cpp
 * Uddeep Karki
 * 04/06/2021
 * Lab 14
 * CS202
 */
#include <iostream>
using std::cout;
#include "MyPair.hpp"
int main() {
    std::cout << "Hello, World!" << std::endl;
    MyPair<int, char> m(2, '2');
    cout << m.getFirst() << " " << m.getSecond() << "\n";

    auto m2 = MyPair( 3.14, "PIE");
    cout << m2.getFirst() << " " << m2.getSecond() << "\n";

    cout << std::string(m2) << "\n";
    return 0;
}
