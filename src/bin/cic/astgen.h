/* SCC: Classical intelligent C - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#ifndef SCC_CIC_ASTGEN_H
#define SCC_CIC_ASTGEN_H
#include <iostream>
#include <vector>
#include "token.h"

class AST_Generator {
private:
    std::vector<Token> tokens;

public:
    AST_Generator();
    ~AST_Generator();
}

#endif
