all:		main
	rm *.o
#	./bin/main
main:		main.o Graphic.o Car.o Sensor.o Line.o nNetwork.o layer.o
			g++ main.o Graphic.o Car.o Sensor.o Line.o nNetwork.o layer.o -o ./bin/main -lsfml-graphics -lsfml-window -lsfml-system

main.o:		./src/main.cpp ./src/Graphic.h ./src/nNetwork.h ./src/layer.h
			g++ -Wall -c ./src/main.cpp -o main.o

Graphic.o:	./src/Graphic.cpp ./src/Graphic.h ./src/Car.h ./src/Line.h
			g++ -Wall -c ./src/Graphic.cpp -o Graphic.o

Car.o:	./src/Car.cpp ./src/Car.h ./src/Sensor.h ./src/Line.h ./src/nNetwork.h
			g++ -Wall -c ./src/Car.cpp -o Car.o

Sensor.o:	./src/Sensor.cpp ./src/Sensor.h
			g++ -Wall -c ./src/Sensor.cpp -o Sensor.o

Line.o:	./src/Line.cpp ./src/Line.h
			g++ -Wall -c ./src/Line.cpp -o Line.o

nNetwork.o: ./src/nNetwork.cpp ./src/nNetwork.h ./src/layer.h
			g++ -Wall -c ./src/nNetwork.cpp -o nNetwork.o

layer.o: ./src/layer.cpp ./src/layer.h
			g++ -Wall -c ./src/layer.cpp -o layer.o

clean:
			rm *.o ./bin/main
