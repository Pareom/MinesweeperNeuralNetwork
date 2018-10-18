all:	testSFML clean
testSFML: ./src/testSFML.cpp
	g++ -c ./src/testSFML.cpp -o testSFML.o
	g++ testSFML.o -o ./bin/sfml-app -lsfml-graphics -lsfml-window -lsfml-system
clean:
	rm -f *.o
clear: clean
	rm -f ./bin/*
redo: clear all
