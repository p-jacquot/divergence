CC:=g++
COMP:=-fopenmp 
LD:=g++
LOMP:=-fopenmp
FLAGS:= 

EXECUTABLE ?= divergence

SOURCES = divergence.cpp output.cpp
OBJ_FILES = divergence.o output.o

$(EXECUTABLE) : $(SOURCES)
	$(CC) -c $(COMP) $(SOURCES) $(FLAGS)
	$(LD) -o $(EXECUTABLE) $(LOMP) $(OBJ_FILES)

clean :
	rm -rf $(OBJ_FILES) $(EXECUTABLE)
