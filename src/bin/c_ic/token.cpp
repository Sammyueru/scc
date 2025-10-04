/* SCC: Classical intelligent C - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <iostream>
#include "token.h"

Token::Token() {

}

Token::Token(Token::Type type) {
    this->type = type;
}

Token::Token(Token::Type type, std::string value) {
    this->type = type;
    this->value = value;
}

Token::~Token() {

}
