//
// Created by uddeepk on 1/30/21.
//

#include "StopWatch.hpp"
#include <iostream>

using std::cout;

//Constructor starts the clock
StopWatch::StopWatch():_startTime(std::chrono::system_clock::now()), _isRunning(true) {
    cout << "Constructed a StopWatch via Default Constructor.\n";
}

StopWatch::~StopWatch() {
    cout << "Destructor for StopWatch is called.\n";
}
void StopWatch::Start() {
    _startTime = std::chrono::system_clock::now();
    _isRunning = true;
    cout << "Restarted StopWatch.\n" ;
}

void StopWatch::Stop () {
    _stopTime = std::chrono::system_clock::now();
    _isRunning = false;
    cout << "Stopped StopWatch.\n";
}

double StopWatch::getCurrentTimeInSeconds() {
    // Should I use a getElapsedTime method and then just convert it ??
    if (_isRunning) {
       return std::chrono::duration<double> ( std::chrono::system_clock::now() - _startTime).count();
    }
    else {
        return std::chrono::duration<double> (_stopTime - _startTime).count() ; //ratio will be 1:1
    }

}

double StopWatch::getCurrentTimeInMilliseconds() {
    // Same as above should I use a getElapsedTime method and just convert it ?
    if (_isRunning) {
        return std::chrono::duration<double,std::milli> (std::chrono::system_clock::now() - _startTime).count();
    }
    else {
        return std::chrono::duration<double,std::milli> (_stopTime - _startTime).count();
    }

}