/* index.c */

#include "index.h"
#include "db/db.h"
#include "dbopts.h"

char *cmd_index( ) {
    db_opts *dbo;
    char *buf;

    buf = malloc( 200 );
    sprintf( buf, "this is the index page. hurrah\n" );

    dbo = db_init( );

    db_setdriver( dbo, DRIVER );
    db_setdbdata( dbo, DBUSER, DBPASS, DBHOST, DBNAME );
    if( db_connect( dbo ) == EXIT_SUCCESS ) {
        strcat( buf, "Woop! Got a DB connection.\n" );
    }

    return buf;
}
