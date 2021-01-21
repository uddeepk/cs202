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

        if ( !validNumber( argv[3])) {
            std::cerr << "Temperature not in number" << std::endl;
            return 1;
        }
        //Make sure the third argument is a number

    //Get answers depending upon arguments

    return 0;
}

double cpp_ftoc(const char* str) { //Converts using C++ STL (stod)
    double tempF = std::stod(std::string(str)) ;

    return ((tempF - 32) * 9 / 5 );
}

double c_ctof(const char* str) {//Uses C function strtod to do conversions
    return 0;
}

bool validNumber ( const char* temp) {
    return true;
}