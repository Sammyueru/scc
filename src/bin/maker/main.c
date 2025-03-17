/* SCC: Maker - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char* command;
    for (int i = 1; i < argc; i++) {
        size_t arglen = strlen(argv[i]); /* length of argument currently being parsed */
        if (arglen < 1) {
            continue;
        }

        switch (argv[i][0]) {
        case '-': {
            if (arglen < 2) {
                printf("{SCC: Maker} ERROR: exiting due to missing parameter in argument.\n");
                return -1;
            }

            switch (argv[i][1]) {
            case 'f': {
                i++;
                if (i >= argc) {
                    printf("{SCC: Maker} ERROR: no maker file selected with `-f`");
                    return -1;
                }
            } break;
            case '-': {
            } break;
            default: {
                printf("{SCC: Maker} ERROR: unknown parameter `%s`.\n", argv[i]);
                return -1;
            } break;
            }
        } break;
        default: { /* argument is maker command */
            command = (char*)malloc(sizeof(argv[i]));
            command = *argv[i];
        } break;
        }
    }
    return 0;
}

