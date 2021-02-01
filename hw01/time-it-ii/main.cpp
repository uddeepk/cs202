// Time It II
// To compile, borrow or link the files from the time-it-i folder.

#include "../time-it-i/StopWatch.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <deque>
#include <memory>

/* Read at least 5 Gutenberg Project books with std::string; record the time taken to read with atleast
 * 3 containers. I am using vector, list, and deque. Also, record times to "find" a random string and
 * "sort" each container. Graph the results.
 * Also, talk about memory used. How ????
 */

// Make a data structure ?? Why ? because a lot of the functions are repeated.
struct Book {
    // Members Using struct and making all public to easily see use of stopwatch
    const char * _fileName; //can use this like ifstream.open( _fil..me)
    std::vector <std::string> bookTextVector;
    std::list <std::string> bookTextList;
    std::deque <std::string> bookTextDeque;

    //Constructors
    Book () = delete ; //disabling the default constructor
    Book (std::string fileName);
};

Book::Book ( std::string fileName):_fileName(fileName.c_str()) {
}
//Read method
    //Read all three ways at the same time ??
    //If read in the same section, the output can be compared for the same book.

//get a random string

// Sort the containers

// function for outputting both seconds and millis ??

static const std::vector <std::string> DEFAULT_FILENAMES = { "pg13332.txt", "22680-0.txt" , "42357-0.txt",
                                                "pg27507.txt", "pg35461.txt" };
using std::unique_ptr;
using std::cout;
int main() {
    StopWatch myWatch = StopWatch();
    std::ifstream myFile ;
    //myFile.open("pg13332.txt");
    std::vector <unique_ptr <Book>> vecOfBookPtrs;
    // Making vector of books
    for ( auto path : DEFAULT_FILENAMES) {
        vecOfBookPtrs.push_back(std::make_unique<Book>(path));
    }
    cout << vecOfBookPtrs.size();
    // Read book

    // store random string

    // Find the random string

    // Sort the containers


    return 0;
}
