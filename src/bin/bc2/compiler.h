/* SCC: Biological C² - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#ifndef SCC_BC2_COMPILER_H
#define SCC_BC2_COMPILER_H
#include <iostream>
#include <cstdint>
#include <vector>

typedef struct compile_settings_ts {
/*  base-10 fixed point notation; includes
    - year (all but last 3 digits),
    - standard set (next 2 digits),
      - S (00). SCC standard
    - year revision (last digit) */
    unsigned int version;

    uint8_t link; // should link?
    uint8_t compile; // should compile?
    uint8_t warning_mode; // warning mode
    uint32_t flags;
    std::string output; // output file name
    std::vector<std::string> include_dirs; // include directories
    std::vector<std::string> libraries;
    std::vector<std::string> library_dirs; // library directories
} compile_settings;

#endif
