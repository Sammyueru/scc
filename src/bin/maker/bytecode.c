/* SCC: Maker - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include "bytecode.h"

instruction** bc_compile(FILE* from) {
    instruction** bc = (instruction**)malloc(sizeof(instruction*) * 30);
    /* pre-initialize bytecode instructions */
    for (int i = 0; i < 30; i++) {
        bc[i] = (instruction*)malloc(sizeof(instruction));
        bc[i]->op = nop;
        bc[i]->inputs_count = 0;
        bc[i]->in_types = NULL;
        bc[i]->out_type = 0;
        bc[i]->inputs = NULL;
    }

    return bc;
}

void bc_free(instruction** bc) {
    for (size_t i = 0; i < (sizeof(bc)/sizeof(instruction*)); i++) {
        if (bc[i]->in_types) free(bc[i]->in_types); /* free inputs' types */

        /* free inputs' elements */
        if (bc[i]->inputs) {
            for (int ix = 0; ix < sizeof(bc[i]->inputs)/sizeof(void*); ix++) {
                free(bc[i]->inputs[ix]);
            }
        }
        free(bc[i]->inputs); /* free inputs array */
        free(bc[i]); /* free instruction element */
    }

    free(bc); /* free instruction array */
}

int bc_run(instruction** bc) {
    size_t bc_count = sizeof(bc)/sizeof(instruction*); /* number of bytecode instructions */
    size_t pos = 0;
    while (pos < bc_count) {
        size_t input_count = sizeof(bc[pos]->in_types)/sizeof(uint16_t);
        if (input_count != sizeof(bc[pos]->inputs)/sizeof(void*)) { /* in_types count != inputs count */
            printf("{SCC: Maker} ERROR: input types count not equal to inputs count.\n");
            return -1;
        }

        switch (bc[pos]->op) {
        case nop: {
            continue;
        } break;
        case jmp: {
            if (input_count != 1) {
                printf("{SCC: Maker} ERROR: 'jmp' instruction must have only 1 input.\n");
                return -1;
            }
            switch (bc[pos]->in_types[0]) {
            case 11: {
                size_t jump_to = bc[pos]->inputs[0];
                if (bc_count < jump_to) {
                    printf("{SCC: Maker} ERROR: 'jmp' instruction would go out of bounds.\n");
                    return -1;
                }
                pos = jump_to;
            } break;
            default: {
                printf("{SCC: Maker} ERROR: 'jmp' instruction given an invalid input type.\n");
                return -1;
            } break;
            }
            continue;
        } break;
        case sjmp: {

        } break;
        case wait: {
            if (input_count != 1) {
                printf("{SCC: Maker} ERROR: 'wait' instruction must have only 1 input.\n");
                return -1;
            }
        } break;
        default: {
            printf("{SCC: Maker} ERROR: interpreted instruction opcode unknown.\n");
            return -1;
        } break;
        }
        pos++;
    }
    return 1;
}
