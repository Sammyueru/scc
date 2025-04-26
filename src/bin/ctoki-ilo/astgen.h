/* SCC: Classical toki ilo - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#ifndef SCC_CTOKI_IJO_ASTGEN_H
#define SCC_CTOKI_IJO_ASTGEN_H
#include <iostream>
#include <cstdint>
#include <vector>
#include <token.h>

class AST_Generator() {
private:
    /* std::vector<AST_Node*> stack;
    AST_Program* ast; */
    std::vector<std::vector<Token>> tokens;

public:
    AST_Generator(std::vector<std::vector<Token>> tokens);
    ~AST_Generator();

public:
    /* AST_Program Generate(); */
};

#endif
