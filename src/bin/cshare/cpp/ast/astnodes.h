/* SCC: Classical - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#ifndef SCC_CSHARE_CPP_AST_H
#define SCC_CSHARE_CPP_AST_H
#include <iostream>
#include <vector>
#include <memory>

namespace AST {
class AST_Node {};

class AST_Tree : AST_Node {
public:
    std::vector<std::shared_ptr<AST_Node>> contents;
};

class AST_Program : AST_Tree {};

class AST_Variable : AST_Node {
public:
    std::string name;
    std::string type;
};

class AST_Var_Op : AST_Node {
public:
    std::shared_ptr<AST_Variable> var;
    std::string op;
    std::shared_ptr<AST_Node> right;
};

class AST_Operation : AST_Node {
public:
    std::shared_ptr<AST_Node> left = nullptr;
    std::string op;
    std::shared_ptr<AST_Node> right = nullptr;
};

class AST_Assignment : AST_Node {
public:
    std::shared_ptr<AST_Variable> var;
    std::string modifier;
    std::shared_ptr<AST_Node> value;
};

class AST_If : AST_Tree {
public:
    AST_Operation condition;
    std::vector<std::shared_ptr<AST_If>> _else_ifs;
    std::shared_ptr<::AST::AST_Node> _else;
};
}

#endif
