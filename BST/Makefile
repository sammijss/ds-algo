# define compiler
COMPILER=g++

# define compiler flags
FLAGS=-std=c++11 -g -Wall

# define executable target
OBJECTS=Main.o\
        BST.o

BINARY=BST

all: clean $(BINARY)
    
BST: $(OBJECTS) 
	$(COMPILER) $(FLAGS) $(OBJECTS) -o $(BINARY) 

Main.o:
	$(COMPILER) -c $(FLAGS) Main.cpp

BST.o:
	$(COMPILER) -c $(FLAGS) BST.cpp

clean:
	rm -f $(BINARY) *.o

.PHONY: clean
