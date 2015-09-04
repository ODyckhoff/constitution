CC=gcc
CFLAGS=-g -o index.cgi -I views/ -I src/ -I . -I/usr/include/mysql/
DFLAGS=-DVIEWPATH="\"views\""
LDFLAGS=-L/usr/lib64/mysql -lmysqlclient -lz
FILES=`find views/ -name "*.c" | xargs echo`
NUMVIEWS=`find views/ -name "*.h" | wc -l`

# target: all - Default target.
all: dispatch database
# target: help - Display callable targets.
help:
	@egrep "^# target:" [Mm]akefile

# target: dispatch - Builds components for dispatch.
dispatch:
	@printf "#ifndef __CNSTN_AUTO_DISPATCH\n" > src/_dispatch.h
	@printf "#define __CNSTN_AUTO_DISPATCH\n\n" >> src/_dispatch.h
	@printf "#include \"dispatch.h\"\n" >> src/_dispatch.h
	@printf "extern struct dispatch_table dispatcher[%d];\n" $(NUMVIEWS) >> src/_dispatch.h
	
	@find views/ -name "*.h" | sed 's/\(.*\)/#include "\1"/' >> src/_dispatch.h
	@printf "#endif\n" >> src/_dispatch.h
	
	@find views/ -name "*.h" | sed 's/views\/\(.*\)\.h/{ "\1", cmd_\1 },/' | awk '{ gsub( "/", "_", $$3 ); print }' > src/_tmp
	@printf "#include \"_dispatch.h\"\n" > src/_dispatch.c
	
	@printf "struct dispatch_table dispatcher[%d] = {\n" $(NUMVIEWS) >> src/_dispatch.c
	@cat src/_tmp | sed 's/^/    /' >> src/_dispatch.c
	@sed -i '$$s/,$$//' src/_dispatch.c
	@printf "};" >> src/_dispatch.c
	
	@rm src/_tmp
	
database: dispatch
	@$(CC) $(CFLAGS) $(DFLAGS) -DNUMVIEWS=$(NUMVIEWS) $(FILES) src/*.c src/db/*.c $(LDFLAGS)
