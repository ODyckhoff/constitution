#ifndef __CONSTITUTION_DB_H
#define __CONSTITUTION_DB_H

typedef enum {
    DB_MYSQL,
    DB_SQLITE,
    DB_ORACLE,
    DB_POSTGRES
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
    DB_DATA  /* Pushing data to prepared query */
} db_op;

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

} db_opts;

#endif /* __CONSTITUTION_DB_H */
