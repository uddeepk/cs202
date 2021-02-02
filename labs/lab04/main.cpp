#include <iostream>
#include <sstream>

using std::cout;
using std::string;
using std::cin;
int main() {
    /*
    std::ostringstream sout;
    sout << "Hello, World!" << 3.14159;
    cout << sout. str() << std::endl;

    std::istringstream sin("4 25.6 Hello");
    int x;
    double d;
    std::string s;
    sin >> x;
    sin >> d;
    sin >> s;

    cout <<x << d << s << "\n";

    int i; int j;
    //std::cin >> i >> j;

    */

    while (true) {
        cout << "Enter an int and a word: ";
        string s;
        getline(cin, s);
        std::istringstream sin(s);
        int i;
        string word;
        sin >> i >> word;
        if(!sin) {
            cout << "You messed up!\n";
            break;
        }
        cout << "int was " << i << " and word was " << word << std::endl;
    }
    return 0;
}
