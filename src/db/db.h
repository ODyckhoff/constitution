#ifndef __CONSTITUTION_DB_H
#define __CONSTITUTION_DB_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mysql.h>

typedef enum {
    DB_MYSQL,
    DB_SQLITE,
    DB_ORACLE,
    DB_POSTGRES,
    DB_CUBRID,
    DB_MSSQL,
    DB_FIREBIRD,
    DB_IBM,
    DB_INFORMIX,
    DB_ODBC,
    DB_4D
} db_driver;

typedef enum {
    DB_ACTIVE,
    DB_NONE,
    DB_CLOSED
} db_status;

typedef enum {
    DB_QUERY,
    DB_CONN,
    DB_DCONN,
    DB_PREP, /* Preparing a query */
    DB_DATA, /* Pushing data to prepared query */
    DB_FETCHONE,
    DB_FETCHALL
} db_op;

typedef struct _row_t {
    struct _row_t *next;
    char **row;
} row_t;

typedef struct _db_opts {
    db_driver driver;
    db_status status;
    db_op operation;

    char *user;
    char *pass;
    char *host;
    char *dbname;

    void *data;
    void *conn;
    void *result;
    row_t *row;
    row_t *rows;
    int numrows;
    int numfields;

} db_opts;

db_opts *db_init( );
int db_free( db_opts *dbo );
int db_connect( db_opts *dbo );
int db_dconnect( db_opts *dbo );
int db_query( db_opts *dbo, char *query );
int db_getrows( db_opts *dbo );
void db_handler( db_opts *dbo );
void db_setdriver( db_opts *dbo, db_driver driver );
void db_setstatus( db_opts *dbo, db_status status );
void db_setop( db_opts *dbo, db_op op, void *data );
void db_setdbdata( db_opts *dbo, char *user, char *pass, char *host, char *dbname );

#endif /* __CONSTITUTION_DB_H */
