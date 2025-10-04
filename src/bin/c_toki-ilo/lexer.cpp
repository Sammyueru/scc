/* SCC: Classical toki ilo - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <unordered_map>
#include <functional>
#include "lexer.h"

static std::unordered_map<std::string, std::function<void(Lexer* lexer)>>* lex_operator_map = {
    { "li", [](Lexer* lexer){

    }},
    { "pi", [](Lexer* lexer){

    }},
};

Lexer::Lexer(std::string source) {
    this->source = source;
}

std::string Lexer::Lex() {

}
