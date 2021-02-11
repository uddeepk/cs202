#include <iostream>
#include <vector>
#include <string>
#include "Cave.hpp"
#include <sstream>

int main() {
    Cave myCave;

    std::istringstream iss ("Longd\nShortd\nLongD2\nShortD2\n0 1\n1 2");

    myCave.readRooms(iss);



    return 0;
}
