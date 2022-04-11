# define compiler
COMPILER=g++

# define compiler flags
FLAGS=-std=c++11 -g -Wall

# define executable target
OBJECTS=Main.o\
        Find.o

BINARY=Array

all: clean $(BINARY)
    
Array: $(OBJECTS) 
	$(COMPILER) $(FLAGS) $(OBJECTS) -o $(BINARY)

Main.o:
	$(COMPILER) -c $(FLAGS) Main.cpp

Find.o:
	$(COMPILER) -c $(FLAGS) Find.cpp

clean:
	rm -f $(BINARY) *.o

.PHONY: clean
