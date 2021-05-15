CC:=gcc
COMP:=-fopenmp 
CFLAGS:=
LD:=gcc
LOMP:=-fopenmp
LFLAGS:= 

EXECUTABLE := divergence

SOURCES = args.c clock.c experience.c divergence.c output.c
OBJ_FILES = args.o clock.o experience.o divergence.o output.o

$(EXECUTABLE) : $(SOURCES)
	$(CC) -c $(COMP) $(SOURCES) $(CFLAGS)
	$(LD) -o $(EXECUTABLE) $(LOMP) $(OBJ_FILES) $(LFLAGS)

clean :
	rm -rf $(OBJ_FILES) $(EXECUTABLE)
