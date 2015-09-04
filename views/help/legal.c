/* legal.c */

#include "help.h"
#include "help/legal.h"

char *cmd_help_legal( ) {

    char *buf = malloc( 50 );
    sprintf( buf, "this is the legal help page. hurrah. All rights reserved.\n" );

    return buf;
}
