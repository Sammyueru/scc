/* SCC: Classical intelligent C - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
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

std::vector<std::shared_ptr<AST::AST_Node>> AST_Generator::Generate_Segment() {
    const std::string err_b = "{SCC: Classical iC} Error: ";
    std::vector<std::shared_ptr<AST::AST_Node>> result;
    Token current = this->tokens[this->pos];
    switch(current.type) {
    case Token::Type::Separator: {
        if (current.value.length() != 1) { std::cout << err_b << "separator token length not equal to 0. " << this->Get_Current_Source() << std::endl; break; }
        switch (current.value.at(0)) {
        case ':': {
            if (open_node != nullptr) {
                switch (prev_node->Get_Node_Type()) {
                case AST::NodeType::Case: case AST::NodeType::Default: {
                    std::shared_ptr<AST::AST_Shared_Tree> stree =  std::static_pointer_cast<AST::AST_Shared_Tree>(prev_node);
                    tree_stack.push_back(stree->tree);
                } break;
                
                default: { std::cout << err_b << "separator `:` misused. " << this->Get_Current_Source() << std::endl; } break;
                }
                break;
            }
            AST::AST_Tree* node = new AST::AST_Tree();
            tree_stack.back()->contents.push_back(std::make_shared<AST::AST_Node>(node));
            tree_stack.push_back(std::make_shared<AST::AST_Tree>(node));
        } break;

        case ';': {
            open_node = nullptr;
        } break;

        case '(': {
            if (open_node == nullptr) break;
            // generate another segment
        } break;

        case ')': {
            return result;
        } break;

        case '{': {
            if (open_node != nullptr) {
                switch (prev_node->Get_Node_Type()) {
                case AST::NodeType::Assignment: {

                } break;
                default: {

                } break;
                }
                break;
            }
            AST::AST_Tree* node = new AST::AST_Tree();
            tree_stack.back()->contents.push_back(std::make_shared<AST::AST_Node>(node));
            tree_stack.push_back(std::make_shared<AST::AST_Tree>(node));
            variable_stack.push_back(std::vector<std::shared_ptr<AST::AST_Variable>>());
        } break;

        case '}': {
            tree_stack.pop_back();
            variable_stack.pop_back();
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

    case Token::Type::Keyword: {
        const std::unordered_map<std::string, void(*)(void)> keywords = {
            { "if", []{
                
            }}, { "switch", []{
                
            }}, { "case", []{
            }}, { "default", []{
            }}, { "while", []{
            }}, { "for", []{
            }}, { "else", []{
            }}, { "break", []{
            }}, { "continue", []{
            }}, { "typedef", []{
            }}, { "struct", []{
            }}, { "class", []{
            }}, { "enum", []{
            }}, { "return", []{
            }}, { "this", []{
            }}, { "const", []{
            }}, { "unsigned", []{
            }}, { "volatile", []{
            }}, { "signed", []{
            }}, { "unsigned", []{
            }}, { "char", []{
            }}, { "short", []{
            }}, { "int", []{
            }}, { "long", []{
            }}, { "float", []{
            }}, { "double", []{
            }}, { "public", []{
            }}, { "private", []{
            }}, { "protected", []{
            }}, { "namespace", []{
            }}, { "using", []{
            }}, { "template", []{
            }}, { "goto", []{
            }},

            auto found = keywords.find(current.value);
            if (found == keywords.end()) {
                std::cout << err_b << "could not find keyword `" << current.value << "`. " << this->Get_Current_Source() << std::endl;
                break;
            }
        };
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
                node = std::make_shared<AST::AST_Node>(new AST::AST_Deref());
            }
            else {
                node = std::make_shared<AST::AST_Node>(new AST::AST_Ref());
            }

            for (size_t i = 0; i < value_len; i++) {
                
            }
        }
    } break;

    case Token::Type::Whitespace: case Token::Type::Comment: break;
    case Token::Type::Unknown: default: { std::cout << err_b << "unknown token [type]. " << this->Get_Current_Source() << std::endl; } break;
    }
    return result;
}

std::shared_ptr<AST::AST_Program> AST_Generator::Generate() {
    std::shared_ptr<AST::AST_Program> result = std::make_shared<AST::AST_Program>(new AST::AST_Program());
    tree_stack = { std::make_shared<AST::AST_Tree>(result.get())};
    prev_node = std::make_shared<AST::AST_Node>(result.get());
    open_node = nullptr;
    for (this->current_source = 0; this->current_source < this->sources.size(); this->current_source++) {
        std::tuple<std::string, std::vector<Token>> source = this->sources.at(current_source);
        tokens = std::get<1>(source);
        for (this->pos = 0; this->pos < tokens.size(); this->pos++) {
            this->Generate_Segment();
        }
    }

    return result;
}

