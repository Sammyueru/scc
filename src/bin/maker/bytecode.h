/* SCC: Maker - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    typedef enum {
        jump = 0,
    } op;
    int16_t* in_types;
    int16_t out_type;
    void** inputs;
} instruction;

