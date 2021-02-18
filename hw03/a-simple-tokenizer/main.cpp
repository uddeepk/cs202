#include <iostream>
#include <sstream>
#include "TokenAndPosition.hpp"

using std::istringstream;
int main() {
    std::istringstream testIss("Hello, World! ");
    readLines(testIss);
    return 0;
}
