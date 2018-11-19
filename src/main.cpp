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

    int testEnd(0); // test de Crash

    Graphic test; // Création de la classe Graphic

    int carsNumber(8);
    vector<Car> carArray;

    for (int i=0; i<carsNumber; i++)    //Remplissage du tableau des voitures
    {
        carArray.push_back(Car(i, 300, 300, -180+i*45, 120*(1+rand()%2), 120*rand()%3, 120*rand()%3)); // Création des voitures
    }

    int wallsNumber(4); // Nombre de murs
    vector<Line> wallArray; //Tableau des murs

    wallArray.push_back(Line(5,5,5,595)); //Remplissage du tableau des murs
    wallArray.push_back(Line(595,5,595,595));
    wallArray.push_back(Line(5,5,595,5));
    wallArray.push_back(Line(5,595,595,595));


    while (window.isOpen())  // Boucle principale + Affichage
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

            for(int i=0; i<carsNumber; i++)
            {

                carArray[i].moveCar(); // Déplacement de la voiture pour le prochain tour
                for(int j=0; j<5; j++) //Calcul des Capteurs (collision)
                {
                    testEnd+=carArray[i].refreshPosSensor(j, wallArray, wallsNumber);
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

            usleep(10000); // Attente 0.5 sec

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
