/* SCC: Sam's Pre-C (SPC) - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#ifndef SCC_SPC_TRANSPILER_H
#define SCC_SPC_TRANSPILER_H

#include "defines.h"
#include "scope.h"
#include "modules.h"
#include "header_gen.h"

typedef struct {
    /* Samm's Standard Version */
    uint32_t ssv_major; /* major */
    uint16_t ssv_minor; /* minor */

    /* C ISO */
    uint32_t c_iso;

    /* directories */
    char** src_dirs;
    size_t src_dirs_count;

    char** inc_dirs;
    size_t inc_dirs_count;

    char* output_dir;
} transpiler_settings;

#endif
