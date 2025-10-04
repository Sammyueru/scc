/* SCC: Sam's Pre-C (SPC) - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <string.h>

#include "transpiler.h"

int main(int argc, char* argv[]) {
    /* initialize */
    setlocale(LC_ALL, "en_US.UTF-8");

    transpiler_settings* settings = (transpiler_settings*)malloc(sizeof(transpiler_settings));
    if (settings == NULL) {
        return -1;
    }

    settings->src_dirs = (char**)malloc(sizeof(char*));
    if (settings->src_dirs == NULL) {
        free(settings);
        return -1;
    }

    settings->src_dirs[0] = NULL;
    settings->src_dirs_count = 0;

    settings->inc_dirs = (char**)malloc(sizeof(char*));
    if (settings->inc_dirs == NULL) {
        free(settings->src_dirs);
        free(settings);
        return -1;
    }

    settings->inc_dirs[0] = NULL;
    settings->inc_dirs_count = 0;

    settings->output_dir = NULL;

    /* parse arguments */
    for (int i = 0; i < argc; i++) {
        
    }

    /* transpile */
    transpile(settings);

    /* cleanup */

    for (size_t i = 0; i < settings->src_dirs_count; i++) {
        free(settings->src_dirs[i]);
    }

    free(settings->src_dirs);

    for (size_t i = 0; i < settings->inc_dirs_count; i++) {
        free(settings->inc_dirs[i]);
    }

    free(settings->inc_dirs);

    free(settings);

    /* exit */
    return 0;
}

