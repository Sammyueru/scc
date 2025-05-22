/* SCC: Classical intelligent C - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <iostream>
#include <vector>
#include <string>
#include "astgen.h"

AST_Generator::AST_Generator(std::vector<std::tuple<std::string, std::vector<Token>>> sources, std::vector<std::string> defines) {
    this->sources = sources;
    this->defines = defines;
}

AST_Generator::~AST_Generator() {

}

Token AST_Generator::Peek(int amt) {
    if (-amt > this->pos) return Token(Token::Type::Unknown, "BF"); // if the peek location would technically be negative (if it was signed) return before file token
    size_t peek_at = this->pos + amt; // the location of the token to return
    if (peek_at > std::get<1>(this->sources.at(current_source)).size() - 1) return Token(Token::Type::Unknown, "EOF"); // if the peek location is greater than the size of the token vector return end of file token
    return std::get<1>(this->sources.at(current_source)).at(peek_at); // successfully returns the token
}

std::string AST_Generator::Get_Current_Source() {
    return std::get<0>(this->sources.at(current_source));
}

std::shared_ptr<AST::AST_Program> AST_Generator::Generate() {
    std::shared_ptr<AST::AST_Program> result = std::make_shared<AST::AST_Program>(new AST::AST_Program());
    std::vector<std::shared_ptr<AST::AST_Tree>> tree_stack = { std::make_shared<AST::AST_Tree>(result.get())};
    std::string err_b = "{SCC: Classical iC} Error: ";
    for (this->current_source = 0; this->current_source < this->sources.size(); this->current_source++) {
        std::tuple<std::string, std::vector<Token>> source = this->sources.at(current_source);
        std::string current_file = std::get<0>(source);
        std::vector<Token> tokens = std::get<1>(source);
        for (this->pos = 0; this->pos < tokens.size(); this->pos++) {
            Token current = tokens[this->pos];
            switch(current.type) {
            case Token::Type::Separator: {
                if (current.value.length() != 1) { std::cout << err_b << "separator token length not equal to 0. " << this->Get_Current_Source() << std::endl; break; }
                switch (current.value.at(0)) {
                case ':': {

                } break;

                case ';': {

                } break;

                case '(': {

                } break;

                case ')': {

                } break;

                case '{': {
                    AST::AST_Tree node();
                    tree_stack.back()->contents.push_back(std::make_shared<AST::AST_Node>(node));
                    tree_stack.push_back(std::make_shared<AST::AST_Tree>(node));
                } break;

                case '}': {
                    tree_stack.pop_back();
                } break;

                case '[': {

                } break;

                case ']': {

                } break;

                default: { std::cout << err_b << "separator string unknown `" << current.value << "`. " << this->Get_Current_Source() << std::endl; } break;
                }
            } break;

            case Token::Type::Word: {
                
            } break;

            case Token::Type::Macro: {
                size_t first_space = current.value.find_first_of(' ');
                if (first_space == std::string::npos) break;
                std::string macro_type = current.value.substr(0, first_space);
                std::string macro_cmd = current.value.substr(first_space + 1, current.value.size());
                // figure out what the macro does (and if it should be compiled into the program)
            } break;

            case Token::Type::Operator: {
                size_t value_len = current.value.length();
                if (value_len < 1) { std::cout << err_b << "operator token [value] length less than 1. " << this->Get_Current_Source() << std::endl; break; }

                char fchr = current.value.at(0);
                if (fchr == '*' || fchr == '&') {
                    uint8_t is_pointer_chr = 0;
                    if (value_len == 1) is_pointer_chr = 1;
                    else if (fchr == current.value.at(1)) is_pointer_chr = 1;
                    if (is_pointer_chr == 0) { std::cout << err_b << "misused operator combination `" << current.value << "`. " << this->Get_Current_Source() << std::endl; break; }

                    std::shared_ptr<AST::AST_Node> node = nullptr;
                    if (fchr == '*') {
                        node = std::make_shared<AST::AST_Node>(AST::AST_Deref());
                    }
                    else {
                        node = std::make_shared<AST::AST_Node>(AST::AST_Ref());
                    }

                    for (size_t i = 0; i < value_len; i++) {
                        
                    }
                }
            } break;

            case Token::Type::Whitespace: case Token::Type::Comment: break;
            case Token::Type::Unknown: default: { std::cout << err_b << "unknown token [type]. " << this->Get_Current_Source() << std::endl; } break;
            }
        }
    }

    return result;
}

