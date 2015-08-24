#ifndef __DB_H
#define __DB_H

typedef enum {
    DB_MYSQL,
    DB_SQLITE,
    DB_ORACLE,
    DB_POSTGRES
} db_driver;

typedef enum {
    DB_ACTIVE,
    DB_NONE,
    DB_CLOSED,
} db_status;

typedef struct _db_opts {

    db_driver driver;
    db_status status;

} db_opts;

#endif /* __DB_H */
