OBJECTS = gpt.cpp
BINARY = gpt

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