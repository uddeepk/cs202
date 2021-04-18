#include <iostream>
#include <vector>

int fib(int n) {
    if ( n <= 0  )
        return 0;
    if ( n == 1)
        return 1;
    return fib ( n - 1) + fib (n - 2 );
}
int fib_loop(int n) {
    std::vector<int> fibNums { 0, 1};
    if ( n >= 0 && n < 2 )
        return fibNums[n];
    for ( int i = 2 ; i <= n ; ++i) {
        fibNums.push_back(fibNums[i-1] + fibNums[i-2]);
    }
    return fibNums[n];
}
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
    std::cout << "Hello, World!" << std::endl;
    std::cout << fib ( 6) << "\n";
    std::cout << fib_loop(6)  << "\n";
    std::cout << ack(4, 1) << "\n";
    return 0;
}
