/* SCC: Classical intelligent C - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <iostream>
#include <vector>
#include <string>
#include "astgen.h"

AST_Generator::AST_Generator(std::vector<std::tuple<std::string, std::vector<Token>>> sources) {
    this->sources = sources;
}

AST_Generator::~AST_Generator() {

}

Token AST_Generator::Peek(int amt) {
    if (-amt > this->pos) return Token(Token::Type::Unknown, "BF"); ; // if the peek location would technically be negative (if it was signed) return default
    size_t peek_at = this->pos + amt; // the location of the character to return
    if (peek_at > std::get<1>(this->sources.at(current_source)).size() - 1) return Token(Token::Type::Unknown, "EOF"); // if the peek location is greater than the size of the source file return default
    return std::get<1>(this->sources.at(current_source)).at(peek_at); // successfully returns the character
}

std::shared_ptr<AST::AST_Program> AST_Generator::Generate() {
    std::shared_ptr<AST::AST_Program> result(new AST::AST_Program());
    for (this->current_source = 0; this->current_source < this->sources.size(); this->current_source++) {
        std::tuple<std::string, std::vector<Token>> source = this->sources.at(current_source);
        std::string current_file = std::get<0>(source);
        std::vector<Token> tokens = std::get<1>(source);
        std::vector<std::shared_ptr<AST::AST_Tree>> tree_stack(std::shared_ptr<AST::AST_Tree>(result));
        for (this->pos = 0; this->pos < tokens.size(); this->pos++) {
            Token current = tokens[this->pos];
            switch(current.type) {
            case Token::Type::Operator: {
                
            } break;

            case Token::Type::Macro: {
                size_t first_space = current.value.find_first_of(' ');
                if (first_space == std::string::npos) break;
                std::string macro_type = current.value.substr(0, first_space);
                std::string macro_cmd = current.value.substr(first_space + 1, current.value.size());
                // figure out what the macro does (and if it should be compiled into the program)
            } break;

            case Token::Type::Whitespace: case Token::Type::Comment: break;
            case Token::Type::Unknown: default: break;
            }
        }
    }

    return result;
}

