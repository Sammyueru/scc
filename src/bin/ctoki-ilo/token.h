/* SCC: Classical toki ilo - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#ifndef SCC_CTOKI_ILO_TOKEN_H
#define SCC_CTOKI_ILO_TOKEN_H

class Token {
public:
    enum class Type : int {
        Unknown = -1,
        Whitespace = 0,
        Operator = 1,
        Separator = 2,
        Literal = 3,
        Macro = 4,

        Punctuation = 6,
        Colon = 8,

        jo = 12, /* variables */
        li = 13, /* assignment */
        ilo = 14, /* tools */
        lawa = 15, /* rules */
        nanpa = 16, /* numbers and reference counted pointers */
        ala = 17, /* not, 0 */
        mute = 18, /* specify a quantity of an array */
        lili = 19,
        nasin = 20, /* create functions */
        o = 21, /* call functions (in combination with nasin) */
        nimi = 22, /* name functions and variables */
        ni = 23, /* self or block creation with ".. ni:" */
        mi = 24, /* program output like "toki mi '<string>' e sina" to print a string */
        sina = 25, /* program input like "toki sina '<string>' e mi" to get user input string */
        kama = 26, /* events */
        ijo = 27, /* objects and dynamic/changing type */
        kute = 28,
        lape = 29,
        ma = 30, /* location labels and namespaces with "ma tomo <name>" */
        pini = 31, /* task completed/end block */
        pana = 32, /* return */
        pi = 33, /* access object or array elements */
        toki = 34, /* "toki sonpile tu { <C++ code> }" include C++ code, "toki sonpile { <C code> }" include C code */
        weka = 35, /* subtraction */
        wile = 36, /* require */
        wawa = 37,
        lipu = 38, /* records */
        tawa = 39, /* go to label's location */
        la = 40, /* conditionals */
        anu = 41, /* conditional else */
        lon = 42, /* memory access/pointers */
        sin = 43, /* create new instance */
        tenpo = 44, /* scheduling */
        pali = 45, /* create variable with "<variable name> [li <variable type>] li pali e <value>" and create macros/rules */
        e = 46,
        en = 47, /* addition and 'and' */

        Comment = 255,
    };

public:
    Type type;
    std::string value;

public:
    Token();
    ~Token();
};

#endif
