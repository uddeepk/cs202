//
// Created by Uddeep Karki on 2/3/21.
// Struct to store the test results
//

#ifndef HW01_TIMESFORPROCESSING_HPP
#define HW01_TIMESFORPROCESSING_HPP
#include <vector>
#include <iostream>

struct TimesForProcessing {

    TimesForProcessing(int trialNumber);

    int _trialNumber;
    std::vector <double> _timeForFillingVector;
    std::vector <double> _timeForSearch;
    std::vector <double> _timeForSort;
    std::vector <double> _timeForBinary_Search;
    std::vector <double> _timeForShuffle;

    std::ostream &displayData(std::ostream &os) ;
    std::ostream &printField ( std::ostream &myOutputStream, std::vector <double> &v);
    std::ostream &printField ( std::ostream &myOutputStream, std::vector <int> &v);
};


#endif //HW01_TIMESFORPROCESSING_HPP
