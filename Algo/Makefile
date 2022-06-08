# define compiler
COMPILER=g++

# define compiler flags
FLAGS=-std=c++11 -g -Wall

# define executable target
OBJECTS=Main.o\
        Algo.o

BINARY=Algo

all: clean $(BINARY)
    
Algo: $(OBJECTS) 
	$(COMPILER) $(FLAGS) $(OBJECTS) -o $(BINARY)

Main.o:
	$(COMPILER) -c $(FLAGS) Main.cpp

Algo.o:
	$(COMPILER) -c $(FLAGS) Algo.cpp

clean:
	rm -f $(BINARY) *.o

.PHONY: clean
