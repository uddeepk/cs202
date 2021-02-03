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

char* strdup(const char*);
char* findx (const char* s, const char* x);

int main() {
    const char* message = "Hello World! asdf";
    char* test = strdup(message);
    printf("%s\n", test);
    //std::cout << "Hello, World!" << std::endl;
    delete test;
    char *myOtherTest = "World";
    char *found = findx(message, myOtherTest);
    printf("%s\n", found);
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

char* findx(const char* s, const char* x) {

    for ( ; *s != '\0' ; ++s) {
        if ( *s == *x ) {
            const char* myTempStringPtr = s;
            auto tempCharPtr = x;
            for ( ; *tempCharPtr != '\0' ; ++tempCharPtr,++myTempStringPtr) {
                //printf("%c", *myTempStringPtr);

                if (*tempCharPtr != *myTempStringPtr)
                    break;
            }
            if (*tempCharPtr == '\0')
                return strdup(s); //

            //Do i delete myTempStringPtr and tempCharPtr
            //Also what do I return for char* ??
        }
    }
    return strdup("nada");
}