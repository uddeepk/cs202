// Uddeep Karki
// CS 202
// Hw2
// Time It II
// To compile, borrow or link the files from the time-it-i folder. It needs StopWatch.hpp, and StopWatch.cpp.
// Also, ensure that the books' .txt files are present, otherwise modify code for you own files.

#include "../time-it-i/StopWatch.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Book.hpp"
#include <iomanip>
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

template <typename T>

std::ostream& displaySpreadApart ( std::ostream& os,const std::vector<T> &v) {
  for(const auto &t : v ) {
    os << std::setw(13) << t;
  }
  return os;
}

int main() {
    const static std::vector < std::string> DEFAULT_FILENAMES = { "22680-0.txt" , "42357-0.txt", "64317-0.txt",
                                                                  "pg27507.txt", "pg35641.txt" };

    StopWatch myWatch = StopWatch();

    std::vector<std::unique_ptr<Book>> vecOfBookPtrs;

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
    // Print book reading times
    cout << "Time to read books\n" ;
    int bookNumber = 1;
    std::vector <string> myContainersUsed = {"String" , "Vector" , "List" , "Deque"};

    cout << std::setw(8) << "Book";
    displaySpreadApart(cout, myContainersUsed)<< "\n";
    for (const auto &currentBook : vecOfBookPtrs) {
      cout << std::setw(8) << bookNumber;
      displaySpreadApart( cout, currentBook->_readTimes) << "\n";
      ++bookNumber;
    }
    cout << "\n";

    // Pring time to find
    cout << "Time to find in books\n" ;
    bookNumber = 1;
    cout << std::setw(8) << "Book";
    displaySpreadApart(cout, myContainersUsed)<< "\n";
    for(const auto &currentBook:vecOfBookPtrs) {
      cout << std::setw(8) << bookNumber;
      displaySpreadApart( cout, currentBook->_findTimes) << "\n";
      ++bookNumber;
    }
    cout << "\n";

    // Print time to sort
    cout << "Time to sort strings in books\n" ;
    bookNumber = 1;
    cout << std::setw(8) << "Book";
    displaySpreadApart(cout, std::vector(myContainersUsed.begin()+1, myContainersUsed.end())) << "\n";
    for(const auto &currentBook:vecOfBookPtrs) {
      cout << std::setw(8) << bookNumber;
      displaySpreadApart( cout, currentBook->_sortTimes) << "\n";
      ++bookNumber;
    }

    return 0;
}
