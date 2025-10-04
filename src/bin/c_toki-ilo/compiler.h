/* SCC: Classical toki ilo - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#ifndef SCC_CTOKI_ILO_COMPILER_H
#define SCC_CTOKI_ILO_COMPILER_H
#include <iostream>
#include <cstdint>
#include <vector>
#include <lexer.h>
#include <parser.h>

typedef struct compiler_settings_ts {
    unsigned int version; /* number of words */
/*  0. Hindu-Arabic base-10 (enabled by default)
    1. official toki pona numeral system (enabled by default)
    2. roman toki pona numberal system
    3. modified roman toki pona numeral system
    4. nasin nanpa pona numeral system (enabled by default) */
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
    std::vector<Lexer> lexers;
    std::vector<Parser> parsers;
    Compiler_Settings settings;
public:
    Compiler(std::vector<std::string> source_files, Compiler_Settings settings);
    ~Compiler();
    
public:
    void Compile();
};

#endif
