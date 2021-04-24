/*
 * myreadwrite.hpp
 * Uddeep Karki
 * Apr 16, 2021
 * The solution for hw 05 program 1
 */
#ifndef TEMPLATE_READ_AND_WRITE_MYREADWRITE_HPP
#define TEMPLATE_READ_AND_WRITE_MYREADWRITE_HPP

#include <fstream>
#include <array>

template <typename T>
std::ostream& myWrite (std::ostream& os,const T &t) {
    os.write( reinterpret_cast<const char*> (&t), sizeof(T));
    return os;
}

template <typename T, std::size_t n>
std::ostream& myWrite (std::ostream& os, std::array <T, n> const &t) {
    for ( std::size_t i = 0 ; i < n ; ++i) {
        os.write(reinterpret_cast<const char*> (&t[i]), sizeof (t));
    }
    return os;
}


template <typename T>
void myRead(std::istream& is, T &t) {
    is.read(reinterpret_cast< char*> (&t), sizeof (t));
}

template <typename T, std::size_t n>
void myRead(std::istream& is,std::array<T,n> &t) {
    for ( std::size_t i = 0 ; i < n; ++i) {
        is.read(reinterpret_cast< char*> (&t[i]), sizeof (t));
    }
}
#endif //TEMPLATE_READ_AND_WRITE_MYREADWRITE_HPP
