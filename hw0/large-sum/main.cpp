/* 
   Uddeep Karki
   CS202
   Project Euler Problem 13 Large Sum
   
   Writing a program to workout the first ten digits of the sum of 100 50-digit numbers.

*/

/*
  Proposed Solution: Reading input from a file line at a time. Storing the numbers
  as a string. Then working for the sum from the last digit. 
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

using std::vector;
using std::getline;
using std::string;
using std::cerr; using std::cout; using std::endl;

string getSumOfNumbers ( const vector <string>& );

int main() {
  vector <string> fiftyDigitNumbers ;//Vector to store the numbers

  std::ifstream myFile ;

  myFile.open("input.txt");
  
  if(myFile.fail()) { 
    //If file opening failed. Figure out another way to do it maybe using try catch.
    cerr << "input.txt not available. Place input.txt in the same locations as this file." << endl;
    return 1;
  }
  
  string temp;
  while (getline(myFile, temp)) {//Continues while input is good(or until it reaches eof)
    //Added regex to ensure input is correct
    std::regex re ("\\D");
    std::smatch m;
    
    if (std::regex_search( temp, m, re)) {
      cerr << "Invalid input. Non digit character present. Search for " << m.str() << endl;
      return 1;
    }
      
    if (temp.length() != 50 ) {
      //throw "Numbers not 50 digits long!";
      cerr << "The numbers are not 50 digits long !" << endl;
      return 1;
    }
      
    //Push temp into vecNum
    fiftyDigitNumbers.push_back(temp);
  }

 
  myFile.close();
  
  string sumOfNumbers = getSumOfNumbers (fiftyDigitNumbers);
  cout << sumOfNumbers << endl;
  return 0;
}

string getSumOfNumbers( const vector <string> &v ) {
  long long sumOfDigits = 0 ;  //This will store the sum of digits at the certain location
  string sum ;
  
  for ( int i = 0 ; i < 50 ; ++i)  {
    for (const auto &s : v) {
      sumOfDigits += ( s[49-i] - '0');
    }
    char tempDigit = ((sumOfDigits % 10) + '0'); //Extracting last digit
    sum = tempDigit + sum;
    sumOfDigits /= 10;
      
  }

  sum = std::to_string(sumOfDigits) + sum;

  return sum;
  
}
    
