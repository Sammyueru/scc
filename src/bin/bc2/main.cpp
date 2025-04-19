/* SCC: Biological C² - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <iostream>
#include <cstdint>
#include <cstring>
#include <vector>

typedef struct compile_settings_ts {
 /* base-10 fixed point notation; includes
    - year (all but last 3 digits),
    - standard set (next 2 digits),
      - S (00). SCC standard
    - year revision (last digit) */
    unsigned int version;

    uint8_t link; // should link?
    uint8_t compile; // should compile?
    std::string output; // output file name
    std::vector<std::string> include_dirs; // include directories
    std::vector<std::string> libraries;
    std::vector<std::string> library_dirs; // library directories
} compile_settings;

int main(int argc, char* argv[]) {
    std::vector<std::string> input_files; // input bio c2 files to be compiled
    compile_settings settings = {0};
    settings.version = 2025000;

    for (int i = 0; i < argc; i++) {
        size_t arglen = strlen(argv[i]); // the length of the argument currently being parsed

        switch (argv[i][0]) {
            case '-': { // the argument is a paremeter
                if (arglen < 2) {
                    std::cout << "{SCC: Bio C²} ERROR: exiting due to no parameter in argument." << std::endl;
                    return -1;
                }

                switch (argv[i][1]) {
                    case '-': {
                        if (argv[i] == "--std") {
                            i++;
                            if (argc < i) break;
                            if (argv[i] == "2025" || argv[i] == "2025S0") {
                                settings.version = 2025000;
                            }
                        }
                    } break;
                    case 'c': { // compile, don't link
                        settings.compile = 1;
                        settings.link = 0;
                    } break;
                    case 'I': { // set include directory
                        if (arglen < 3) { std::cout << "{SCC: Bio C²} WARNING: include directory not specified" << std::endl; break; }
                        settings.include_dirs.push_back(std::string(argv[i]).substr(2));
                    } break;
                    case 'l': { // library
                        if (arglen < 3) { std::cout << "{SCC: Bio C²} WARNING: library name not specified" << std::endl; break; }
                        settings.libraries.push_back(std::string(argv[i]).substr(2));
                    } break;
                    case 'o': { // output
                        if (!settings.compile) {
                            settings.compile = 1;
                            settings.link = 1;
                        }

                        i++;
                        if (argc < i) break;
                        settings.output = std::string(argv[i]);
                    } break;
                    case 'L': { // set library directory
                        if (arglen < 3) { std::cout << "{SCC: Bio C²} WARNING: library directory not specified" << std::endl; break; }
                        settings.library_dirs.push_back(std::string(argv[i]).substr(2));
                    } break;
                    default: break;
                }
            } break;
            default: { // the argument is an input file
                input_files.push_back(std::string(argv[i]));
            } break;
        }
    }



    return 0;
}
