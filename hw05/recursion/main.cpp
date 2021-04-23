#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

//unsigned long long fib(unsigned )
unsigned long long fib(unsigned long long n);

unsigned long long fib_loop(unsigned long long n);

long long ack ( long long m, long long n) {
    if (m == 0)
        return n + 1;
    if (m > 0) {
        if (n == 0)
            return ack(m - 1, 1);
        if (n > 0)
            return ack( m - 1 , ack ( m , n - 1));
    }
}
int main() {
    std::vector<unsigned long long> fibNums { 0, 1};
    std::string readBuffer;
    std::cout << "Hello, World!" << std::endl;
//    std::cout << fib ( 6) << "\n";
//    std::cout << fib_loop(6, fibNums)  << "\n";

    std::cout << "Printing Fibionacci Numbers from both functions\n";
    std::cout << "Please press enter to continue";
    getline(std::cin, readBuffer);
    std::cout << std::setw(4) << "n" << std::setw(22) << "fib" << std::setw(22) << "fib_loop" <<"\n";
    for (unsigned long long i = 0 ; i < 38 ; ++i ) {
        std::cout << std::setw(4) << i << std::setw( 22) << fib ( i ) << std::setw(22) << fib_loop(i) << "\n";

    }
    std::cout << "Here we only are going to n = 37 because after this, the recursive function takes too long." << "\n";
    std::cout << "\n";
    std::cout << "Trying to find max fibionacci number possible in this system" << "\n";
    std::cout << "Please press enter to continue";
    getline(std::cin, readBuffer);
    std::cout << std::setw(4) << "n" << std::setw(22) << "fib_loop" << "\n";
    for ( unsigned long long i = 0 ; i < 95/*std::numeric_limits<unsigned long long>::max()*/; ++i) {
        std::cout << std::setw(4) << i << std::setw( 22) << fib_loop ( i ) << /*" " << fib(i, fibNums) << */  "\n";
    }

    std::cout << "Notice the overflow at n = 94, for the 95th Fibionacci number" << "\n";
    std::cout << "Thus the bigges number that can be computed is the 94h Fibionacci number 12200160415121876738.";
    std::cout << "\n\n";
    std::cout << "Please press enter to continue";
    getline(std::cin, readBuffer);

    std::cout << ack(1, 4) << "\n";
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
