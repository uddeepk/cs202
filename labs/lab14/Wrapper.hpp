//
// Created by uddeepk on 4/6/21.
//

#ifndef LAB14_WRAPPER_HPP
#define LAB14_WRAPPER_HPP
#include<sstream>
template<typename T>
class Wrapper {
public:
    Wrapper(T wrapee);
    T getWrapee () const;
    template<typename R>
    friend std::ostream& operator <<( std::ostream &os, const Wrapper<R> &w);
    operator std::string();
private:
    T _data;
};
template<typename T>
Wrapper<T>::Wrapper(T wrapee):_data(wrapee)
{}
template<typename T>
T Wrapper<T>::getWrapee() const{
    return _data;
}
template<typename T>
std::ostream& operator << (std::ostream &os, const Wrapper<T> &w) {
    os << w._data;
    return os;
}

template<typename T>
Wrapper<T>::operator std::string() {
    std::ostringstream os;
    os << _data;
    return os.str();
}

#endif //LAB14_WRAPPER_HPP
