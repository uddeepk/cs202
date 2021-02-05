/*
 * c_style_strings.cpp
 * Uddeep Karki
 * Feb 1, 2021
 *
 * Make the two following functions without use of any standard library functions.
 * char* strdup(const char*) //copies C-style string into memory it allocates dynamically (using new)
 *
 * char* findx(const char* s, const har* x) //that finds the first occurance of the C-style string x in s.
 */
#include <iostream>
#include <vector>

char* strdup(const char*);
char* findx (const char* s, const char* x);

int main() {
    const char* message  = "asdf asdf asdf asdf Julia aasdf asdf asdf ";
    char* test = strdup(message);
    printf("%s\n", test);
    //std::cout << "Hello, World!" << std::endl;

    const char* myOtherTest = "Julia";
    auto found = findx(message, myOtherTest);
    //for ( int i = 0 ; i < 6 ; ++i ) ++message;

//    std::cout << &message << std::endl;
//    std::cout << found << std::endl;
    std::cout << &test << std::endl;
//    std::cout << &myOtherTest << std::endl;

    //std::cout << (message == myOtherTest) << std::endl;
    printf("%s\n", found);

    return 0;
}

char* strdup (const char* myCStyleString) {

    size_t n = 0;
    for (auto c = myCStyleString ; *c != '\0' ; ++c) {
        ++n;
    }

    char * myCharPtr = new char [n];
    //myCharPtr = (char *) malloc(n * sizeof (char)); //Did not require new so I

    char * myStrdup = myCharPtr;

    while (*myCStyleString != '\0') {
        *myStrdup = *myCStyleString;
        ++myCStyleString;
        ++myStrdup;
    }
    *myStrdup = '\0';
    return myCharPtr;

}

char* findx(const char* s, const char* x) {
    //std::cout << &s << std::endl;
    for ( ; *s != '\0' ; ++s) {
        if ( *s == *x ) {
            const char* myTempStringPtr = s;
            auto tempXPtr = x;
            for ( ; *tempXPtr != '\0' ; ++tempXPtr,++myTempStringPtr) {
                //printf("%c", *myTempStringPtr);
                if (*tempXPtr != *myTempStringPtr)
                    break;
            }
            if (*tempXPtr == '\0')
                return (char* ) s;
        }
    }
    return strdup("nada");
}