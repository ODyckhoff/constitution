/* index.c */

#include "index.h"
#include "db/db.h"
#include "dbopts.h"

void cmd_index() {
    db_opts *dbo;

    printf("this is the index page. hurrah\n");

    dbo = db_init( );

    db_setdriver( dbo, DRIVER );
    db_setdbdata( dbo, DBUSER, DBPASS, DBHOST, DBNAME );
    db_connect( dbo );

}
