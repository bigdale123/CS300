OBJECTS = wikiLadder.o main.o
BINARY = wikiLadder

build: $(OBJECTS)
	g++ $(OBJECTS) -lcurl -o $(BINARY)

%.o: %.cpp
	g++ -g -c $^

run: $(BINARY)
	./$(BINARY)

clean:
	rm -f *.o $(BINARY)

.phony: db

db:
	gdb -tui $(BINARY)