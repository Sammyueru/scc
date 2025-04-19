/* SCC: Maker - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include "bytecode.h"

instruction** bc_compile(FILE* from) {
    instruction** bc = (instruction**)malloc(sizeof(instruction*) * 30);
    /* pre-initialize bytecode instructions */
    for (int i = 0; i < 30; i++) {
        bc[i] = (instruction*)malloc(sizeof(instruction));
    }

    return bc;
}

void bc_free(instruction** bc) {
    for (int i = 0; i < (sizeof(bc)/sizeof(instruction*)); i++) {
        free(bc[i]->in_types); /* free inputs' types */

        /* free inputs' elements */
        for (int ix = 0; ix < sizeof(bc[i]->inputs)/sizeof(void*); ix++) {
            free(bc[i]->inputs[ix]);
        }
        free(bc[i]->inputs); /* free inputs array */
        free (bc[i]); /* free instruction element */
    }

    free(bc); /* free instruction array */
}

