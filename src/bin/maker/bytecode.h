/* SCC: Maker - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#ifndef SCC_MAKER_BYTECODE_H
#define SCC_MAKER_BYTECODE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    typedef enum {
        nop = 0, /* no operation */
        jmp = 1, /* jump to address in memory */
        store = 2, /* store value in variable */
    } op;
    int16_t* in_types;
    int16_t out_type;
    void** inputs;
} instruction;

#endif

