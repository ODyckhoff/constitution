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
    row_t *row;

    if( ( tmp = mysql_fetch_row( dbo->result ) ) != NULL ) {
        row = db_mysqlrowtostr( dbo, &tmp );
        dbo->numfields = mysql_num_fields( dbo->result );
    }
    if( dbo->row != NULL )
        free( dbo->row );
    dbo->row = row;
    
}

void db_mysqlgetall( db_opts *dbo ) {
    MYSQL_ROW tmp;
    int numrows = 1;
    row_t *root;
    row_t *dummy;

    tmp = mysql_fetch_row( dbo->result );
    dummy = db_mysqlrowtostr( dbo, &tmp );

    root = dummy;

    while( ( tmp = mysql_fetch_row( dbo->result ) )  != NULL ) {
        dummy->next = db_mysqlrowtostr( dbo, &tmp );
        dummy = dummy->next;
        dummy->next = NULL;
        numrows++;
    }

    dbo->rows = root;
    dbo->numrows = numrows;
    dbo->numfields = mysql_num_fields( dbo->result );
}

row_t *db_mysqlrowtostr( db_opts *dbo, MYSQL_ROW *row ) {
    MYSQL_ROW tmp = *row;
    MYSQL_FIELD *field;
    hashmap_t *hmap = inithmap( 1 );
    row_t *outrow;
    int i;
    int num = mysql_num_fields( dbo->result );
    outrow = malloc( sizeof( row_t ) );
    outrow->next = NULL;

    if( ! dbo->fields ) {
        dbo->fields = calloc( num, sizeof( char * ) );
    }

    for( i = 0; i < num; i++ ) {
        field = mysql_fetch_field( dbo->result );
        if( ! dbo->fields[i] ) {
            dbo->fields[i] = malloc( strlen( field->name ) + 1 );
            strcpy( dbo->fields[i], field->name );
        }
        puthmap( hmap, dbo->fields[i], tmp[i] );
    }
    outrow->row = hmap;

    return outrow;
}
