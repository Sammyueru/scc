/* SCC: Biological C² - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#ifndef SCC_BC2_PARSER_H
#define SCC_BC2_PARSER_H
#include <iostream>
#include <cstdint>
#include <vector>
#include <compiler/token.h>

class Parser {
public:
    std::string source;
    int pos;

public:
    Parser(std::string source);
    ~Parser();

public:
    std::vector<Token> Parse();
};

#endif
