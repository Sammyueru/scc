/* SCC: Classical intelligent C - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#ifndef SCC_CIC_COMPILER_H
#define SCC_CIC_COMPILER_H
#include <iostream>
#include <vector>
#include <cstdint>

class Compiler_Settings {
public:
    unsigned int version_major = 1;
    uint16_t version_minor = 0;
    /* version states:
       'a'. alpha
       'b'. beta
       'f'. final/release */
    char version_state = 'b';

    uint8_t compile = 0;
    uint8_t link = 0;
};

#endif
