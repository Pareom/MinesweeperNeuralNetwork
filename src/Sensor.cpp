#include "Sensor.h"
#include <vector>
#include <iostream>

using namespace std;

Sensor::Sensor(int i_idSensor, float i_angleOffset, float i_x2, float i_y2) : idSensor(i_idSensor), angleOffset(i_angleOffset), x2(i_x2), y2(i_y2)
{
}
