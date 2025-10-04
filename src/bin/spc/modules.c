/* SCC: Sam's Pre-C (SPC) - Copyright (c) 2025 Samm, See LICENSE.txt for license details */

/* modules are defined in the following manners:
 * 'module my_module { ... }'
 * 'module my_module ..;'
**/

/* modules are used (globally across a file) in the following manners:
 * 'using module.to.import @ "./path/to/file.h"',
 * 'using module.to.import @ <./path/to/file.h>',
 * 'using module.to.import @ .', or
 * 'using * @ "path/to/file.h"' (to use the entire file)
**/

/* to transpile make sure to define every component of the module with the compatible "convert_var_name" function */

