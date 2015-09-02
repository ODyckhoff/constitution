/* main.c - Where constitution starts. */

#include <stdlib.h>
#include <stdio.h>
#include "_dispatch.h"

#include "globalopts.h"

int main( void ) {

    dispatch( getenv( "QUERY_STRING" ) );

    return EXIT_SUCCESS;
}
