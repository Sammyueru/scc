/* SCC: Sam's Pre-C (SPC) - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#ifndef SCC_SPC_UTILS_FS_PATTERNS_H
#define SCC_SPC_UTILS_FS_PATTERNS_H

#if defined(__linux__)
#include <glob.h>

typedef struct {
    size_t pathc;
    char** pathv;
    size_t offset;
} fs_pattern_t;

#endif /* posix */

int util_fs_pattern_match(fs_pattern_t* pattern, const char* input, int flags, int (*errfunc) (const char *epath, int eerrno));
void util_fs_pattern_free(fs_pattern_t* pattern);

#endif
