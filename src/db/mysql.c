#include <stdlib.h>
#include <stdio.h>

#include "db/db.h"
#include "db/mysql.h"

void mysql_handler( db_opts *dbo ) {

    switch( dbo->operation ) {
        case DB_CONN:
            db_mysqlconn( dbo );
        break;
    }
}

void db_mysqlconn( db_opts *dbo ) {

    MYSQL *conn = mysql_init( NULL );
    if( ! mysql_real_connect( 
              conn,
              dbo->host,
              dbo->user,
              dbo->pass,
              dbo->dbname,
              0, NULL, 0
          )
    ) {
        /* Error stuff, mysql_error( conn ); */
        fprintf( stderr, "Nope. Nada. Never. No. Negative. Nay. Niet. Nein. Oxi.\n" );
        return;
    }

    dbo->conn = conn;
}
