#include "Car.h"
#include "Sensor.h"
#include "Line.h"
#include "nNetwork.h"
#include <vector>
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

using namespace std;

#define PI 3.14159265359

Car::Car(int i_idCar, float i_posX, float i_posY, float i_rotZ, int R, int G, int B) : colorR(R), colorG(G), colorB(B), brain(std::vector<int>(2,1)), alive(true), idCar(i_idCar),posX(i_posX), posY(i_posY), rotZ(i_rotZ)
{
	lengthSensor=100;
	testCrash=0;

	//préparation cerveau
	vector<int> layerSize;
	layerSize.push_back(5);
	layerSize.push_back(16);
	layerSize.push_back(2);
	brain = NNetwork(layerSize);
	//
	for(int i=0; i<5; i++)
	{
		sensorArray.push_back(Sensor(i,-(PI/2)+i*(PI/4),0,0));
		Car::setPosSensor(i);
	}
}

Car::Car(int i_idCar) : colorR(255), colorG(0), colorB(0), brain(std::vector<int>(2,1)), alive(true), idCar(i_idCar), posX(100), posY(100), rotZ(90)
{
	lengthSensor=100;
	testCrash=0;
	//préparation cerveau
	vector<int> layerSize;
	layerSize.push_back(5);
	layerSize.push_back(16);
	layerSize.push_back(2);
	brain = NNetwork(layerSize);
	//
	for(int i=0; i<5; i++)
	{
		sensorArray.push_back(Sensor(i,-(PI/2)+i*(PI/4),0,0));
		Car::setPosSensor(i);
	}
}

void Car::setPosSensor(int idSensor)
{
	sensorArray[idSensor].x2 = lengthSensor*cos(rotZ+sensorArray[idSensor].angleOffset)+posX;
	sensorArray[idSensor].y2 = lengthSensor*sin(rotZ+sensorArray[idSensor].angleOffset)+posY;
}

void Car::refreshPosSensor(int idSensor, Line wall)
{
	Car::setPosSensor(idSensor);

	float scalarProduct = ((wall.posY2-wall.posY1)*(sensorArray[idSensor].x2-this->posX)) - ((wall.posX2-wall.posX1)*(sensorArray[idSensor].y2-this->posY)) ;
	float prop1, prop2;
	if(scalarProduct!=0)
	{
		prop1 = ((this->posY-wall.posY1)*(wall.posX2-wall.posX1)+(wall.posX1-this->posX)*(wall.posY2-wall.posY1))/scalarProduct;
		prop2 = ((this->posY-wall.posY1)*(sensorArray[idSensor].x2-this->posX)+(wall.posX1-this->posX)*(sensorArray[idSensor].y2-this->posY))/scalarProduct;

		if((prop1 < 1 && prop1 >= 0) && (prop2 < 1 && prop2 >= 0))
		{
			sensorArray[idSensor].x2 = (sensorArray[idSensor].x2-this->posX)*prop1 + this->posX;
			sensorArray[idSensor].y2 = (sensorArray[idSensor].y2-this->posY)*prop1 + this->posY;

			if(prop1 < 0.05) //test Crash voiture
			{
				alive=false;
			}
		}
	}
}

void Car::refreshPosSensor(int idSensor, vector<Line> wallArray, int wallsNumber) //retourne 1 si crash
{
	Car::setPosSensor(idSensor);

	vector<float> prop1;
	vector<float> prop2;
	vector<float> scalarProduct;
	int testCollision(0);
	float prop1Min(1);

	for(int i=0; i<wallsNumber; i++)
	{
		scalarProduct.push_back(((wallArray[i].posY2-wallArray[i].posY1)*(sensorArray[idSensor].x2-this->posX)) - ((wallArray[i].posX2-wallArray[i].posX1)*(sensorArray[idSensor].y2-this->posY)));
		if(scalarProduct[i]!=0)
		{
			prop1.push_back(((this->posY-wallArray[i].posY1)*(wallArray[i].posX2-wallArray[i].posX1)+(wallArray[i].posX1-this->posX)*(wallArray[i].posY2-wallArray[i].posY1))/scalarProduct[i]);
			prop2.push_back(((this->posY-wallArray[i].posY1)*(sensorArray[idSensor].x2-this->posX)+(wallArray[i].posX1-this->posX)*(sensorArray[idSensor].y2-this->posY))/scalarProduct[i]);
		}
		else
		{
			prop1.push_back(1);
			prop2.push_back(1);
		}
	}

	for(int i=0; i<wallsNumber; i++) //Choix du prop le plus petit
	{
		if((prop1[i] < 1 && prop1[i] >= 0) && (prop2[i] < 1 && prop2[i] >= 0))
		{
			if(prop1[i]<prop1Min)
			{
				prop1Min=prop1[i];
				testCollision=1;
			}
		}
	}

	if(testCollision==1)
	{
		sensorArray[idSensor].x2 = (sensorArray[idSensor].x2-this->posX)*prop1Min + this->posX;
		sensorArray[idSensor].y2 = (sensorArray[idSensor].y2-this->posY)*prop1Min + this->posY;

		if(prop1Min < 0.05) //test Crash voiture
		{
			alive=false;
		}
	}
}

std::vector<float> Car::getLengthSensors()
{
	vector<float> RealLengthSensor;

	for(int i=0; i<5; i++)
	{
		RealLengthSensor.push_back(pow(pow(sensorArray[i].x2-this->posX,2)+pow(sensorArray[i].y2-this->posY,2),0.5));
	}
	return RealLengthSensor;
}

void Car::moveCar()
{
		int move = evalue();
    float speed=2;
    if(move==1)
    {
        this->rotZ -= 0.02;
    }
    if(move==2)
    {
        this->rotZ += 0.02;
    }
    this->posX += speed * cos(this->rotZ);
    this->posY += speed * sin(this->rotZ);
}

int Car::evalue()
{
	return brain.evalue(Car::getLengthSensors());
}

void Car::setPosCar(float newposX, float newposY, float newrotZ)
{
	this->posX = newposX;
	this->posY = newposY;
	this->rotZ = newrotZ;
}

float Car::getposX()
{
	return this->posX;
}

float Car::getposY()
{
	return this->posY;
}

float Car::getrotZ()
{
	return this->rotZ;
}
