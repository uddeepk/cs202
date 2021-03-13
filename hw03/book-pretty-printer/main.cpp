/*
 * main.cpp
 * Uddeep Karki
 * 3/12/2021
 * main source file for homework 3 additional program 1 book pretty printer
 */

#include <iostream>
#include <sstream>
#include "MyParagraph.hpp"

using std::string;
using std::cout;

int main() {
    //
    // 1. Pass fstream / istream
    string test1 = "I felt I uttered my explanations awkwardly; the master frowned. 'It is\n"
                   "nothing, is it, Ellen Dean?' he said sternly. 'You shall account more\n"
                   "clearly for keeping me ignorant of this!' And he took his wife in his\n"
                   "arms, and looked at her with anguish.\n\n"
                   "At first she gave him no glance of recognition: he was invisible to her\n"
                   "abstracted gaze. The delirium was not fixed, however; having weaned her\n"
                   "eyes from contemplating the outer darkness, by degrees she centred her\n"
                   "attention on him, and discovered who it was that held her.";
    std::istringstream iss (test1);
    // 2. Process strings
    auto myVec = makeVecOfMyParagraph(iss);
    // 3. Pretty Print strings
    prettyPrint(myVec, 40);

    return 0;
}
