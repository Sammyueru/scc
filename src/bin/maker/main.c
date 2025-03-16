/* SCC: Maker - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    char* command;
    for (int i = 0; i < argc; i++) {
        switch (argv[i][0]) {
        case '-': {
        } break;
        default: {
            command = (char*)malloc(sizeof(argv[i]));
            command = *argv[i];
        } break;
        }
    }
    return 0;
}

