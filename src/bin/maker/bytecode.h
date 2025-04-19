/* SCC: Maker - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#ifndef SCC_MAKER_BYTECODE_H
#define SCC_MAKER_BYTECODE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    enum {
        nop = 0, /* no operation */
        jmp = 1, /* jump to address in memory */
        store = 2, /* store value in variable */
        syscall = 3, /* run system software */
        print = 4, /* print as string */
        find_file = 5, /* find file by argument */
        wait = 6, /* wait milliseconds */
    } op;
    int16_t* in_types;
    int16_t out_type;
    void** inputs;
} instruction;

instruction** bc_compile(FILE* from);
void bc_free(instruction** bc);

#endif

