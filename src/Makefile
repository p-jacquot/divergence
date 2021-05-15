CC:=gcc
COMP:=-fopenmp 
CFLAGS:=
LD:=gcc
LOMP:=-fopenmp
LFLAGS:= 

EXECUTABLE := divergence

SOURCES = args.c divergence.c output.c
OBJ_FILES = args.o divergence.o output.o

$(EXECUTABLE) : $(SOURCES)
	$(CC) -c $(COMP) $(SOURCES) $(CFLAGS)
	$(LD) -o $(EXECUTABLE) $(LOMP) $(OBJ_FILES) $(LFLAGS)

clean :
	rm -rf $(OBJ_FILES) $(EXECUTABLE)
