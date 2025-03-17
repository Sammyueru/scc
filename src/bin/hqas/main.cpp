/* SCC: Hardware Quantum Assembler - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <iostream>
#include <cstring>
#include <vector>
#include <libqasm/v3x/cqasm-python.hpp>

int main(int argc, char* argv[]) {
    std::vector<std::string> input_files; // input hardware quantum assembly to be compiled
    
    for (int i = 0; i < argc; i++) {
        size_t arglen = strlen(argv[i]); // the length of the argument currently being parsed
        if (arglen < 1) break;

        switch (argv[i][0]) {
        case '-': { // the argument is a parameter
            if (arglen < 2) {
                std::cout << "{SCC: HQAS} ERROR: exiting due to no parameter in argument." << std::endl;
                return -1;
            }
        } break;
        default: { // the argument is an input file
            input_files.push_back(std::string(argv[i]));
        } break;
        }
    }
main_end_argument_parser:

    return 0;
}

