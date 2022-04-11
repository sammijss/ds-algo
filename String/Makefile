# define compiler
COMPILER=g++

# define compiler flags
FLAGS=-std=c++11 -g -Wall

# define executable target
OBJECTS=Main.o\
        String.o

BINARY=String

all: clean $(BINARY)
    
String: $(OBJECTS) 
	$(COMPILER) $(FLAGS) $(OBJECTS) -o $(BINARY)

Main.o:
	$(COMPILER) -c $(FLAGS) Main.cpp

String.o:
	$(COMPILER) -c $(FLAGS) String.cpp

clean:
	rm -f $(BINARY) *.o

.PHONY: clean
