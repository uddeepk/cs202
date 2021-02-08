//Uddeep Karki
//Hw02
//Additional Program 1: Lower Case Letters
//This program contains a function to replace all uppercase letters in the C-style string s
//with their lowercase equivalents without using any standard library functions.
#include <iostream>

void to_lower(char* s); // declaring the function

int main() {
    char testString[] { "My Test String"};
    std::cout << testString<< std::endl;
    std::cout << "After to_lower" << std::endl;
    to_lower(testString);
    std::cout << testString << std::endl;
    return 0;
}

void to_lower(char* s) {
    //defining the function
    while ( *s != 0) { //used how '\0' == 0 from pdf for hw2
        if ( *s >= 'A' && *s <= 'Z')
            *s += 32;

        ++s;
    }
}