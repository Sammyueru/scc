/* SCC: Classical intelligent C - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#ifndef SCC_CIC_COMPILER_H
#define SCC_CIC_COMPILER_H
#include <iostream>
#include <vector>
#include <cstdint>
#include "parser.h"

class Compiler_Settings {
public:
    unsigned int version_major = 1;
    uint16_t version_minor = 0;
    /* version states:
       'a'. alpha
       'b'. beta
       'f'. final/release */
    char version_state = 'b';

    uint8_t compile = 0;
    uint8_t link = 0;

    std::vector<std::string> include_dirs;
};

class Compiler {
private:
    Compiler_Settings settings;
    std::vector<std::string> input_files;
    std::vector<Parser> parsers;

public:
    Compiler(Compiler_Settings settings, std::vector<std::string> input_files);
    ~Compiler();

public:
    void Compile();
};

#endif
