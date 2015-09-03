/* 404.c */

#include "404.h"

char *cmd_404( ) {
    char *buf;

    buf = malloc( 200 );
    sprintf( buf, "<h1>Error 404</h1>\n<hr />\n<p>The requested page '%s' could not be found.\n", 
                  getenv( "QUERY_STRING" ) 
    );

    return buf;
}
