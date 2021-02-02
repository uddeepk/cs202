/*
 * Lab 04
 * Uddeep Karki
 *
 * Display the contents of a file, then ask user for a number and a line of text.
 * After, append the text to the file the number of times input by user.
 */

#include <iostream>
#include <sstream>
#include <fstream>

using std::cout;
using std::string;
using std::cin;

void output (std::ostream &os) {
    os << "Hello world.\n";
}
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

    /*
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
            if (sin.eof())
                cout << "Because you didn't give enough input.\n";
            sin.clear();
        } else
            cout << "int was " << i << " and word was " << word << std::endl;
        if ( i == 13 )
            break;

        cout << "int was " << i << " and word was " << word << std::endl;
    }
    */

    /* //Using cin
    while (true) {
        cout << "Enter an int and a word: ";
        string s;
        //getline(cin, s);
        //std::istringstream sin(s);
        int i;
        string word;
        cin >> i >> word;
        if (!cin) {
            cout << "You messed up!\n";
            if (cin.eof())
                cout << "Because you didn't give enough input.\n";
            cin.clear();
            cin.ignore(9999, '\n');
        } else
            cout << "int was " << i << " and word was " << word << std::endl;

        if (i == 13)
            break;
    }
    output (cout);
    std::ostringstream ostring("foo.txt");
    output(ostring);
    cout << "the ostringstream got " << ostring.str() << "\n" ;

    */

    while (true) {
        //Open text file and display the contnets to the console
        std::ifstream myFileStream("myInputFile.txt");

        if (!myFileStream) {
            cout << "Ensure file is present!\n" ;
            break;
        }
        string readBuffer;

        while (getline(myFileStream, readBuffer)) {
            cout << readBuffer << "\n";
        }
        myFileStream.close();

        // Query the user for a number n, and a line of text, to be entered all on one line
        cout << "Enter a number and a line of text in same line : ";

        getline(cin, readBuffer);

        std::istringstream myInputStream(readBuffer);

        int numberOfCopies;

        string lineOfText;

        myInputStream >> numberOfCopies;
        myInputStream.get();
        getline(myInputStream, lineOfText);

        if ( !myInputStream) {
            cout << "You messed up!\n";
            if (!myInputStream.eof())
                cout << "Because you didn't have enough input!\n";
            myInputStream.clear();
        } else {
            //cout << lineOfText ;
            // Append n copies of the line of text to the file.
            std::ofstream myOutputFile("myInputFile.txt", std::ios::app);

            for (int times = 0; times < numberOfCopies; ++times) {
                myOutputFile << '\n';
                myOutputFile << lineOfText;
            }
        }
        if ( numberOfCopies == 13)
            break;
    }

    return 0;
}
