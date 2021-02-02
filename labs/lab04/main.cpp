#include <iostream>
#include <sstream>

using std::cout;

int main() {
    std::ostringstream sout;
    sout << "Hello, World!" << 3.14159;
    cout << sout. str() << std::endl;


    std::istringstream sin("4 25.6 Hello");
    int x;
    double d;
    std::string s;
    sin >> x;
    sin >> d;
    sin >> s;

    return 0;
}
