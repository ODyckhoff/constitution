#ifndef __CONSTITUTION_ERR_H
#define __CONSTITUTION_ERR_H

typedef enum {

    /* Database Errors. */

    EDBNULL, /* DB instance not initialised. */
    EDBNOCONN, /* No DB connection exists. */
    EDBCLOSED, /* Attempt to query a closed DB connection. */

    /* URL errors */
    
    ENODATA, /* Empty query string */

} constitution_err;

#endif /* __CONSTITUTION_ERR_H */
