all:	main clean
	./bin/main
testSFML: ./src/testSFML.cpp
	g++ -c ./src/testSFML.cpp -o testSFML.o
	g++ testSFML.o -o ./bin/sfml-app -lsfml-graphics -lsfml-window -lsfml-system

main:		main.o Graphic.o Car.o Sensor.o Line.o layer.o nNetwork.o
			g++ main.o layer.o nNetwork.o Graphic.o Car.o Sensor.o Line.o -o ./bin/main -lsfml-graphics -lsfml-window -lsfml-system
main.o:		./src/main.cpp ./src/Graphic.h
			g++ -Wall -c ./src/main.cpp -o main.o


Graphic.o:	./src/Graphic.cpp ./src/Graphic.h ./src/Car.h ./src/Line.h
			g++ -Wall -c ./src/Graphic.cpp

Car.o:	./src/Car.cpp ./src/Car.h ./src/Sensor.h ./src/Line.h
			g++ -Wall -c ./src/Car.cpp

Sensor.o:	./src/Sensor.cpp ./src/Sensor.h
			g++ -Wall -c ./src/Sensor.cpp

Line.o:	./src/Line.cpp ./src/Line.h
			g++ -Wall -c ./src/Line.cpp


layer.o: ./src/layer.cpp ./src/layer.h
	g++ -Wall -c ./src/layer.cpp -o layer.o
nNetwork.o: ./src/nNetwork.cpp ./src/layer.h ./src/nNetwork.h
	g++ -Wall -c ./src/nNetwork.cpp -o nNetwork.o


clean:
	rm -f *.o
clear: clean
	rm -f ./bin/*
redo: clear all
