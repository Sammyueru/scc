/* SCC: Sam's Pre-C (SPC) - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <stdio.h>
#include <string.h>
#include "transpiler.h"
#include "defines.h"
#include "utils/fs/patterns.h"

char* convert_var_name(char* og_name) {
    if (!og_name) return NULL;

    uint16_t og_len = strnlen(og_name, BOUND_16ui);
    size_t new_len = og_len;
    for (uint16_t i = 0; i < og_len; i++) {
        char chr = og_name[i];
        switch (chr) {
        case '_': {
            new_len++;
        } break;
        case '.': {
            new_len += 2;
        } break;
        case '*': {

        } break;
        default: break;
        }
    }

    char* new_name = (char*)malloc(new_len + 1);
    if (new_name == NULL) return new_name;
    
    {
        size_t new_current = 0;
        for (uint16_t i = 0; i < og_len; i++) {
            switch (og_name[i]) {
            case '_': {
                new_name[new_current] = '_';

                new_current++;
                new_name[new_current] = '_';
            } break;
            case '.': {
                new_name[new_current] = '_';

                new_current++;
                new_name[new_current] = 'd';

                new_current++;
                new_name[new_current] = '_';
            } break;
            default: {
                new_name[new_current] = og_name[i];
            } break;
            }
            new_current++;
        }
    }

    new_name[new_len + 1] = '\0';
    return new_name;
}

uint16_t transpile(transpiler_settings* settings) {
    char** source_files = NULL;
    size_t source_files_count = 0;
    for (size_t i = 0; i < settings->src_dirs_count; i++) {
        fs_pattern_t fpattern = (fs_pattern_t)0;
        size_t pinput_len = strnlen(settings->src_dirs[i], BOUND_16ui - 2) + 2;
        char* pinput = (char*)malloc(pinput_len);
        if (pinput == NULL) return 1;
        memcpy(pinput, settings->src_dirs[i], pinput_len - 2);
        pinput[pinput_len - 1] = '\0';
        pinput[pinput_len - 2] = '*';

        util_fs_pattern_match(&pattern, pinput, 0, NULL, NULL);
        free(pinput);

        util_fs_pattern_free(&pattern);
    }
    
    return 0; /* success */
}
