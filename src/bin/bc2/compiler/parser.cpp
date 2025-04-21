/* SCC: Biological C² - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <iostream>
#include "parser.h"

Parser::Parser(std::string source) {
    this->source = source;
}

Parser::~Parser() {
    
}

std::vector<Token> Parser::Parse() {
    std::vector<Token> result;
    for (pos = 0; pos < source.length(); pos++) {
        while (source.at(pos) != isspace) {
            switch (source.at(pos)) {
                case '=':
                case '+':
                case '-':
                case '*':
                case '/':
                case '&':
                case '|':
                case '>':
                case '<': {
                    result.push_back(Token(Token::Type::Operator, source.at(pos)));
                } break;
                case '(':
                case ')':
                case '{':
                case '}': {
                    result.push_back(Token(Token::Type::Seperator, source.at(pos)));
                } break;
                default: {

                } break;
            }
        }
    }
}

