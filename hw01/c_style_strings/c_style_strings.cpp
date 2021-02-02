/*
 * c_style_strings.cpp
 * Uddeep Karki
 * Feb 1, 2021
 *
 * Make the two following functions without use of any standard library functions.
 * char* strdup(const char*) //copies C-style string into memroy it allocates dynamically (using new)
 *
 * char* findx(const char* s, const har* x) //that finds the first occurance of the C-style string x in s.
 */
#include <iostream>

char* strdup(const char*);
char* findx (const char* s, const char* x);

int main() {
    const char* message = "Hello World!";
    char* test = strdup(message);
    printf("%s", test);
    //std::cout << "Hello, World!" << std::endl;
    delete test;
    return 0;
}

char* strdup (const char* myCStyleString) {
    char * myCharPtr = new char();

    char * myStrdup = myCharPtr;

    while (*myCStyleString != '\0') {
        *myStrdup = *myCStyleString;
        ++myCStyleString;
        ++myStrdup;
    }
    *myStrdup = '\0';
    myStrdup = nullptr; // do i need to do this ?
    delete myStrdup; // same as above.
    return myCharPtr;

}