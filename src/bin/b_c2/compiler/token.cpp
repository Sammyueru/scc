/* SCC: Biological C² - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <iostream>
#include "token.h"

Token::Token(Type type, std::string value) {
    this->type = type;
    this->value = value;
}

Token::~Token() {
    
}
