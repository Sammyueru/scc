/* SCC: Classical intelligent C - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#ifndef SCC_CIC_TOKEN_H
#define SCC_CIC_TOKEN_H
#include <iostream>

class Token {
public:
    enum class Type : int {
        Unknown = -1,
        Whitespace = 0,
        Operator = 1,
        Separator = 2,
        Literal = 3,
        Macro = 4,
        Keyword = 5,
        Member_access = 6,

/*
        Semicolon, // end of statement

        // brackets
        Parentheses,
        Bracket - square,
        Bracket - curly,

        // member access
        Dot, // (.). access members of a class or structure
        Arrow, // (->). access members of a pointer

        Pointer, // (*). pointer astrix

        Plus, // (+). addition
        Minus, // (-). subtraction
        Multiply, // (*). multiplication
        Divide, // (/). division

        Comma, // (,)

        // literals
        Integer, // (?, '?'). (number AND no decimal point) OR (type is specified manually AND is compatible)
        Float, // (?.?, ?.?f, ?). number AND ((has a decimal point MAY end with f) OR the type is specified manually)
        Double, // (?.?, ?.?d, ?). number AND ((has a decimal point AND ends with d) OR the type is specified manually)
        Char, // (?, '?'). char code number or single character wrapped inside of single quotes (')
        String/Character array, // ("???")
*/

        Comment = 256, // (//?, /*?*/). used for notes and will not affect the program build
    };

public:
    Type type;
    std::string value;

public:
    Token();
    Token(Type type);
    Token(Type type, std::string value);
    ~Token();
};

#endif
