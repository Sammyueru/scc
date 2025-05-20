/* SCC: Classical intelligent C - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
#include "parser.h"

Parser::Parser(std::string source) {
    this->source = source;
}

Parser::~Parser() {
    delete this->tokens;
}

char Parser::Peek(int amt) {
    if (-amt > pos) return '\0';
    size_t peek_at = pos + amt;
    if (peek_at > source.length() - 1) return '\0';
    return source.at(peek_at);
}

std::vector<Token> Parser::Parse() {
    Token last_token(Token::Type::Unknown, std::string("NONE"));
    for (this->pos = 0; this->pos < this->source.length(); this->pos++) {
        char current = source.at(this->pos);
        switch (current) {
        // whitespace
        case ' ':
        case '\n':
        case '\t':
        case '\r':
        case '\f':
        case '\v': {
            std::string whitespace(current);
            for (size_t i = pos + 1; i < source.length(); i++) {
                char check = source.at(i);
                if (!isspace(check)) break;
                whitespace.push_back(check);
                pos++;
            }

            this->tokens->push_back(Token::Type::Whitespace, whitespace);
        } break;
        // unknown
        default: {
            std::cout << "{SCC: Classical iC} Error: unknown token." << std::endl;
            this->tokens->push_back(Token::Type::Unknown, std::string(current));
        } break;
        }
    }

    return *this->tokens;
}
