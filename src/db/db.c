/* db.c - Database Handler for the constitution framework. */

#include "globalopts.h"
#include "dbopts.h"

#include "err/err.h"

#include "db/db.h"
#include "db/mysql.h"
#include "db/sqlite.h"
#include "db/oracle.h"
#include "db/postgres.h"
#include "db/cubrid.h"
#include "db/mssql.h"
#include "db/firebird.h"
#include "db/ibm.h"
#include "db/informix.h"
#include "db/odbc.h"
#include "db/4d.h"

/* Core functions. */
db_opts *db_init( ) {
    /* Initialise a database object. */
    db_opts *dbo = malloc( sizeof( db_opts ) );

    if( dbo == NULL ) return EDBNULL;

    db_setstatus( dbo, DB_NONE );

    return dbo;
}

int db_free( db_opts *dbo ) {
    /* Free a database object */

    /* First free bits inside dbo... */
    free( dbo->user );
    free( dbo->pass );
    free( dbo->host );
    free( dbo->dbname );
    free( dbo );
    return EXIT_SUCCESS;
}

int db_connect( db_opts *dbo ) {
    if( dbo->status == DB_CLOSED ) return EDBCLOSED;

    if( dbo->user == NULL ) {
        if( FAIL_ON_NULL_USER ) {
            /* Some error stuff. */
            return 1;
        }
        dbo->user = malloc( 5 * sizeof( char ) );
        strcpy( dbo->user, "root\0" );
    }

    if( dbo->host == NULL ) {
        dbo->host = malloc( 10 * sizeof( char ) );
        strcpy( dbo->host, "localhost\0" );
    }

    db_setop( dbo, DB_CONN, NULL );
    db_handler( dbo );

    db_setstatus( dbo, DB_ACTIVE );

    return EXIT_SUCCESS; 
}

int db_dconnect( db_opts *dbo ) {
    if( ! ( dbo->status == DB_CLOSED || 
            dbo->status == DB_NONE ) ) {

        db_setop( dbo, DB_DCONN, NULL );
        db_handler( dbo );

        db_setstatus( dbo, DB_CLOSED );
    }

    return EXIT_SUCCESS;
}

int db_query( db_opts *dbo, char *query ) {

    if( query == NULL )
        return 1;
    if( dbo->status == DB_NONE )
        return 2;
    if( dbo->status == DB_CLOSED )
        return 3;

    db_setop( dbo, DB_QUERY, query );
    db_handler( dbo );
    return EXIT_SUCCESS;
}

int db_getrows( db_opts *dbo ) {
    db_setop( dbo, DB_FETCHALL, NULL );
    db_handler( dbo );
}

void db_handler( db_opts *dbo ) {

    switch( dbo->driver ) {
        case DB_MYSQL:
            /* MySQL Handler */
            mysql_handler( dbo );
        break;
        case DB_SQLITE:
            /* SQLite Handler */
        break;
        case DB_ORACLE:
            /* Oracle Handler */
        break;
        case DB_POSTGRES:
            /* PostGreSQL Handler */
        break;
        case DB_CUBRID:
            /* CUBRID Handler */
        break;
        case DB_MSSQL:
            /* MS SQL Handler */
        break;
        case DB_FIREBIRD:
            /* Firebird Handler */
        break;
        case DB_IBM:
            /* IBM Handler */
        break;
        case DB_INFORMIX:
            /* Informix Handler */
        break;
        case DB_ODBC:
            /* ODBC Handler */
        break;
        case DB_4D:
            /* 4D Handler */
        break;
    }
}

/* Helper functions. */
void db_setdriver( db_opts *dbo, db_driver driver ) {
    /* Set the driver for a database object. */
    dbo->driver = driver;
}

void db_setstatus( db_opts *dbo, db_status status ) {
    /* Set the database object status. Active, Closed, or None. */
    dbo->status = status;
}

void db_setop( db_opts *dbo, db_op op, void *data ) {
    /* Set the database object action. CONN, QUERY, DCONN */
    dbo->operation = op;
    if( dbo->operation == DB_QUERY && data == NULL ) {
        /* ENODATA or some such */
        return;
    }

    dbo->data = data;
}

void db_setdbdata( db_opts *dbo, 
                   char *user, char *pass, 
                   char *host, char *dbname ) {
    dbo->user   = user;
    dbo->pass   = pass;
    dbo->host   = host;
    dbo->dbname = dbname;
}
