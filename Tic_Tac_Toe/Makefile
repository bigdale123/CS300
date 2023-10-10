OBJECTS = tictactoe.o
FLAGS = -g
BINARY = tictactoe

build: $(OBJECTS)
	g++ $(FLAGS) $(OBJECTS) -o $(BINARY)

%.o: %.cpp
	g++ -c $^

run: $(BINARY)
	./$(BINARY)

clean:
	rm -f *.o $(BINARY)