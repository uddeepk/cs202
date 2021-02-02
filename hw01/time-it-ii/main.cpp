// Time It II
// To compile, borrow or link the files from the time-it-i folder.

#include "../time-it-i/StopWatch.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
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



int main() {
    const static std::vector < std::string> DEFAULT_FILENAMES = { "22680-0.txt" , "42357-0.txt", "64317-0.txt",
                                                                  "pg27507.txt", "pg35641.txt" };

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

        // Read book
        currentBook->readTheBook(myWatch);
        // Find random string
        currentBook->findRandomString(myWatch);
        // sort Containers
        currentBook->sortContainers(myWatch);

    }

    // Past this is testing getline vs >>
    ifstream testFileReading ;
    testFileReading.open ( DEFAULT_FILENAMES[0]);
    string readBuffer ;
    //while (testFileReading >> readBuffer) {
    while (getline(testFileReading, readBuffer)) {
        cout << readBuffer;
    }

    testFileReading.close();
    return 0;
}
