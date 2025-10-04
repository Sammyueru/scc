/* SCC: Sam's Pre-C (SPC) - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <string.h>
#include "defines.h"

char* convert_var_name(char* og_name) {
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

    char* new_name = (char*)malloc(new_len);
    
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

    return new_name;
}
