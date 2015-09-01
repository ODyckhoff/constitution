#ifndef __CONSTITUTION_CFG_H
#define __CONSTITUTION_CFG_H

typedef struct _cfg_opts {

    int debugmode;

    char *basedir;
    char *logdir;
    char *logfrmt; /* How to name the log file(s). */

} cfg_opts;

#endif /* __CONSTITUTION_CFG_H */
