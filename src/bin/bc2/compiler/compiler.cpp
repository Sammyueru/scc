/* SCC: Biological C² - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <iostream>
#include <fstream>
#include <sstream>
#include "compiler.h"

Compiler::Compiler(std::vector<std::string> source_files, Compiler_Settings settings) {
    for (std::string source_file : source_files) {
        std::ifstream source;
        source.open(source_file, std::ios::in);
        if (!source.is_open()) continue;
        std::stringstream source_buffer;
        source_buffer << source.rdbuf;
        Parser parser(source_buffer.str());
        source.close();
        parsers.push_back(parser);
    }
}

Compiler::~Compiler() {

}

void Compiler::Compile() {
    std::vector<std::vector<Token>> tokens;
    for (Parser parser : parsers) {
        tokens.push_back(parser.Parse());
    }
}

