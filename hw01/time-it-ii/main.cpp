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

using std::unique_ptr;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
// Make a data structure ?? Why ? because a lot of the functions are repeated.
struct Book {
    // Members Using struct and making all public to easily see use of stopwatch
    string _fileName; //can use this like ifstream.open( _fil..me)
    string wholeBook;
    std::vector <string> bookTextVector;
    std::list <string> bookTextList;
    std::deque <string> bookTextDeque;

    //Constructors
    Book () = delete ; //disabling the default constructor
    Book (std::string fileName);

    void readTheBook(StopWatch &watch);
};

Book::Book ( std::string fileName):_fileName(fileName) {
}

void Book::readTheBook (StopWatch &watch)  {
    //Read method
    //Read all three ways at the same time ??
    ifstream myFile ;

    //vector
    myFile.open(_fileName);
    if (myFile.fail())
        cout << "wtf\n";
    string inputLine ;

    cout << inputLine ;
    watch.Start();
    while (myFile >> inputLine) {
        cout << inputLine;
        if(!inputLine.empty())
            bookTextVector.push_back(inputLine);
    }
    watch.Stop();
    cout << "Time to read into vector :" << watch.getCurrentTimeInMilliseconds() << endl;
    myFile.close();

    //list
    myFile.open(_fileName);
    watch.Start();
    while (myFile >> inputLine) {
        if(!inputLine.empty())
            bookTextList.push_back(inputLine);
    }
    watch.Stop();
    cout << "Time to read into List :" << watch.getCurrentTimeInMilliseconds() << endl;
    myFile.close();

    //deque
    myFile.open(_fileName);
    watch.Start();
    while (myFile >> inputLine) {
        if(!inputLine.empty())
            bookTextList.push_back(inputLine);
    }
    watch.Stop();
    cout << "Time to read into Deque :" << watch.getCurrentTimeInMilliseconds() << endl;

    myFile.close();
    //If read in the same section, the output can be compared for the same book.

}


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

    for (auto &currentBook : vecOfBookPtrs) {
        //notice that can't use auto currentBook because Book() = delete :)

        currentBook->readTheBook(myWatch);

    }

    // Read book

    // store random string

    // Find the random string

    // Sort the containers


    return 0;
}
