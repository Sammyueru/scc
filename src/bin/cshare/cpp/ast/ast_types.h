/* SCC: Classical - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#ifndef SCC_CSHARE_CPP_AST_TYPES_H
#define SCC_CSHARE_CPP_AST_TYPES_H
#include <iostream>

namespace AST {
enum class NodeType : unsigned int {
    None = 0,
    Tree = 1,
    Program = 2,
    Function = 3,
    Class = 4,
    Variable = 5,
    Deref = 6,
    Ref = 7,
    Var_op = 8,
    Op = 9,
    Assignment = 10,
    If = 11,
    Switch = 12,
    Shared_tree = 13,
    Case = 14,
    Default = 15,
};
}

#endif
