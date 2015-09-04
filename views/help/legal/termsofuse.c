/* termsofuse.c */

#include "help.h"
#include "help/legal.h"
#include "help/legal/termsofuse.h"

char *cmd_help_legal_termsofuse( ) {

    char *buf = malloc( 50 );
    sprintf( buf, "this is the Terms of Use help page. hurrah. You are allowed to use this site. Good stuff!\n" );

    return buf;
}
