/* SCC: Classical intelligent C - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#ifndef SCC_CIC_PARSER_H
#define SCC_CIC_PARSER_H
#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include "token.h"
#include <cpp/ast/astnodes.h>

class Parser {
private:
    const std::vector<std::string> keywords = { "if", "switch", "case", "default", "while", "for", "else", "break", "continue", "typedef", "struct", "class", "return", "this", };

    std::string source;
    size_t pos;
    size_t line_num;

public:
    Parser(std::string source);
    ~Parser();

private:
    std::string Get_Pos_Data();
    std::string Get_Pos_Data(size_t tpos);

    size_t Get_Line_Column();
    size_t Get_Line_Column(size_t tpos);
    
    char Peek(int amt);

public:
    std::vector<Token> Parse();
};

#endif
