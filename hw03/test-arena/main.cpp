#include <iostream>
#include <fstream>

int main() {
    std::string testString ("Wad up?");
    size_t size = testString.size();
//    std::cout << size ;
    std::fstream myFout;
    myFout.open("that_file.dat", std::ios::out | std::ios::binary);
    myFout.write(reinterpret_cast<char*>(&size), sizeof(size) );
    myFout.write ( testString.c_str(), testString.size());
    myFout.close();

    size = 0;
    std::fstream myFin ("that_file.dat", std::ios::in | std::ios::binary);

    myFin.read(reinterpret_cast<char*>(&size), sizeof(size) );
//    std::cout << size ;
    std::string textRead ;
    textRead.resize(size);

    myFin.read(&textRead[0], textRead.size() );
    myFin.close();
    //myFin.read

    std::cout << "Read text = " << textRead << std::endl;

    //16 doubles would be 128 bytes because double is a 8 bytes
    myFout.open("128bytes.dat", std::ios::out | std::ios::binary);

    double myDouble = 1;

    for(int i = 0 ; i < (16 * 9) ; ++i ) {
        myFout.write(reinterpret_cast<char *>(&myDouble), sizeof(myDouble));
//        std::cout << myFout.tellg() << std::endl;
    }
    std::cout << myFout.tellp() << std::endl; // tellp output position
    //tellg input position. But in fstreams they return the same

    return 0;
}
