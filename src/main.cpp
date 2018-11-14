#include "Graphic.h"
#include "Car.h"
#include "Sensor.h"
#include "Line.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265359

using namespace std;

void moveCar(Car *c1, int left);

int main()
{


    srand (time(NULL));

    sf::RenderWindow window(sf::VideoMode(600, 600), "Cars race"); // Creation of the window

    int testEnd(0);

    Graphic test;
    Car voiture1(1);

    cout << "voiture crée" << endl;

    //----Les Murs----
    int wallsNumber(2);
    vector<Line> wallArray; //Tableau des murs

    wallArray.push_back(Line(140,80,140,600)); //Remplissage du tableau des murs
    wallArray.push_back(Line(160,0,160,600));

    cout << "Murs crées" << endl;
    //----------------

    while (window.isOpen())
    {
        sf::Event event;

        while(testEnd==0)
        {

            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                    return 0;
                }
            }

            window.clear();

            for(int i=0; i<wallsNumber; i++) //Affichage des murs
            {
                test.drawLine(wallArray[i],window);
            }

            for(int i=0; i<5; i++) //Calcul des Capteurs (collision)
            {
                testEnd+=voiture1.refreshPosSensor(i, wallArray, wallsNumber);
            }

            test.drawCar(voiture1,window); // Affichage de la voiture

            test.drawSensors(voiture1,window); // Affichage des capteurs

            window.display();

            moveCar(&voiture1, rand()%2); // Déplacement de la voiture

            usleep(100000); // Attente 0.5 sec

        }

        window.clear();
        test.writeCrash(window);
        window.display();

        usleep(1500000);
        break;

    }

    window.close();
	return 0;
}

void moveCar(Car *c1, int left)
{
    float newrotZ;
    float speed=2;
    if(left==1)
    {
        newrotZ = (c1->getrotZ()) - 0.02;
    }
    else
    {
        newrotZ = (c1->getrotZ()) + 0.02;
    }

    float newposX( ( c1->getposX() ) + speed * cos(newrotZ*2*PI/360));
    float newposY( ( c1->getposY() ) + speed * sin(newrotZ*2*PI/360));

    c1->setPosCar(newposX, newposY, newrotZ);
}
