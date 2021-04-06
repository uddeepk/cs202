//
// Created by uddeepk on 4/6/21.
//

#ifndef LAB14_MYPAIR_HPP
#define LAB14_MYPAIR_HPP

template<typename First, typename Second>
class MyPair {
public:
    MyPair(First first, Second second);
    int getFirst() const;
    char getSecond() const;
    void setFirst(First first);
    void setSecond(Second second);
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

#endif //LAB14_MYPAIR_HPP
