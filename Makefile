CC=gcc
CFLAGS=-g -o cnstn_exec
LDFLAGS=
NUMVIEWS=`find views/ -name "*.h" | wc -l`

all:
	@printf "#ifndef __CNSTN_AUTO_DISPATCH\n#define __CNSTN_AUTO_DISPATCH\n\n#include \"dispatch.h\"\nextern struct dispatch_table dispatcher[%d];\n" $(NUMVIEWS) > src/_dispatch.h
	@find views/ -name "*.h" | sed 's/\(.*\)/#include "\1"/' >> src/_dispatch.h
	@printf "#endif\n" >> src/_dispatch.h
	@find views/ -name "*.h" | sed 's/views\/\(.*\)\.h/{ "\1", cmd_\1 },/' > src/_tmp
	@printf "#include \"_dispatch.h\"\nstruct dispatch_table dispatcher[%d] = {\n" $(NUMVIEWS) > src/_dispatch.c
	@cat src/_tmp | sed 's/^/    /' >> src/_dispatch.c
	@sed -i '$$s/,$$//' src/_dispatch.c
	@printf "};" >> src/_dispatch.c
	@$(CC) $(CFLAGS) -DVIEWPATH="\"views\"" -DNUMVIEWS=$(NUMVIEWS) -I . src/main.c src/dispatch.c src/_dispatch.c views/*.c
