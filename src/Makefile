CC:=g++
COMP:=-fopenmp 
CFLAGS:=
LD:=g++
LOMP:=-fopenmp
LFLAGS:= 

EXECUTABLE ?= divergence

SOURCES = divergence.cpp output.cpp
OBJ_FILES = divergence.o output.o

$(EXECUTABLE) : $(SOURCES)
	$(CC) -c $(COMP) $(SOURCES) $(CFLAGS)
	$(LD) -o $(EXECUTABLE) $(LOMP) $(OBJ_FILES) $(LFLAGS)

clean :
	rm -rf $(OBJ_FILES) $(EXECUTABLE)
