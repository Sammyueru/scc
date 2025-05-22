/* SCC: Classical intelligent C - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#ifndef SCC_CIC_ASTGEN_H
#define SCC_CIC_ASTGEN_H
#include <iostream>
#include <vector>
#include <tuple>
#include "token.h"
#include <cpp/ast/astnodes.h>

class AST_Generator {
private:
    std::vector<std::tuple<std::string, std::vector<Token>>> sources;
    std::vector<std::string> defines;
    size_t current_source;
    size_t pos;

public:
    AST_Generator(std::vector<std::tuple<std::string, std::vector<Token>>> sources, std::vector<std::string> defines);
    ~AST_Generator();

private:
    Token Peek(int amt = 1);
    std::string Get_Current_Source();

public:
    std::shared_ptr<AST::AST_Program> Generate();
};

#endif
