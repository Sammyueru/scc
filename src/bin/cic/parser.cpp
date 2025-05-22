/* SCC: Classical intelligent C - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include "parser.h"

Parser::Parser(std::string source) {
    this->source = source;
}

Parser::~Parser() {
    
}

std::string Parser::Get_Pos_Data() {
    return "(line [" + std::to_string(this->line_num) + "], column [" + std::to_string(this->Get_Line_Column()) + "])";
}

std::string Parser::Get_Pos_Data(size_t tpos) {
    size_t line = 0;
    size_t col = 0;
    if (tpos >= this->source.length()) return "(line [ERROR], column [ERROR])";
    for (size_t i = 0; i < tpos; i++) {
        if (this->source.at(i) == '\n') {
            line++; col = 0;
            continue;
        }
        col++;
    }

    return "(line [" + std::to_string(line) + "], column [" + std::to_string(col) + "])";
}

size_t Parser::Get_Line_Column() {
    if (this->pos >= this->source.length()) return 0;
    size_t ipos = 0;
    for (ipos = this->pos; ipos > 0; ipos--) {
        if (this->source.at(ipos) == '\n') break;
    }

    return this->pos - ipos;
}

size_t Parser::Get_Line_Column(size_t tpos) {
    if (tpos >= this->source.length()) return 0;
    size_t ipos = 0;
    for (ipos = tpos; ipos > 0; ipos--) {
        if (this->source.at(ipos) == '\n') break;
    }

    return tpos - ipos;
}

char Parser::Peek(int amt) {
    if (-amt > this->pos) return '\0'; // if the peek location would technically be negative (if it was signed) return default
    size_t peek_at = this->pos + amt; // the location of the character to return
    if (peek_at > this->source.length() - 1) return '\0'; // if the peek location is greater than the size of the source file return default
    return this->source.at(peek_at); // successfully returns the character
}

std::vector<Token> Parser::Parse() {
    std::vector<Token> tokens;
    for (this->pos = 0; this->pos < this->source.length(); this->pos++) {
        char current = this->source.at(this->pos);

        // variable names and keywords
        if (current == '_' || (current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z')) {
            std::string word = "";
            for (size_t i = this->pos; i < this->source.length(); i++) {
                current = this->source.at(i);
                if (!(current == '_' || (current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z') || (current >= '0' && current <= '9'))) break;
                word.push_back(current);
                this->pos++;
            }

            if (std::find(this->keywords.begin(), this->keywords.end(), word) != this->keywords.end()) {
                tokens.push_back(Token(Token::Type::Keyword, word));
            }
            else {
                tokens.push_back(Token(Token::Type::Word, word));
            }

            continue;
        }

        switch (current) {
        // whitespace
        case ' ': case '\n': case '\t': case '\r': case '\f': case '\v': {
            std::string whitespace = "";
            for (size_t i = this->pos; i < this->source.length(); i++) {
                current = this->source.at(i);
                if (!isspace(current)) break;
                if (current == '\n') this->line_num++;
                whitespace.push_back(current);
                this->pos++;
            }

            tokens.push_back(Token(Token::Type::Whitespace, whitespace));
        } break;

        // separators
        case ';': case ',':
        case '(': case ')':
        case '{': case '}':
        case '[': case ']': {
            tokens.push_back(Token(Token::Type::Separator, std::string("" + current)));
        } break;

        // operators
        case ':':
        case '^':
        case '*': case '/':
        case '+': case '-':
        case '<': case '>':
        case '=': case '!':
        case '&': case '|': {
            char next = this->Peek(1);
            if (current == '/' && (next == '/' || next == '*')) {
                std::string comment = "";
                if (next == '/') {
                    for (size_t i = this->pos; i < source.length(); i++) {
                        current = source.at(i);
                        if (current == '\n') break;
                        comment.push_back(current);
                        this->pos++;
                    }
                }
                else {
                    comment += "/*";
                    this->pos += 2;
                    for (size_t i = this->pos; i < source.length(); i++) {
                        current = source.at(i);
                        if (current == '*') {
                            if (this->Peek(1) == '/') break;
                        }
                        comment.push_back(current);
                        this->pos++;
                    }
                    comment += "*/";
                    this->pos++;
                }
                tokens.push_back(Token(Token::Type::Comment, comment));
                break;
            }

            if (current == '*' && next == '*') {
                std::string op = "";
                for (size_t i = this->pos; i < this->source.length(); i++) {
                    current = this->source.at(i);
                    if (current != '*') break;
                    op += current;
                    this->pos++;
                }
                tokens.push_back(Token(Token::Type::Operator, op));
                break;
            }

            if (current == '-' && next == '>') {
                tokens.push_back(Token(Token::Type::Member_access, "->"));
                break;
            }

            std::string op = "" + current;
            if (next == '=' || next == current) {
                op.push_back(next);
                this->pos++;
            }
            tokens.push_back(Token(Token::Type::Operator, op));
        } break;

        // macros
        case '#': {
            std::string macro = "";
            for (size_t i = this->pos; i < this->source.length(); i++) {
                current = this->source.at(i);
                if (current == '\n') break;
                macro.push_back(current);
                this->pos++;
            }
            
            tokens.push_back(Token(Token::Type::Macro, macro));
        } break;

        // number literals
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.': {
            std::string literal = "";
            uint8_t exit = 0;
            size_t i = 0;

            if (current == '.') {
                char next = this->Peek(1);
                if (next == '_' || (next >= 'a' && next <= 'z') || (next >= 'A' && next <= 'Z')) {
                    tokens.push_back(Token(Token::Type::Member_access, "."));
                    break;
                }
            }

            for (i = this->pos; i < this->source.length(); i++) {
                if (exit > 0) {
                    break;
                }
                current = this->source.at(i);
                if (isdigit(current) || current == '.' || current == 'f' || current == 'd') {
                    literal.push_back(current);
                    continue;
                }

                switch (current) {
                case 'a': case 'A':
                case 'b': case 'B':
                case 'c': case 'C':
                case 'd': case 'D':
                case 'e': case 'E':
                case 'f': case 'F': {
                    literal.push_back(current);
                    continue;
                } break;

                case 'x': case 'X': {
                    if ((i != this->pos + 1) || this->Peek(-1) != '0') { exit = 2; continue; }
                    literal.push_back(current);
                } break;

                default: {
                    exit = 1;
                } break;
                }
            }

            this->pos = i - 1;

            if (exit > 1) { // exit > 1 means there is an error
                std::string error_print = "{SCC: Classical iC} Error: ";
                switch (exit) {
                    case 2: {
                        error_print += "hex literal must be formatted starting with `0x` followed by a hex number";
                    } break;
                    
                    default: {
                        error_print += "unknown parser error regarding a number literal";
                    } break;
                }
                error_print += ". " + this->Get_Pos_Data();
                std::cout << error_print << std::endl;
            }
        } break;

        // string & char literals
        case '"': case '\'': {
            char literal_sep = current;
            std::string literal = "" + current;
            for (this->pos++; this->pos < this->source.length(); this->pos++) {
                current = this->source.at(this->pos);
                literal += current;
                if (current == literal_sep && this->Peek(-1) != '\\') break; // if literal is terminated
            }
        } break;

        // unknown
        default: {
            std::cout << "{SCC: Classical iC} Error: unknown token `" << current << "`." << std::endl;
            tokens.push_back(Token(Token::Type::Unknown, std::string("" + current)));
        } break;
        }
    }

    return tokens;
}
