/* SCC: Classical intelligent C - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <iostream>
#include "compiler.h"

Compiler::Compiler(Compiler_Settings settings, std::vector<std::string> input_files) {
    this->settings = settings;
    this->input_files = input_files;
}

Compiler::~Compiler() {

}

void Compiler::Compile() {

}

