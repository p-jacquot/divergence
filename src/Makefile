CC:=g++
COMP:=-fopenmp 
CFLAGS:=
LD:=g++
LOMP:=-fopenmp
LFLAGS:= 

EXECUTABLE ?= divergence

SOURCES = args.cpp divergence.cpp output.cpp
OBJ_FILES = args.o divergence.o output.o

$(EXECUTABLE) : $(SOURCES)
	$(CC) -c $(COMP) $(SOURCES) $(CFLAGS)
	$(LD) -o $(EXECUTABLE) $(LOMP) $(OBJ_FILES) $(LFLAGS)

clean :
	rm -rf $(OBJ_FILES) $(EXECUTABLE)
