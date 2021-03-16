//
// Created by uddeepk on 3/2/21.
//

#include "SmartArray.hpp"

using std::size_t;
SmartArray::SmartArray(size_t size) :_size(size), _data(new int[size]) {
}
SmartArray::~SmartArray() {
    delete [] _data;
}
int &SmartArray::operator[](size_t index) {
    return _data[index];
}
const int &SmartArray::operator[](size_t index) const {
    return _data[index];
}
size_t SmartArray::size() const {
    return _size;
}

SmartArray::SmartArray(const SmartArray &orig) :_size{orig._size}, _data(new int[orig._size]){
    for(size_t i = 0 ; i < _size ;  ++i) {
        _data[i] = orig._data[i];
    }
}

SmartArray &SmartArray::operator=(const SmartArray &orig) {
//    if (_data == orig._data)
    if ( &orig == this)
        return *this;

    delete [] _data;
    _size = orig._size;
    _data = new int[_size];
    for ( size_t i = 0; i < _size ; ++i ){
        _data[i] = orig._data[i];
    }

    return *this;
}
