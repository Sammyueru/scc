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
        tjmp = 7, /* jump if true */
        fjmp = 8, /* jump if false */
        add =  9, /* add */
        sub = 10, /* subtract */
        mul = 11, /* multiply */
        div = 12, /* divide */
        exp = 13, /* exponent */
        cmp = 14, /* compare; [0] operator, [1] left, [2] right */
        sjmp = 15, /* stack jump (updates the stack pointer) */
        find_files = 16,
        and = 17,
        or = 18,
        xor = 19,
    } op;

    size_t inputs_counts;
/*  input/output types
    0.  void
    1.  int
    2.  str
    3.  str[]
    4.  bool
    5.  int[]
    6.  unsigned int
    7.  float
    8.  float[]
    9.  double
    10. double[]
    11. size
    12. long
    13. size[] */
    int16_t* in_types;
    int16_t out_type;
    void** inputs;
} instruction;

typedef struct {
    instruction* bc;
    size_t count;
} bc_token;

typedef struct {
    instruction** bc;
    size_t bc_count;
} bc_program;

bc_program* bc_compile(FILE* from);
void bc_free(bc_program* program);

int bc_run(bc_program* program);

#endif

