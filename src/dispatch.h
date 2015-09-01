#ifndef __CONSTITUTION_DISPATCH_H
#define __CONSTITUTION_DISPATCH_H

    #include <dirent.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>

    void dispatch( char *querystr );

    struct dispatch_table {
        char *name;
        void ( *function )();
    };

#endif /* __CONSTITUTION_DISPATCH_H */

