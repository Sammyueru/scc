/* SCC: Libraries - Copyright (c) 2025 Samm, See LICENSE.txt for license details */
#ifndef SCC_LIB_BIO_GENE_H
#define SCC_LIB_BIO_GENE_H
#include <iostream>

namespace Bio {
    class Gene {
    public:
        std::string name;
        std::string* sequence;
    };
}

#endif
