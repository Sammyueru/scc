/* SCC: Classical intelligent C - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <iostream>
#include <vector>
#include "astgen.h"

AST_Generator::AST_Generator(std::vector<std::tuple<std::string, std::vector<Token>>> sources) {
    this->sources = sources;
}

AST_Generator::~AST_Generator() {

}

std::shared_ptr<AST_Program> AST_Generator::Generate() {
    std::shared_ptr<AST_Program> result(new AST_Program());
    return result;
}

