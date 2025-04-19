/* SCC: Biological C² - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <iostream>
#include <cstring>
#include <vector>

int main(int argc, char* argv[]) {
    std::vector<std::string> input_files; // input bio c2 files to be compiled

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
                            if (argv[i] == "2025") {
                                
                            }
                        }
                    } break;
                    case 'c': { // compile, don't link

                    } break;
                    case 'I': { // set include directory

                    } break;
                    case 'l': { // library

                    } break;
                    case 'o': { // output

                    } break;
                    case 'L': { // set library directory

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
