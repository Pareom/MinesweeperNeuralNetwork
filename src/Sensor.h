#ifndef DEF_SENSOR
#define DEF_SENSOR

#include <iostream>
#include <vector>

class Sensor
{
	public:

		Sensor(int i_idSensor, float i_angleOffset, float i_x2, float i_y2);

		int idSensor;
		float angleOffset;
		float x2;
		float y2;
		//float lengthSensor;
};

#endif