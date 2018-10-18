all:	main clean
	./bin/main
testSFML: ./src/testSFML.cpp
	g++ -c ./src/testSFML.cpp -o testSFML.o
	g++ testSFML.o -o ./bin/sfml-app -lsfml-graphics -lsfml-window -lsfml-system
main: main.o layer.o nNetwork.o
	g++ main.o layer.o nNetwork.o -o ./bin/main
main.o: ./src/main.cpp ./src/layer.h ./src/nNetwork.h
	g++ -Wall -c ./src/main.cpp -o main.o
layer.o: ./src/layer.cpp ./src/layer.h
	g++ -Wall -c ./src/layer.cpp -o layer.o
nNetwork.o: ./src/nNetwork.cpp ./src/layer.h ./src/nNetwork.h
	g++ -Wall -c ./src/nNetwork.cpp -o nNetwork.o
clean:
	rm -f *.o
clear: clean
	rm -f ./bin/*
redo: clear all
