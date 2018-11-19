#include "Graphic.h"
#include "Car.h"
#include "Sensor.h"
#include "Line.h"
#include "nNetwork.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <math.h>
#include <time.h>

using namespace std;

int main()
{
    vector<float> displayLengthTest; // Vecteur 5 float des longueurs des capteurs

    srand (time(NULL)); // Initialisation du random

    sf::RenderWindow window(sf::VideoMode(600, 600), "Cars race"); // Creation of the window


    Graphic test; // Création de la classe Graphic

    int carsNumber(8);
    int carLeft=carsNumber;
    vector<Car> carArray;
    int offSetWall(100);

    for (int i=0; i<carsNumber; i++)    //Remplissage du tableau des voitures
    {
        carArray.push_back(Car(i, offSetWall/2, offSetWall/2, -180/*+i*45*/, rand()%240, rand()%240, rand()%240)); // Création des voitures
    }

    int wallsNumber(4+4); // Nombre de murs
    vector<Line> wallArray; //Tableau des murs

    wallArray.push_back(Line(5,5,5,595)); //Remplissage du tableau des murs
    wallArray.push_back(Line(595,5,595,595));
    wallArray.push_back(Line(5,5,595,5));
    wallArray.push_back(Line(5,595,595,595));

    wallArray.push_back(Line(5+offSetWall,5+offSetWall,5+offSetWall,595-offSetWall)); //Remplissage du tableau des murs interieurs
    wallArray.push_back(Line(595-offSetWall,5+offSetWall,595-offSetWall,595-offSetWall));
    wallArray.push_back(Line(5+offSetWall,5+offSetWall,595-offSetWall,5+offSetWall));
    wallArray.push_back(Line(5+offSetWall,595-offSetWall,595-offSetWall,595-offSetWall));

    while (window.isOpen())  // Boucle principale + Affichage
    {
        sf::Event event;

        while(carLeft!=0)//Tant qu'il y a des voitures en vies
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

            carLeft=0;
            for(int i=0; i<carsNumber; i++)
            {
              if(carArray[i].alive)
              {
                carLeft++;
                carArray[i].moveCar(); // Déplacement de la voiture pour le prochain tour
                for(int j=0; j<5; j++) //Calcul des Capteurs (collision)
                {
                    carArray[i].refreshPosSensor(j, wallArray, wallsNumber);
                }
              }
                displayLengthTest = carArray[i].getLengthSensors();  //Récuperation des longueurs des capteurs


                test.drawCar(carArray[i],window); // Affichage de la voiture

                test.drawSensors(carArray[i],window); // Affichage des capteurs


            }
            /*for(int i=0; i<5; i++)                      // Affichage des longueurs des capteurs
            {
                cout << "Capteur numéro " << i << " : Length = " << displayLengthTest[i] << endl;
            }
            cout << endl;
            */

            window.display();

            usleep(20000); // Attente 0.5 sec

        }
        // Affichage de l'écran de fin

        window.clear();
        test.writeCrash(window);
        window.display();

        usleep(1500000);
        break;

    }

    window.close();
	return 0;
}
