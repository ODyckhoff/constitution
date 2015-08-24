/* db.c - Database Handler for the constitution framework. */

#include "db/db.h"
#include "err/err.h"

#include "db/mysql.h"
#include "db/sqlite.h"
#include "db/oracle.h"
#include "db/postgres.h"

/* Core functions. */
int db_init( db_opts *dbo ) {
    /* Initialise a database object. */
    if( dbo == NULL ) return EDBNULL;

    db_setstatus( dbo, DB_NONE );
    return EXIT_SUCCESS;
}

int db_free( db_opts *dbo ) {
    /* Free a database object */
    
    return EXIT_SUCCESS;
}

int db_connect( db_opts *dbo ) {
    if( dbo->status == DB_NONE   ) return EDBNOCONN;
    if( dbo->status == DB_CLOSED ) return EDBCLOSED;

    return EXIT_SUCCESS; 
}

void db_handler( db_opts *dbo ) {

    switch( dbo->driver ) {
        case DB_MYSQL:
            /* MySQL Handler */
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


