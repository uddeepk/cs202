//
// Created by uddeepk on 1/30/21.
//

#include "StopWatch.hpp"
#include <iostream>

using std::cout;

//Constructor starts the clock
StopWatch::StopWatch():_startTime(std::chrono::system_clock::now()) {
    cout << "Constructed a StopWatch via Default Constructor.\n";
}

void StopWatch::Start() {
    _startTime = std::chrono::system_clock::now();
    cout << "Restarted StopWatch.\n" ;
}

void StopWatch::Stop () {
    _stopTime = std::chrono::system_clock::now();
    cout << "Stopped StopWatch.\n";
}