/* SCC: Classical - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#ifndef SCC_CSHARE_CPP_AST_H
#define SCC_CSHARE_CPP_AST_H
#include <iostream>
#include <vector>
#include <memory>
#include "ast_types.h"

namespace AST {
class AST_Node {
private:
    NodeType ntype = NodeType::None;

public:
    NodeType Get_Node_Type();
};

class AST_Tree : AST_Node {
private:
    NodeType ntype = NodeType::Tree;

public:
    std::vector<std::shared_ptr<AST_Node>> contents;
};

class AST_Program : AST_Tree {
private:
    NodeType ntype = NodeType::Program;

public:
    std::shared_ptr<AST_Tree> entry;
};

class AST_Function : AST_Tree {
private:
    NodeType ntype = NodeType::Function;

public:
    std::string name;
    std::string type;
    std::vector<std::shared_ptr<::AST::AST_Node>> args;
};

class AST_Class : AST_Tree {
private:
    NodeType ntype = NodeType::Class;

public:
    std::string name;
    std::vector<std::shared_ptr<AST_Class>> extends;
};

class AST_Variable : AST_Node {
private:
    NodeType ntype = NodeType::Variable;
    
public:
    std::string name;
    std::string type;
};

class AST_Deref : AST_Variable {
private:
    NodeType ntype = NodeType::Deref;
public:
    int amount;
};

class AST_Ref : AST_Variable {
private:
    NodeType ntype = NodeType::Ref;
public:
    int amount;
};

class AST_Var_Op : AST_Node {
private:
    NodeType ntype = NodeType::Var_op;

public:
    std::shared_ptr<AST_Variable> var;
    std::string op;
    std::shared_ptr<AST_Node> right;
};

class AST_Operation : AST_Node {
private:
    NodeType ntype = NodeType::Op;

public:
    std::shared_ptr<AST_Node> left = nullptr;
    std::string op;
    std::shared_ptr<AST_Node> right = nullptr;
};

class AST_Assignment : AST_Node {
private:
    NodeType ntype = NodeType::Assignment;

public:
    std::shared_ptr<AST_Variable> var;
    std::string modifier;
    std::shared_ptr<AST_Node> value;
};

class AST_If : AST_Tree {
private:
    NodeType ntype = NodeType::If;

public:
    AST_Operation condition;
    std::vector<std::shared_ptr<AST_If>> _else_ifs;
    std::shared_ptr<::AST::AST_Node> _else;
};

class AST_Switch : AST_Tree {
private:
    NodeType ntype = NodeType::Switch;

public:
    std::shared_ptr<::AST::AST_Node> expression;
};

class AST_Shared_Tree : AST_Node {
private:
    NodeType ntype = NodeType::Shared_tree;

public:
    std::shared_ptr<AST_Tree> tree;
};

class AST_Case : AST_Shared_Tree {
private:
    NodeType ntype = NodeType::Case;

public:
    std::shared_ptr<AST::AST_Node> of; // "in the case of"
};

class AST_Default : AST_Shared_Tree {
private:
    NodeType ntype = NodeType::Default;
};

}

#endif
