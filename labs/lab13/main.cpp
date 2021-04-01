#include <iostream>

using std::cout;
using std::endl;
using std::string;

template<typename T>
T twice ( T t1 ) {
    return t1 + t1;
}
string twice( const char * carr ) {
    return twice(string(carr));
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    cout << twice(2) << endl;
    cout << twice(2.3) << endl;
    cout << twice(string("Hello")) << endl;
    cout << twice("Hello") << endl;

    return 0;
}
