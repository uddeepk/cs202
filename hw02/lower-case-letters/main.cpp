//Uddeep Karki
//Hw02
//Additional Program 1: Lower Case Letters
//This program contains a function to replace all uppercase letters in the C-style string s
//with their lowercase equivalents without using any standard library functions.

//Pass arguments in the command line and it will print out the char* with lower letters
//example
// $ test FooBar "My Test STRING"
// foobar my test string

#include <iostream>

void to_lower(char* s); // declaring the function

int main(int argc, char **argv) {
//    char testString[] = "My Test String";
//    std::cout << testString<< std::endl;
//    std::cout << "After to_lower" << std::endl;
//    to_lower(testString);
//    std::cout << testString << std::endl;
    if ( argc < 2) {
        std::cerr << "Not enough arguments!" << std::endl;
        return 1;
    }
    // else
    for ( size_t argumentIndex = 1 ; argumentIndex < argc ; ++argumentIndex ) {
        to_lower(argv[argumentIndex]); // Notice that char [] is
        std::cout << argv[argumentIndex] << " " ;
    }
    std::cout << std::endl;
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