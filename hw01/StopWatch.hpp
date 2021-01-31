//
// Created by uddeepk on 1/30/21.
//

#ifndef HW01_STOPWATCH_HPP
#define HW01_STOPWATCH_HPP

#include <chrono>
#include <string>

class StopWatch {
public:
    //Needs constructor
    StopWatch(); //Default Constructor
    StopWatch(const StopWatch &watch); //Copy Constructor ; do I need it ?
    StopWatch(const std::string& name); //Other Constructor ???
    ~StopWatch(); //Destructor
    //Start method
    void Start();
    //Stop method
    void Stop();
    //Method to report time in seconds as double
    double getCurrentTimeInSeconds();
    //Method to report time in milliseconds as double
    double getCurrentTimeInMilliseconds();
private:
    //Data member would it be start time according to system clock ?


};


#endif //HW01_STOPWATCH_HPP
