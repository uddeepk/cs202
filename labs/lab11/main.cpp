#include <iostream>

class Base {
public:
    Base ();
    Base (int) ;
    ~Base();
private:
    int _data ;
};

Base::Base() {
    std::cout << "Constructing a default Base object with number " << _data << std::endl;
}
Base::Base(int d):_data(d) {
    std::cout << "Constructing a Base Object with number " << _data << std::endl;
}
Base::~Base() {
    std::cout << "Destructing a Base Object with number " << _data << std::endl;
}

class Derived : public Base {
public:
    Derived (int d): Base(d) {

    }
    Derived(): Base(), _name("Default") {
        std::cout << "Constructing a default Derived object with name " << _name << std::endl;
    }
    Derived(int d, std::string name): Base(d), _name(name) {
        std::cout << "Constructing a Derived object with name " << _name << std::endl;
    }
    ~Derived () {
        std::cout << "Destructing Derived object with name " << _name << std::endl;
    }
private:
    std::string _name;
};

using std::cout ;
using std::endl;
int main() {
    {  Base b;}
    cout <<  endl;
    {  Base b{ 13};}
    cout <<  endl;
    {  Derived d;}
    cout <<  endl;
    {  Derived d{  16,  "Eliza"};}
    cout << endl;
    {  Derived d{ 3}; }
    return 0;
}
