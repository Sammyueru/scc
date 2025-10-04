/* SCC: Sam's Pre-C (SPC) - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#ifndef SCC_SPC_MODULES_H
#define SCC_SPC_MODULES_H

typedef struct spc_module_tds {
    char* name;
    struct spc_module_tds* parent;
    struct spc_module_tds* children;
} spc_module;

#endif
