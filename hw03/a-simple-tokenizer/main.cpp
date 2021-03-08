#include <iostream>
#include <sstream>
#include "TokenAndPosition.hpp"

using std::istringstream;
int main() {
    std::istringstream testIss("Hello, World! \n ifthere asdf");
    auto myTestTokens  {readLines(testIss)};
    printTokens(std::cout , myTestTokens);
    testIss.clear();
    testIss.str("n 1 6 berry\n\n"
            " vc 255 0 0");
    auto myTestTokens2 { readLines(testIss)};
    printTokens(std::cout , myTestTokens2);


    return 0;
}
