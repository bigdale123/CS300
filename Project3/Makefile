OBJECTS = pirate.o roman.o main.o
BINARY = stack

build: $(OBJECTS)
	g++ $(OBJECTS) -o $(BINARY)

%.o: %.cpp
	g++ -g -c $^

run: $(BINARY)
	./$(BINARY)

clean:
	rm -f *.o $(BINARY)

.phony: db

db:
	gdb -tui $(BINARY)