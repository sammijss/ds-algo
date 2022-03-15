# define compiler
COMPILER=g++

# define compiler flags
FLAGS=-std=c++11 -g -Wall

# define executable target
OBJECTS=Main.o\
    List.o\
    Operations.o

BINARY=List

all: clean $(BINARY)
    
List: $(OBJECTS) 
	$(COMPILER) $(FLAGS) $(OBJECTS) -o List

Main.o:
	$(COMPILER) -c $(FLAGS) Main.cpp

List.o:
	$(COMPILER) -c $(FLAGS) List.cpp

Operations.o:
	$(COMPILER) -c $(FLAGS) Operations.cpp

clean:
	rm -f $(BINARY) *.o

.PHONY: clean
