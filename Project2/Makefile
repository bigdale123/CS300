# Makefile for HelloWorld
#****************************************************************

PROGRAM = main
OBJECTS = main.o shape.o shapelist.o

ROOTPATH = cpplib
CPPOPTIONS = -I$(ROOTPATH)/include -fvisibility-inlines-hidden
LDOPTIONS = -L$(ROOTPATH)/lib -static-libstdc++
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAM) spl.jar

spl.jar:
	@ln -s $(ROOTPATH)/java/spl.jar

main: $(OBJECTS)
	g++ -o $(PROGRAM) $(LDOPTIONS) $(OBJECTS) $(LIB)

main.o: main.cpp shape.o shapelist.o Makefile
	g++ -c $(CPPOPTIONS) main.cpp

shape.o: shape.cpp Makefile
	g++ -c $(CPPOPTIONS) shape.cpp

shapelist.o: shapelist.cpp Makefile
	g++ -c $(CPPOPTIONS) shapelist.cpp

run: $(PROGRAM)
	./$(PROGRAM)

# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAM) $(OBJECTS) spl.jar
