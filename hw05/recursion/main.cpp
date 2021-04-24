#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
#include <fstream>
#include "StopWatch.hpp"

//unsigned long long fib(unsigned )
unsigned long long fib(unsigned long long n);

unsigned long long fib_loop(unsigned long long n);
std::vector <unsigned long long> getFibionacciFromFile();

long long ack ( long long m, long long n);
int main() {
    StopWatch myStopwatch{};
    std::vector <unsigned long long> fibioList =  getFibionacciFromFile ();
//    std::vector<unsigned long long> fibNums { 0, 1};
//    std::string readBuffer;
//    std::cout << "Hello, World!" << std::endl;
////    std::cout << fib ( 6) << "\n";
////    std::cout << fib_loop(6, fibNums)  << "\n";
//
//    std::cout << "Printing Fibionacci Numbers from both functions\n";
//    std::cout << "Please press enter to continue";
//    getline(std::cin, readBuffer);
//    std::cout << std::setw(4) << "n" << std::setw(22) << "fib" << std::setw(22) << "fib_loop" <<"\n";
//    for (unsigned long long i = 0 ; i < 38 ; ++i ) {
//        std::cout << std::setw(4) << i << std::setw( 22) << fib ( i ) << std::setw(22) << fib_loop(i) << "\n";
//
//    }
//    std::cout << "Here we only are going to n = 37 because after this, the recursive function takes too long." << "\n";
//    std::cout << "\n";
//    std::cout << "Trying to find max fibionacci number possible in this system" << "\n";
//    std::cout << "Please press enter to continue";
//    getline(std::cin, readBuffer);
//    std::cout << std::setw(4) << "n" << std::setw(22) << "fib_loop" << "\n";
//    for ( unsigned long long i = 0 ; i < 95/*std::numeric_limits<unsigned long long>::max()*/; ++i) {
//        std::cout << std::setw(4) << i << std::setw( 22) << fib_loop ( i ) << /*" " << fib(i, fibNums) << */  "\n";
//    }
//
//    std::cout << "Notice the overflow at n = 94, for the 95th Fibionacci number" << "\n";
//    std::cout << "Thus the bigges number that can be computed is the 94h Fibionacci number 12200160415121876738.";
//    std::cout << "\n\n";
//    std::cout << "Please press enter to continue";
//    getline(std::cin, readBuffer);
    char choice;

    do {

        long long x, y;
        while (true) {
            std::cout << "Please enter two numbers to find Ackerman numbers: ";
            if (std::cin >> x >> y) {
                break;
            } else {
                std::cout << "Invalid input! Please enter two integer values" << "\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        }
        myStopwatch.Start();
        auto ackNumber = ack(x, y);
        myStopwatch.Stop();

        std::cout << "Ackerman (" << x << ", " << y << ") = " << ackNumber << "\n";
        std::cout << "Time taken : " << myStopwatch.getCurrentTimeInSeconds() << " seconds." << "\n";
        std::cout << "\n";



        while (true) {
            std::cout << "Do you want to compute another Ackerman number?(y/n)";
            std::cin >> choice;
            if ( choice == 'y' || choice == 'n') {
                    std::cin.ignore(10000, '\n');
                break;
            }
            else {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Please enter valid choice y or n ! \n";
                continue;
            }
        }

} while ( choice == 'y');
    return 0;
}

unsigned long long fib(unsigned long long int n) {
    if ( n <= 0  )
        return 0;
    if ( n == 1)
        return 1;
    return fib ( n - 1) + fib (n - 2 );
}

unsigned long long fib_loop(unsigned long long int n) {
    std::vector<unsigned long long> fibNums { 0, 1};

    if ( n >= 0 && n < 2 )
        return fibNums[n];
    for ( std::size_t i = 2 ; i <= n ; ++i) {
        fibNums.push_back(fibNums[i-1] + fibNums[i-2]);
    }
    return fibNums[n];
}

// Gets the list of fibionacci numbers from the list procured from online encyclopedia of integer sequences
std::vector<unsigned long long> getFibionacciFromFile() {
    std::vector <unsigned long long> listOfFibio ;
    std::ifstream myFile ("b0000045.txt");
    std::string readBuffer ;
    while (std::getline(myFile, readBuffer)) {
        std::stringstream ss (readBuffer);
        unsigned long long buf, num;
        ss >> buf >> num;
        listOfFibio.push_back(num);
    }

    return listOfFibio;
}

long long ack(long long int m, long long int n) {
    if (m == 0)
        return n + 1;
    if (m > 0) {
        if (n == 0)
            return ack(m - 1, 1);
        if (n > 0)
            return ack( m - 1 , ack ( m , n - 1));
    }
}
