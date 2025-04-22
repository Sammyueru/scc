/* SCC: Maker - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bytecode.h"

int main(int argc, char* argv[]) {
    char* command;
    FILE* makerfile;
    if (!(makerfile = fopen("makerfile", "r"))) {
        makerfile = NULL;
    }

    for (int i = 1; i < argc; i++) {
        size_t arglen = strlen(argv[i]); /* length of argument currently being parsed */
        if (arglen < 1) {
            continue;
        }

        switch (argv[i][0]) {
        case '-': {
            if (arglen < 2) {
                printf("{SCC: Maker} ERROR: missing parameter in argument.\n");
                return -1;
            }

            switch (argv[i][1]) {
            case 'f': {
                i++;
                if (i >= argc) {
                    printf("{SCC: Maker} ERROR: no maker file selected with `-f`.\n");
                    return -1;
                }

                if (!(makerfile = fopen(argv[i]))) {
                    printf("{SCC: Maker} ERROR: maker file `%s` does not exist.\n", argv[i]);
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
            strcpy(command, argv[i]);
        } break;
        }
    }

    if (makerfile == NULL) {
        printf("{SCC: Maker} ERROR: no valid makerfile.\n")
        return -1;
    }

    bc_program* program = bc_compile(makerfile);
    bc_run(program);
    bc_free(program);

    return 0;
}

