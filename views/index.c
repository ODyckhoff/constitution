/* index.c */

#include "index.h"
#include "db/db.h"
#include "dbopts.h"

char *cmd_index( ) {
    db_opts *dbo;
    char *buf;
    char tmp[200];
    char *field;
    row_t *row;
    int count = 1;
    int i;

    buf = malloc( 100000 );
    sprintf( buf, "<h1>Index</h1>\nthis is the index page. hurrah<br />\n" );

    dbo = db_init( );

    db_setdriver( dbo, DRIVER );
    db_setdbdata( dbo, DBUSER, DBPASS, DBHOST, DBNAME );
    if( db_connect( dbo ) == EXIT_SUCCESS ) {
        strcat( buf, "Woop! Got a DB connection.<br />\n" );
    }

    if( db_query( dbo, "SELECT * FROM links;" ) == EXIT_SUCCESS ) {
        strcat( buf, "Query used is 'SHOW TABLES;'<br />\n<h2>Results</h2>\n" );
        db_getrows( dbo );
        row = dbo->rows;
        strcat( buf, "<pre>\n" );
        do {
            sprintf( tmp, "Row %d:\n", count );
            strcat( buf, tmp );
            for( i = 0; i < dbo->numfields; i++ ) {
                sprintf( tmp, "    Field %d (%s) = \"%s\",\n", i, dbo->fields[i], db_getfield( row, dbo->fields[i] ) );
                strcat( buf, tmp );
            }
            strcat( buf, "\n" );
            count++;
        } while( ( row = row->next ) != NULL );
        strcat( buf, "</pre>\n" );
    }
    else {
        strcat( buf, "Failed to execute query<br />\n" );
    }

    if( db_dconnect( dbo ) == EXIT_SUCCESS )
        strcat( buf, "Closed the DB connection.<br />\n" );

    strcat( buf, "<a href=\"./help\">Help Page.</a>" );

    return buf;
}
