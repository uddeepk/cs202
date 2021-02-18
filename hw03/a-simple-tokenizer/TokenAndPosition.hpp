//
// Created by uddeepk on 2/17/21.
//

#ifndef A_SIMPLE_TOKENIZER_TOKENANDPOSITION_HPP
#define A_SIMPLE_TOKENIZER_TOKENANDPOSITION_HPP

#include <string>
#include <vector>
#include <iostream>

struct TokenAndPosition {
    std::string _token;
    int _line;
    unsigned int _column;
};

std::vector <std::string> lineToTokens (const std::string &line);
std::vector <TokenAndPosition> readLines(std::istream &is);
void printTokens(std::ostream &os, const std::vector<TokenAndPosition> &tokens);


#endif //A_SIMPLE_TOKENIZER_TOKENANDPOSITION_HPP
