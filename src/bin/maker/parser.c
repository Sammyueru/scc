/* SCC: Maker - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include "parser.h"

bc_program* parser_parse_line(bc_program* program, char* line) {
    bc_program* result = (bc_program*)malloc(sizeof(bc_program));
    result->bc = (instruction**)malloc(sizeof(instruction*));
    result->bc_count = 0;

    uint8_t pos = 0;
    size_t current = 0;
    uint8_t done = 0;
    while (!done) {
        /* pre-initialize bytecode instruction */
        result->bc[current] = (instruction*)malloc(sizeof(instruction));
        result->bc[current]->op = nop;
        result->bc[current]->inputs_count = 0;
        result->bc[current]->in_types = NULL;
        result->bc[current]->out_type = 0;
        result->bc[current]->inputs = NULL;



        if (done || line[pos] == '\0') break;

        pos++;
        result->bc_count++;
        realloc(result->bc, result->bc_count * sizeof(instruction));
    }

    return result;
}

bc_token* parser_compiler_token() {
    bc_token result = (bc_token*)malloc(sizeof(bc_token));
    result->bc = (instruction*)malloc(sizeof(instruction));
    result->count = 0;

    return result;
}

