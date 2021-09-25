CC = g++
C_FLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic
OBJECTS = FibLFSR.o PhotoMagic.o
DEPS = FibLFSR.h
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
EXE = PhotoMagic

all: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXE) $(LIBS)
%.o: %.cpp $(DEPS)
	$(CC) $(C_FLAGS) -o $@ $<
clean:
	rm $(OBJECTS) $(EXE)
