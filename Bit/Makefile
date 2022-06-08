# define compiler
COMPILER=g++

# define compiler flags
FLAGS=-std=c++11 -g -Wall

# define executable target
OBJECTS=Main.o\
        Bit.o

BINARY=Bit

all: clean $(BINARY)
    
Bit: $(OBJECTS) 
	$(COMPILER) $(FLAGS) $(OBJECTS) -o $(BINARY)

Main.o:
	$(COMPILER) -c $(FLAGS) Main.cpp

Bit.o:
	$(COMPILER) -c $(FLAGS) Bit.cpp

clean:
	rm -f $(BINARY) *.o

.PHONY: clean
