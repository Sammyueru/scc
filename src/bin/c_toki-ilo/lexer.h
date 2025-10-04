/* SCC: Classical toki ilo - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#ifndef SCC_CTOKI_ILO_LEXER_H
#define SCC_CTOKI_ILO_LEXER_H
#include <iostream>
#include <cstdint>
#include <vector>

class Lexer {
public:
    std::string source;

    size_t pos;
    size_t pos_word;

public:
    Lexer(std::string source);
    ~Lexer();

public:
    std::string Lex();
};

#endif
