#ifndef DEF_GRAPHIC
#define DEF_GRAPHIC

#include <vector>
#include <SFML/Graphics.hpp> 
#include <iostream>
#include "Car.h"
#include "Line.h"

class Graphic
{
	public:

	void drawLine(float p1X, float p1Y, float p2X, float p2Y, sf::RenderWindow& window);
	void drawLine(Line wall, sf::RenderWindow& window);
	void drawCar(Car inputCar, sf::RenderWindow& window);
	void drawSensors(Car inputCar, sf::RenderWindow& window);
	void writeCrash(sf::RenderWindow& window);

};

#endif
