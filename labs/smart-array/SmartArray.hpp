//
// Created by uddeepk on 3/2/21.
//

#ifndef SMART_ARRAY_SMARTARRAY_HPP
#define SMART_ARRAY_SMARTARRAY_HPP

#include <cstddef>

class SmartArray {
public:
    explicit SmartArray (std::size_t size); // explicit stops implicit conversions
    SmartArray(const SmartArray&);
    ~SmartArray();
    SmartArray & operator=(const SmartArray &orig);
    int & operator[](std::size_t index);
    const int & operator[](std::size_t index) const;

    std::size_t size() const; //
private:
    int * _data;
    std::size_t _size;
};


#endif //SMART_ARRAY_SMARTARRAY_HPP
