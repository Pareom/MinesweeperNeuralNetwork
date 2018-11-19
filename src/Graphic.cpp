#include "Graphic.h"
#include "Car.h"
#include "Line.h"
#include <SFML/Graphics.hpp>
#include <vector>

#define PI 3.14159265359

using namespace std; 


void Graphic::drawLine(float p1X, float p1Y, float p2X, float p2Y, sf::RenderWindow& window)
{
	sf::Vertex line[] = 
	{
		sf::Vertex(sf::Vector2f(p1X, p1Y)),
		sf::Vertex(sf::Vector2f(p2X, p2Y))
	};

	window.draw(line, 2, sf::Lines);
}

void Graphic::drawLine(Line wall, sf::RenderWindow& window)
{
	sf::Vertex line[] = 
	{
		sf::Vertex(sf::Vector2f(wall.posX1, wall.posY1)),
		sf::Vertex(sf::Vector2f(wall.posX2, wall.posY2))
	};

	window.draw(line, 2, sf::Lines);
}

void Graphic::drawCar(Car inputCar, sf::RenderWindow& window)
{
	sf::Color color(inputCar.colorR, inputCar.colorG, inputCar.colorB, 255);
	sf::RectangleShape rectangle(sf::Vector2f(12, 8));
	rectangle.setPosition(inputCar.getposX(), inputCar.getposY());
	rectangle.setOrigin (6,4);
	rectangle.setRotation(inputCar.getrotZ()*360/(2*PI));
	rectangle.setFillColor(color);

	window.draw(rectangle);
}

void Graphic::drawSensors(Car inputCar, sf::RenderWindow& window)
{
	for(int i=0;i<5;i++)
	{
		Graphic::drawLine(inputCar.getposX(), inputCar.getposY(), inputCar.sensorArray[i].x2, inputCar.sensorArray[i].y2,window);	
	}
}

void Graphic::writeCrash(sf::RenderWindow& window)
{
	sf::Font font; 				//Font 

    if (!font.loadFromFile("OpenSans-ExtraBold.ttf")) //Loading Font..
    {
        cout << "erreur" << endl;
    }

    sf::Text text; 				//Text

    text.setPosition(40, 200); //Text position

    text.setFont(font);					//Text font
    text.setColor(sf::Color::Red);	//Text color
    text.setCharacterSize(50);			//Text size

	text.setString("Crash de la voiture !!");

	window.draw(text);
}