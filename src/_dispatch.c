#include "_dispatch.h"
struct dispatch_table dispatcher[2] = {
    { "help", cmd_help },
    { "index", cmd_index }
};