/* main.c - Where constitution starts. */

#include <stdlib.h>
#include <stdio.h>

#include "http.h"
#include "response.h"
#include "_dispatch.h"

#include "globalopts.h"

int main( void ) {
    FILE *fp;
    
    long length;

    http_t *http = malloc( sizeof( http_t ) );
    http->data = NULL;

    dispatch( getenv( "QUERY_STRING" ), http );

    if( strcmp( http->data, "" ) != 0 ) {
        sendresponse( http );
    }

    return EXIT_SUCCESS;
}
