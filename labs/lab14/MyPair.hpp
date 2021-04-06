//
// Created by uddeepk on 4/6/21.
//

#ifndef LAB14_MYPAIR_HPP
#define LAB14_MYPAIR_HPP
#include <string>
#include <sstream>
template<typename First, typename Second>
class MyPair {
public:
    MyPair(First first, Second second);
    First getFirst() const;
    Second getSecond() const;
    void setFirst(First first);
    void setSecond(Second second);
    operator std::string() {
        std::ostringstream os;
        os << _first << " " << _second;
        return os.str();
    }
private:
    First _first;
    Second _second;
};
template<typename First, typename Second>
MyPair<First, Second>::MyPair(First first, Second second):_first(first), _second(second)
{}
template<typename First, typename Second>
First MyPair<First, Second>::getFirst() const {
    return _first;
}
template<typename First, typename Second>
Second MyPair<First, Second>::getSecond() const {
    return _second;
}
template<typename First, typename Second>
void MyPair<First, Second>::setFirst(First first) {
    _first = first;
}
template<typename First, typename Second>
void MyPair<First, Second>::setSecond(Second second) {
    _second = second;
}
template<typename First, typename Second>
MyPair<First, Second> makeMyPair( First first, Second second) {
    MyPair<First, Second> ret {first, second};
    return ret;
}
//template<typename First, typename Second>
//operator typename MyPair<First, Second>::std::string() {
//
//}
#endif //LAB14_MYPAIR_HPP
