OBJECTS = main.o tokenscanner.o
FLAGS = -g
BINARY = class_activity

build: $(OBJECTS)
	g++ $(FLAGS) $(OBJECTS) -o $(BINARY)

%.o: %.cpp
	g++ -c $^

run: $(BINARY)
	./$(BINARY)

clean:
	rm -f *.o $(BINARY)