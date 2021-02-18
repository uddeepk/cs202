#include <iostream>
#include <sstream>
#include "TokenAndPosition.hpp"

using std::istringstream;
int main() {
    std::istringstream testIss("Hello, World! \n ifthere asdf");
    readLines(testIss);
    testIss.clear();
    testIss.str("n 1 6 berry\n\n"
            " vc 255 0 0");
    readLines(testIss);
    return 0;
}
