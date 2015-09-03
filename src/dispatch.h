#ifndef __CONSTITUTION_DISPATCH_H
#define __CONSTITUTION_DISPATCH_H

    #include <dirent.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>

    #include "http.h"

    void dispatch( char *querystr, http_t *http );

    struct dispatch_table {
        char *name;
        char *( *function )( );
    };

#endif /* __CONSTITUTION_DISPATCH_H */

