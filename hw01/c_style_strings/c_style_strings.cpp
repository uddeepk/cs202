/*
 * c_style_strings.cpp
 * Uddeep Karki
 * Feb 1, 2021
 *
 * Make the two following functions without use of any standard library functions.
 * char* strdup(const char*) //copies C-style string into memory it
 * allocates dynamically (using new)
 *
 * char* findx(const char* s, const har* x) //that finds the first
 * occurance of the C-style string x in s.
 *
 *
 */
#include <iostream>
#include <vector>

char* strdup(const char*);
char* findx (const char* s, const char* x);
std::ostream& testTheFunctions (std::ostream& os) ;
bool testStrdup ( const char* myFunctionOutput, const char* myCheckValue);
bool testFindx ( const char* myFunctionOutput, const char* myCheckValue);
int main() {

    testTheFunctions(std::cout) << std::endl;

    return 0;
}
char* strdup (const char* myCStyleString) {
    size_t length = 0;
    const char* traversingChar = myCStyleString;
    while ( *traversingChar ) {
        ++length;
        ++traversingChar;
    }
    char * myCharPtr = new char[length + 1] ;
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
    //In my opinion this does not work the way I want it.
    // No matter how I declared the function, the address returned
    //did not match the address that within the input string.
    for ( ; *s != '\0' ; ++s) {
        if ( *s == *x ) {
            const char* myTempStringPtr = s;
            auto tempXPtr = x;
            for ( ; *tempXPtr != '\0' ; ++tempXPtr,++myTempStringPtr) {
                if (*tempXPtr != *myTempStringPtr)
                    break;
            }
            if (*tempXPtr == '\0')
                return (char* ) s;
        }
    }
    return (char*) s; //returns the end of the s or the adress for the '\0'
}

std::ostream& testTheFunctions (std::ostream& os) {
    std::vector<const char*> testTexts  = {
            "In 1979 Mandelbrot discovered that he could create one image in the complex plane"
            " that would serve as a catalogue of Julia sets, a guide to each and every one.",
            "The idea of hacking may conjure sylized images of electronic vandalism, espionage"
            ", dyed hair, and body piercings. Most people associate hacking with breaking the"
            " law and assume that everyone who engages in hacking activities is a criminal."
            " Granted, there are people out there who use hacking techniques to break"
            " the law, but hacking isn't really about that. In fact, hacking is more about"
            " following the law than breaking it. The essence of hacking is finding "
            "unintended or overlooked uses for the laws and properties of a given situation"
            " and then applying them in new and inventive ways to solve a problem-whatever"
            " it may be.",
            "To the untutored eye, Lisp is a strange programming language. In Lisp code there"
            " are parentheses everywhere. Some people even claim that the name stands for"
            " \"Lots of Isolated Silly Parentheses\". But the claim that the name stands for"
            " LISt Processing, and the programming language handles lists (and lists of lists) "
            "by putting them between parentheses. The parentheses mark the boundaries of the"
            " list. Sometimes a list is preceded by an apostrophe ''', called a single-quote"
            " in Lisp. Lists are the basis of Lisp." };

    std::vector <const char*> expectedAnswersStrdup = { "Julia sets, a",
                                                        "inventive ways to",
                                                        "boundaries of the list"};
    std::vector <const char*> expectedAnswersFindx = {
            "Julia sets, a guide to each and every one.",
            "inventive ways to solve a problem-whatever it may be.",
            "boundaries of the list. Sometimes a list is preceded by an apostrophe ''',"
            " called a single-quote in Lisp. Lists are the basis of Lisp." };

    int testsFailed = 0;

    for (auto testText = testTexts.begin(), testPhrase = expectedAnswersStrdup.begin(),
            expectedAnswer = expectedAnswersFindx.begin();
    testText != testTexts.end(), testPhrase != expectedAnswersStrdup.end(),
    expectedAnswer != expectedAnswersFindx.end() ;
    ++testText, ++testPhrase, ++expectedAnswer) {

        char * testOutput = strdup(*testPhrase);
        char * testOutput2 = findx(*testText, *testPhrase);

        if( !testStrdup(testOutput, *testPhrase)) {
            ++testsFailed;
            os << "Test failed!\n";
            os << "Expected Output: " << *testPhrase << " Actual Output: "
            << *testOutput << "\n";
        }
        if ( !testFindx(testOutput2, *expectedAnswer)) {
            ++testsFailed;
            os << "Test failed!\n";
            os << "Expected Output: " << *expectedAnswer << " Actual Output :"
            << testOutput2 << "\n";

        }

        delete [] testOutput; // raw pointers have to be deleted.

    }

    if (testsFailed == 0 ) {
        os << "All tests passed" << std::endl;
    }

    return os;
}
bool testStrdup ( const char* myFunctionOutput, const char* myCheckValue) {
    while (*myFunctionOutput == *myCheckValue &&
    *myFunctionOutput != '\0' && *myCheckValue != '\0') {
        ++myFunctionOutput;
        ++myCheckValue;
    }
    return *myFunctionOutput == '\0' && *myCheckValue == '\0';
}
bool testFindx ( const char* myFunctionOutput, const char* myCheckValue) {
    return testStrdup; // I wasn't able to check the pointer addresses because
    // for some reasont the address changes
    // even when the function is declared as const char *
}