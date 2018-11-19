#ifndef DEF_CAR
#define DEF_CAR

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Sensor.h"
#include "Line.h"
#include "nNetwork.h"

class Car
{
	public:

		Car(int i_idCar, float i_posX, float i_posY, float i_rotZ, int R, int G, int B);
		Car(int i_idCar);
		void setPosSensor(int idSensor);
		void refreshPosSensor(int idSensor, Line wall); //retourne 1 si crash
		void refreshPosSensor(int idSensor, std::vector<Line> wallArray, int wallsNumber); //retourne 1 si crash
		std::vector<float> getLengthSensors();
		void moveCar();
		void setPosCar(float newposX, float newposY, float newrotZ);
		float getposX();
		float getposY();
		float getrotZ();
		int evalue();
		std::vector<Sensor> sensorArray;
		int colorR;
		int colorG;
		int colorB;
	  NNetwork brain;
		bool alive;
		int getTicks();
		int getIdCar();
	private:

		int idCar;
		float posX;
		float posY;
		float rotZ;
		float lengthSensor;
		int testCrash;
		int ticks;

};

#endif
