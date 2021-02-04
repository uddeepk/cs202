#include <iostream>
#include <iomanip>
#include <fstream>
using std::cin;
using std::cout;
using std::setw;
using std::ostream;
using std::ofstream;
using std::ifstream;
int main() {
//
//   std::ofstream fout("example.txt");
//
//   for (int i = 0 ; i < 100 ; ++i) {
//       //cout << setw(5) << i * i;
//       fout << setw(5) << i * i;
//   }
//
//   std::ifstream fin("example.txt");
//
//   fin.seekg(83 * 5);
//   int x;
//   fin >> x;
//   cout << "83 squared is " << x << std::endl;
//
//
//   int a[100] = {1, 2, 3};
//   int ii = 8 * 8;
//   ofstream fout("data.dat", std::ios::binary | std::ios::out);
//   fout.write( reinterpret_cast<const char*> (&a), sizeof(int)*100);
//   fout.close();
//
//   ifstream fin("data.dat", std::ios::binary | std::ios::in);
//
//   for (int j = 0; j < 4 ; ++j) {
//       char c;
//       fin.read(reinterpret_cast<char *>(&c), sizeof(c));
//       cout << (unsigned int)(c) << std::endl;
//   }


//    Binary Files
//    Purpose
//
//    In this lab, you will get open and read from a binary file containing integer data.
//            What to Do
//
//    Write a program that opens and reads from the binary file data.dat.
//
//            Read the integers from the file
//    Print the number of integers, their sum, and the average.
//
//            There are two reasonable ways to know how many integers to read. The first, and easiest is to test the stream after each read and see whether it failed or not (just as we normally do for input.) The second is to determine the file size ahead of time, using seekg() relative to the end, then tellg() to find out where you are.
//
//
    ifstream fin("data.dat", std::ios::binary | std::ios::in);

    if (!fin) {
        cout << "You messed up." << std::endl;
        if(fin.eof()) {
            cout << "Error not enough data" << std::endl;
        }
        return -1;
    }
    int counter = 0, sum = 0, number;

    //(X) Notice I can use while (fin.read(reinterpret_cast<char *>(&number), sizeof(int))) and
    //remove the if(!fin) check.
    while (true) { //Because I am using

        // fin.seekg(counter*sizeof(int)); // Unnecessary

        fin.read(reinterpret_cast<char *>(&number), sizeof(int)); //Look at note above (X)
        if (!fin) { //Look at note above (X)
            break;
        }

        cout << number << std::endl;
        sum += number;
        ++counter;
    }

    cout << "The sum is :" << sum << std::endl;
    cout << "The average is :" << static_cast<double> (sum) / counter << std::endl;

    return 0;
}
