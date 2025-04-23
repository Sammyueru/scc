/* SCC: Maker - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include "bytecode.h"
#include "parser.h"

bc_program* bc_compile(FILE* from) {
    bc_program* program = (bc_program*)malloc(sizeof(bc_program));
    program->bc = (instruction**)malloc(sizeof(instruction*));
    /* pre-initialize bytecode instructions */
    program->bc[0] = (instruction*)malloc(sizeof(instruction));
    program->bc[0]->op = nop;
    program->bc[0]->inputs_count = 0;
    program->bc[0]->in_types = NULL;
    program->bc[0]->out_type = 0;
    program->bc[0]->inputs = NULL;

    /* parse file */
    char line[256];
    while (fgets(line, 255, from)) {
        line[255] = '\0';
        bc_program* prgm_line = parser_parse_line(program, line);
        program->bc_count += prgm_line->bc_count;
        program->bc = realloc(program->bc, program->bc_count * sizeof(instruction));

        /* move instructions to full program */
        for (size_t i = program->bc_count - prgm_line->bc_count; i < program->bc_count; i++) {
            *program->bc[i] = *prgm_line->bc[program->bc_count - i];
        }

        /* free line bytecode */
        bc_free(prgm_line);
    }

    return program;
}

void bc_free(bc_program* program) {
    for (size_t i = 0; i < (program->bc_count); i++) {
        if (program->bc[i]->in_types) free(program->bc[i]->in_types); /* free inputs' types */

        /* free inputs' elements */
        if (program->bc[i]->inputs) {
            for (int ix = 0; ix < program->bc_count; ix++) {
                free(program->bc[i]->inputs[ix]);
            }
        }

        free(program->bc[i]->inputs); /* free inputs array */
        free(program->bc[i]); /* free instruction element */
    }

    free(program->bc);
    free(program); /* free instruction array */
}

int bc_run(bc_program* program) {
    size_t pos = 0;
    while (pos < program->bc_count) {
        switch (program->bc[pos]->op) {
        case nop: {
            continue;
        } break;
        case jmp: {
            if (input_count != 1) {
                printf("{SCC: Maker} ERROR: 'jmp' instruction must have only 1 input.\n");
                return -1;
            }
            switch (program->bc[pos]->in_types[0]) {
            case 11: {
                size_t jump_to = program->bc[pos]->inputs[0];
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
