/* SCC: Maker - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#ifndef SCC_MAKER_PARSER_H
#define SCC_MAKER_PARSER_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "bytecode.h"

bc_program* parser_parse_line(bc_program* program, char* line);

#endif
