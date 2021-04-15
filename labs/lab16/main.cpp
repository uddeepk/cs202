#include <iostream>

// a_n = 2 * a_(n-1) - a_(n-2) is the same as arithmetic sequence
//int recurrentSequence( int n, int a = 0 , int b = 1 ) {
//    if ( n == 0)
//        return a;
//    if ( n == 1)
//        return b;
//    return 2 * recurrentSequence  (n-1, a, b) - recurrentSequence( n - 2, a, b);
//}
//int main() {
//    std::cout << recurrentSequence(6) << std::endl;
//    std::cout << recurrentSequence(5, 0, 3) << std::endl;
//
//    return 0;
//}
#include <iterator>
#include <vector>
using std::string;
using std::cout;
using std::vector;
template <typename Iterator>
void printReversed(Iterator theBegin, Iterator theEnd){
// ... your code here
if ( theBegin == theEnd)
    return;
    printReversed(theBegin + 1 , theEnd);
    cout << *theBegin << " ";
}

int main() {
    string s("Hello World!");
    printReversed(begin(s),end(s));
    cout << "\n";
    vector<int> primes{2,3,5,7,11,13,17};
    printReversed(begin(primes),end(primes));
    cout << "\n";
    return 0;
}
