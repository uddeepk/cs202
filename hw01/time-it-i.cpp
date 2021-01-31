#include <iostream>
#include <chrono>
#include "StopWatch.hpp"

int main() {
    auto start = std::chrono::system_clock::now();
    std::cin.get();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> dick = end - start ;
    std::cout <<  dick.count() << std::endl;

    return 0;
}
