/* help.c */

#include "help.h"

char *cmd_help( ) {

    char *buf = malloc( 50 );
    sprintf( buf, "this is the help page. hurrah\n" );

    return buf;
}
