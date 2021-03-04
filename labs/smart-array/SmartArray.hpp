//
// Created by uddeepk on 3/2/21.
//

#ifndef SMART_ARRAY_SMARTARRAY_HPP
#define SMART_ARRAY_SMARTARRAY_HPP


class SmartArray {
public:
    SmartArray (int size);
    ~SmartArray();
    int & operator[](unsigned int index);
    const int & operator[](unsigned int index) const;

    int size() const; //
private:
    int * _data;
    int _size;
};


#endif //SMART_ARRAY_SMARTARRAY_HPP
