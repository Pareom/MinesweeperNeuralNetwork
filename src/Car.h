#ifndef DEF_CAR
#define DEF_CAR

#include <iostream>
#include <vector>
#include "Sensor.h"
#include "Line.h"
#include "nNetwork.h"

class Car
{
	public:

		Car(int i_idCar, float i_posX, float i_posY, float i_rotZ);
		Car(int i_idCar);
		void setPosSensor(int idSensor);
		int refreshPosSensor(int idSensor, Line wall); //retourne 1 si crash
		int refreshPosSensor(int idSensor, std::vector<Line> wallArray, int wallsNumber); //retourne 1 si crash
		//std::vector<float>
		void setPosCar(float newposX, float newposY, float newrotZ);
		float getposX();
		float getposY();
		float getrotZ();

		std::vector<Sensor> sensorArray;

	private:

		int idCar;
		float posX;
		float posY;
		float rotZ;
		float lengthSensor;
		int testCrash;
		NNetwork brain;

};

#endif
