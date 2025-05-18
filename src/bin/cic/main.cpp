/* SCC: Classical intelligent C - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

int main(int argc, char* argv[]) {
    std::vector<std::string> input_files;
    Compiler_Settings settings;
    for (int i = 0; i < argc; i++) {
        size_t arglen = strlen(argv[i]);
        
        switch (argv[i][0]) {
        // argument is a parameter
        case '-': {
            if (arglen < 2) {
                std::cout << "{SCC: Classical iC} Error: no parameter in argument `-`." << std::endl;
                return -1;
            }

            switch (argv[i][1]) {
            case '-': {
                if (argv[i] == '--std') {
                    i++; if (i >= argc) break;

                    settings.version_minor = 0;
                    settings.version_state = 'f';
                    std::string standard(argv[i]);
                    std::string major = standard;
                    size_t standard_dot = major.find('.');
                    if (standard_dot != std::string::npos) {
                        major = major.substr(0, standard_dot);
                        std::string minor = standard.substr(standard_dot, standard.end());
                        if (!std::isdigit(minor.at(minor.size() - 1))) {
                            minor.pop_back();
                            settings.version_state = standard.back();
                        }
                        settings.version_minor = (uint16_t)std::stoi(minor);
                    }
                    else {
                        if (!std::isdigit(major.at(major.size() - 1))) {
                            major.pop_back();
                            settings.version_state = standard.back();
                        }
                    }

                    settings.version_major = (unsigned int)std::stoi(major);
                }
            } break;
            case 'I': {
                i++;
                if (i >= argc) break;

                settings.include_dirs.push_back(std::string(argv[i]));
            } break;
            default: break;
            }
        } break;

        // argument is an input file
        default: {
            input_files.push_back(std::string(argv[i]));
        } break;
        }
    }

    if (input_files.size() < 1) {
        std::cout << "{SCC: Classical iC} Error: no input sources supplied" << std::endl;
        return -1;
    }

    return 0;
}
