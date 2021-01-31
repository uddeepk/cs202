//
// Created by uddeepk on 1/30/21.
//

#include "StopWatch.hpp"
#include <iostream>

using std::cout;

//Constructor starts the clock
StopWatch::StopWatch():_name("Default"),_startTime(std::chrono::system_clock::now()) {
    cout << "Constructed a StopWatch named _Default_ via Default Constructor.\n";
}

