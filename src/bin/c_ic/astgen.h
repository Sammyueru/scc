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
    std::vector<Token> tokens;
    std::vector<std::vector<std::shared_ptr<AST::AST_Variable>>> variable_stack;
    std::vector<std::shared_ptr<AST::AST_Tree>> tree_stack;
    std::shared_ptr<AST::AST_Node> prev_node;
    std::shared_ptr<AST::AST_Node>* open_node;
    size_t current_source;
    size_t pos;

public:
    AST_Generator(std::vector<std::tuple<std::string, std::vector<Token>>> sources, std::vector<std::string> defines);
    ~AST_Generator();

private:
    Token Peek(int amt = 1);
    Token PeekNW(int amt = 1); // peek no whitespace or comments
    std::string Get_Current_Source();
    std::vector<std::shared_ptr<AST::AST_Node>> Generate_Segment();

public:
    std::shared_ptr<AST::AST_Program> Generate();
};

#endif
