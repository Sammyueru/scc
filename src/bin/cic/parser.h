/* SCC: Classical intelligent C - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#ifndef SCC_CIC_PARSER_H
#define SCC_CIC_PARSER_H
#include <iostream>
#include <vector>
#include <string>
#include "token.h"
#include <cpp/ast/astnodes.h>

class Parser {
private:
    std::string source;
    size_t pos;

public:
    Parser();
    ~Parser();

private:
    char Peek(int amt);

public:
    std::vector<Token> Parse();
};

#endif
