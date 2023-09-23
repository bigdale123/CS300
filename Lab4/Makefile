OBJECTS = lab4.o user.o deque.o
BINARY = lab4

build: $(OBJECTS)
	g++ -g $(OBJECTS) -o $(BINARY)

%.o: %.cpp
	g++ -c $^

run: $(BINARY)
	./$(BINARY)

clean:
	rm -f *.o $(BINARY)

.phony: db

db:
	gdb -tui $(BINARY)
