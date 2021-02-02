// Time It II
// To compile, borrow or link the files from the time-it-i folder.

#include "../time-it-i/StopWatch.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include "Book.hpp"
/* Read at least 5 Gutenberg Project books with std::string; record the time taken to read with atleast
 * 3 containers. I am using vector, list, and deque. Also, record times to "find" a random string and
 * "sort" each container. Graph the results.
 * Also, talk about memory used. How ????
 */

using std::unique_ptr;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
// Make a data structure ?? Why ? because a lot of the functions are repeated.




//get a random string

// Sort the containers

// function for outputting both seconds and millis ??

const static std::vector < std::string> DEFAULT_FILENAMES = { "22680-0.txt" , "42357-0.txt", "64317-0.txt",
                                                         "pg27507.txt", "pg35641.txt" };

int main() {
    StopWatch myWatch = StopWatch();
    //std::ifstream myFile ;
    //myFile.open("pg13332.txt");
    std::vector<std::unique_ptr<Book>> vecOfBookPtrs;
    // Making vector of books
    for (auto path : DEFAULT_FILENAMES) {
        vecOfBookPtrs.push_back(std::make_unique<Book>(path));
    }

    // Read book
    for (auto &currentBook : vecOfBookPtrs) {
        //notice that can't use auto currentBook because Book() = delete :)

        currentBook->readTheBook(myWatch);
        currentBook->findRandomString(myWatch);
        currentBook->sortContainers(myWatch);

    }

    // Find the random string

    // Sort the containers


    return 0;
}