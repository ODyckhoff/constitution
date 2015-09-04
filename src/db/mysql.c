#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "db/db.h"
#include "db/mysql.h"

void mysql_handler( db_opts *dbo ) {

    switch( dbo->operation ) {
        case DB_CONN:
            db_mysqlconn( dbo );
        break;

        case DB_DCONN:
            db_mysqlclose( dbo );
        break;

        case DB_QUERY:
            db_mysqlquery( dbo );
        break;

        case DB_FETCHONE:
            db_mysqlgetrow( dbo );
        break;

        case DB_FETCHALL:
            db_mysqlgetall( dbo );
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

void db_mysqlclose( db_opts *dbo ) {

    if( dbo->result != NULL )
        mysql_free_result( dbo->result );
    
    if( dbo->conn != NULL )
        mysql_close( dbo->conn );
}

void db_mysqlquery( db_opts *dbo ) {

    MYSQL_RES *res;

    if( mysql_query( dbo->conn, dbo->data ) ) {
        fprintf( stderr, "%s\n", mysql_error( dbo->conn ) );
        return;
    }

    res = mysql_use_result( dbo->conn );
    dbo->result = res;
}

void db_mysqlgetrow( db_opts *dbo ) {
    MYSQL_ROW tmp;
    row_t *row = malloc( sizeof( row ) );

    if( ( tmp = mysql_fetch_row( dbo->result ) ) != NULL ) {
        row->row = db_mysqlrowtostr( dbo, &tmp );
        dbo->numfields = mysql_num_fields( dbo->result );
    }
    if( dbo->row != NULL )
        free( dbo->row );
    dbo->row = row;
    
}

void db_mysqlgetall( db_opts *dbo ) {
    MYSQL_ROW tmp;
    int numrows = 1;
    row_t *root = malloc( sizeof( row_t ) );
    row_t *rtmp;

    if( root != NULL ) {
        tmp = mysql_fetch_row( dbo->result );
        root->row = db_mysqlrowtostr( dbo, &tmp );
    }
    else {
        dbo->numrows = 0;
        return;
    }

    rtmp = root;

    while( ( tmp = mysql_fetch_row( dbo->result ) )  != NULL ) {
        rtmp->next = malloc( sizeof( row_t ) );

        rtmp = rtmp->next;
        rtmp->row = db_mysqlrowtostr( dbo, &tmp );
        numrows++;
    }

    rtmp->next = NULL;

    dbo->rows = root;
    dbo->numrows = numrows;
    dbo->numfields = mysql_num_fields( dbo->result );
}

char **db_mysqlrowtostr( db_opts *dbo, MYSQL_ROW *row ) {
    MYSQL_ROW tmp = *row;
    int i;
    int num = mysql_num_fields( dbo->result );
    char **strrow = malloc( num * sizeof( char * ) );

    for( i = 0; i < num; i++ ) {
        strrow[i] = malloc( strlen( ( char * ) tmp[i] ) );
        sprintf( strrow[i], "%s", tmp[i] );
    }

    return strrow;
}
