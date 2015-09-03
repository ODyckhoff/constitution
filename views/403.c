/* 403.c */

#include "403.h"

char *cmd_403( ) {
    char *buf;

    buf = malloc( 200 );
    sprintf( buf, "<h1>Error 403</h1>\n<hr />\n<p>The requested resource '%s' is forbidden.\n", 
                  getenv( "REDIRECT_BADURI" ) 
    );

    return buf;
}
