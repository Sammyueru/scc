/* SCC: Biological C² - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <iostream>

class Token {
public:
    enum class Type : int {
        Unknown = -1,
        Whitespace = 0,
        Operator = 1,
        Seperator = 2,
        Literal = 3,
        Identifier = 4,
        KEYWORD = 5,
        Comment = 6,
    };

public:
    Type type;
    std::string value;

public:
    Token(Type type, std::string value);
    ~Token();
};

