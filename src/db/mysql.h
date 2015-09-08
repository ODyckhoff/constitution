#ifndef __CONSTITUTION_DB_MYSQL_H
#define __CONSTITUTION_DB_MYSQL_H

#include <mysql.h>

#include "db/db.h"

void mysql_handler( db_opts *dbo );
void db_mysqlconn( db_opts *dbo );
void db_mysqlclose( db_opts *dbo );
void db_mysqlquery( db_opts *dbo );
void db_mysqlgetrow( db_opts *dbo );
void db_mysqlgetall( db_opts *dbo );
row_t *db_mysqlrowtostr( db_opts *dbo, MYSQL_ROW *row );

#endif /* __CONSTITUTION_DB_MYSQL_H */
