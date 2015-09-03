#include "_dispatch.h"
struct dispatch_table dispatcher[4] = {
    { "404", cmd_404 },
    { "help", cmd_help },
    { "403", cmd_403 },
    { "index", cmd_index }
};