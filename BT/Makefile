# define compiler
COMPILER=g++

# define compiler flags
FLAGS=-std=c++11 -g -Wall

# define executable target
OBJECTS=Main.o\
        BT.o\
        Traversal.o\
        View.o

BINARY=BT

all: clean $(BINARY)
    
BT: $(OBJECTS) 
	$(COMPILER) $(FLAGS) $(OBJECTS) -o $(BINARY) 

Main.o:
	$(COMPILER) -c $(FLAGS) Main.cpp

BT.o:
	$(COMPILER) -c $(FLAGS) BT.cpp

Traversal.o:
	$(COMPILER) -c $(FLAGS) Traversal.cpp

View.o:
	$(COMPILER) -c $(FLAGS) View.cpp

clean:
	rm -f $(BINARY) *.o

.PHONY: clean
