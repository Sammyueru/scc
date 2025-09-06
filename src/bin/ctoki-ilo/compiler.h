/* SCC: Classical toki ilo - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#ifndef SCC_CTOKI_ILO_COMPILER_H
#define SCC_CTOKI_ILO_COMPILER_H
#include <iostream>
#include <cstdint>
#include <vector>
#include <parser.h>

typedef struct compiler_settings_ts {
    unsigned int version; /* number of words */
/*  0. Hindu-Arabic base-10
    1. official toki pona numeral system
    2. roman toki pona numberal system
    3. modified roman toki pona numeral system */
    std::vector<uint16_t> number_systems;

    uint8_t link; // should link?
    uint8_t compile; // should compile?
    uint8_t warning_mode; // warning mode
    uint32_t flags;
    std::string output; // output file name
    std::vector<std::string> include_dirs; // include directories
    std::vector<std::string> libraries;
    std::vector<std::string> library_dirs; // library directories
} Compiler_Settings;

class Compiler() {
private:
    std::vector<Parser> parsers;
    Compiler_Settings settings;
public:
    Compiler(std::vector<std::string> source_file, Compiler_Settings settings);
    ~Compiler();
    
public:
    void Compile();
};

#endif
