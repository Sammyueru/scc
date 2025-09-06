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

        PERIOD = 6,
        QUESTION = 7,
        COLON = 8,

        jo = 12, /* variables */
        li = 13, /* assignment */
        ilo = 14, /* tools */
        lawa = 15, /* rules */
        nanpa = 16, /* numbers */
        ala = 17, /* not, 0 */
        mute = 18, /* specify a quantity of an array */
        lili = 19,
        nasin = 20, /* create functions */
        o = 21, /* call functions (in combination with nasin) */
        nimi = 22, /* name functions and variables */
        ni = 23,
        mi = 24,
        sina = 25,
        kama = 26, /* events */
        ijo = 27, /* objects */
        kute = 28,
        lape = 29,
        ma = 30, /* namespaces? */
        pini = 31, /* task completed */
        pana = 32,
        pi = 33, /* access object or array elements */
        toki = 34, /* "toki sonpile tu { <C++ code> }" include C++ code, "toki sonpile { <C code> }" include C code */
        weka = 35,
        wile = 36, /* require */
        wawa = 37,
        lipu = 38, /* records */

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
