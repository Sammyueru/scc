/* SCC: Classical toki ilo - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#ifndef SCC_CTOKI_IJO_PARSER_H
#define SCC_CTOKI_IJO_PARSER_H
#include <iostream>
#include <cstdint>
#include <vector>

class Parser {
private:
    std::string source;

public:
    Parser(std::string source);
    ~Parser();

public:
    std::vector<Token> Parse();
};

#endif
