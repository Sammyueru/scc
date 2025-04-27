/* SCC: Biological C² - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <iostream>
#include <ctype>
#include "parser.h"

Parser::Parser(std::string source) {
    this->source = source;
}

Parser::~Parser() {
    
}

std::vector<Token> Parser::Parse() {
    std::vector<Token> result;
    for (pos = 0; pos < source.length(); pos++) {
        while (source.at(pos) != isspace && pos < sourece.length()) {
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
                case '}': 
                case ';': {
                    result.push_back(Token(Token::Type::Seperator, source.at(pos)));
                } break;
                default: {
                    if (isdigit(source.at(pos))) {
                        std::string number = source.at(pos);
                        while (pos < source.length()) {
                            pos++;
                            if (isdigit(source.at(pos)) || source.at(pos) == '.') {
                                number += source.at(pos);
                                continue;
                            }
                            break;
                        }
                        if (source.at(pos) == 'f') {
                            number += 'f';
                        }
                        else { pos--; }
                        result.push_back(Token(Token::Type::Literal), number);
                    }
                    else {
                        std::string name = "";
                        while (pos < source.length()) {
                            char chr = source.at(pos);
                            if ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z') || chr == '_' || isdigit(chr)) {
                                name += source.at(pos);
                                pos++;
                                continue;
                            }
                            break;
                        }
                        pos--;
                        if (name == "") { break; }
                        else if (name == "when" || name == "if" || name == "else" || name == "while" || name == "class" || name == "for" || name == "switch") {
                            result.push_back(Token(Token::Type::Keyword), name);
                        }
                        else {
                            result.push_back(Token(Token::Type::Identifier), name);
                        }
                    }
                } break;
            }
        }
    }
}

