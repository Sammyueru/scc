/* SCC: Sam's Pre-C (SPC) - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#include <stdio.h>
#include "patterns.h"

int util_fs_pattern_match(fs_pattern_t* pattern, const char* input, int flags, int (*errfunc) (const char *epath, int eerrno)) {
#if defined(__linux__)
    return glob(input, flags, errfunc, (glob_t*)pattern);
#endif
}

void util_fs_pattern_free(fs_pattern_t* pattern) {
#if defined(__linux__)
    globfree((glob_t*)pattern);
#endif
}
