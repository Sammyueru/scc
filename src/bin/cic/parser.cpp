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
    
}

char Parser::Peek(int amt) {
    if (-amt > this->pos) return '\0';
    size_t peek_at = this->pos + amt;
    if (peek_at > this->source.length() - 1) return '\0';
    return this->source.at(peek_at);
}

std::vector<Token> Parser::Parse() {
    std::vector<Token> tokens;
    Token last_token(Token::Type::Unknown, std::string("NONE"));
    for (this->pos = 0; this->pos < this->source.length(); this->pos++) {
        char current = this->source.at(this->pos);
        switch (current) {
        // whitespace
        case ' ':
        case '\n':
        case '\t':
        case '\r':
        case '\f':
        case '\v': {
            std::string whitespace = "" + current;
            for (size_t i = pos + 1; i < this->source.length(); i++) {
                char check = this->source.at(i);
                if (!isspace(check)) break;
                whitespace.push_back(check);
                pos++;
            }

            tokens.push_back(Token(Token::Type::Whitespace, whitespace));
        } break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '>':
        case '<':
        case '&':
        case '|': {
            char next = this->Peek(1);
            if (current == '/' && (next == '/' || next == '*')) {
                std::string comment = "";
                if (next == '/') {
                    for (int i = pos; i < source.length(); i++) {
                        current = source.at(i);
                        if (current == '\n') break;
                        comment.push_back(current);
                        pos++;
                    }
                }
                else {
                    comment += "/*";
                    pos += 2;
                    for (int i = pos; i < source.length(); i++) {
                        current = source.at(i);
                        if (current == '*') {
                            if (this->Peek(1) == '/') break;
                        }
                        comment.push_back(current);
                        pos++;
                    }
                    comment += "*/";
                    pos++;
                }
                tokens.push_back(Token(Token::Type::Comment, comment));
                break;
            }

            if (current == '*' && next == '*') {
                std::string op = "";
                for (int i = this->pos; i < this->source.length(); i++) {
                    current = this->source.at(i);
                    if (current != '*') break;
                    op += current;
                    pos++;
                }
                tokens.push_back(Token(Token::Type::Operator, op));
                break;
            }

            std::string op = "" + current;
            if (next == '=' || next == current) {
                op.push_back(next);
                this->pos++;
            }
            tokens.push_back(Token(Token::Type::Operator, op));
        } break;
        // unknown
        default: {
            std::cout << "{SCC: Classical iC} Error: unknown token." << std::endl;
            tokens.push_back(Token(Token::Type::Unknown, std::string("" + current)));
        } break;
        }
        last_token = tokens.back();
    }

    return tokens;
}
