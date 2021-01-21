/*
 * Uddeep Karki
 * Homework 0
 * CS202
 * Spring 2021
 *
 * Temperature
 * Converts temperature from degrees Farenheit to degrees Celsius by processing the command line
 * variables argc and argv.
 *
 * Instructions: From command line the following are ways to put input
 * temperature --ftoc 50
 * temperature --ctof -40
 *
 */

#include <iostream>
#include <string>
#include <cstring>

using std::string;
double cpp_ftoc(const char* str) ; //Converts using C++ STL (stod)
double c_ctof(const char* str) ; //Uses C function strtod to do conversions
bool validNumber (const char*str) ;
int main(int argc, char **argv) {

    // Take input

    //Check input validity
        //Check correct number of args
        if ( argc != 3) {
            std::cerr << (argc < 3 ? "too few " : "too many ") << " arguments."<<
             "\nPut answer in form $temperature conversionType number" << std::endl;
            return 1;
        }
        //Ensure arguments are correct

        string conversionType ( argv[1]);

        if ( !validNumber( argv[2])) {
            std::cerr << "Temperature not in number" << std::endl;
            return 1;
        }
        //Make sure the third argument is a number

    //Get answers depending upon arguments
    if ( conversionType == "--ftoc" ) {
        std::cout << "The temperature is " << cpp_ftoc(argv[2]) <<" degrees Celsius." << std::endl;
    }
    else if (conversionType == "--ctof") {
        std::cout << "The temperature is " << c_ctof(argv[2]) << " degrees Farenheit." <<std::endl;
    }
    else {
        std::cerr << "Improper conversion type call. Did you mean --ftoc or --ctof?" << std::endl;
        return 1;
    }

    return 0;
}

double cpp_ftoc(const char* str) { //Converts using C++ STL (stod)
    double tempF = std::stod(std::string(str)) ;

    return ((tempF - 32) * 5 / 9 );
}

double c_ctof(const char* str) {//Uses C function strtod to do conversions
    double tempC = strtod(str, NULL);

    return ((tempC * 9 / 5 ) + 32 );
}

bool validNumber ( const char* str) {
    size_t len = strlen ( str );
    size_t offset = 0;

    if( len == 0) {
        return false;
    }

    if (str [0] == '-' || str[0] == '+') {
        offset = 1;
    }

    int numOfDigits = 0, numOfDots = 0;

    for ( size_t i = 0 + offset ; i < len ; ++i) {
        if(str[i] >= '0' && str[i] <= '9') {
            ++numOfDigits;
        }
        else if ( str [i] == '.' ) {
            ++numOfDots;
        }
        else {
            return false;
        }

        if ( numOfDots > 1 ){
            return false;
        }
    }
    return (numOfDigits > 0);
}