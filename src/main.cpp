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

    int nbIteration(3);
    Graphic test; // Création de la classe Graphic
    int ticks(0);
    int carsNumber(1000);
    int carLeft=carsNumber;
    vector<Car> carArray;
    vector<Car> babyCarArray;
    int offSetWall(50);

    for (int i=0; i<carsNumber; i++)    //Remplissage du tableau des voitures
    {
        carArray.push_back(Car(i, offSetWall/2, offSetWall/2, -180/*+i*45*/, rand()%240, rand()%240, rand()%240)); // Création des voitures
    }

    vector<Line> wallArray; //Tableau des murs

    wallArray.push_back(Line(5,5,5,595)); //Remplissage du tableau des murs
    wallArray.push_back(Line(595,5,595,595));
    wallArray.push_back(Line(5,5,595,5));
    wallArray.push_back(Line(5,595,595,595));
    /*
    wallArray.push_back(Line(5+offSetWall,5+offSetWall,5+offSetWall,595-offSetWall)); //Remplissage du tableau des murs interieurs
    wallArray.push_back(Line(595-offSetWall,5+offSetWall,595-offSetWall,595-offSetWall));
    wallArray.push_back(Line(5+offSetWall,5+offSetWall,595-offSetWall,5+offSetWall));
    wallArray.push_back(Line(5+offSetWall,595-offSetWall,595-offSetWall,595-offSetWall));
    */
    //Ligne à la droite du départ
    wallArray.push_back((Line(100,5,100,495)));
    wallArray.push_back((Line(100,495,545,545)));
//Ligne par dessus Ilot DB
    wallArray.push_back((Line(595,355,300,250)));
    wallArray.push_back((Line(300,250,230,450)));
    wallArray.push_back((Line(230,450,200,430)));
    wallArray.push_back((Line(200,430,150,300)));
    wallArray.push_back((Line(150,300,120,100)));
    wallArray.push_back((Line(120,100,140,45)));
    wallArray.push_back((Line(140,45,595,45)));
//Ilot Droite Bas(DB)
    wallArray.push_back((Line(300,340,280,450)));//gauche
    wallArray.push_back((Line(280,450,480,480)));//bas
    wallArray.push_back((Line(480,480,480,340)));//droite
    wallArray.push_back((Line(300,340,480,340)));//haut

    while (window.isOpen())  // Boucle principale + Affichage
    {
        sf::Event event;
        while(nbIteration!=0)
        {
          nbIteration--;
          while(carLeft!=-1)//Tant qu'il y a des voitures en vies
          {
            ticks++;
            if(ticks==60){//Murs pour tuer ceux qui tournent au début
              wallArray.push_back((Line(5,5,100,100)));
            }
            if(ticks==150){//Murs pour tuer les resistants
              wallArray.push_back((Line(30,5,30,200)));
              wallArray.push_back((Line(70,5,70,200)));
            }
            if(ticks==320){//Murs pour tuer les resistants
              wallArray.push_back((Line(30,5,30,595)));
              wallArray.push_back((Line(70,5,70,595)));
            }
              while (window.pollEvent(event))
              {
                  if (event.type == sf::Event::Closed)
                  {
                      window.close();
                      return 0;
                  }
              }

              window.clear();
              for(int i=0; i<wallArray.size(); i++) //Affichage des murs
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
                      carArray[i].refreshPosSensor(j, wallArray, wallArray.size());
                  }

                  displayLengthTest = carArray[i].getLengthSensors();  //Récuperation des longueurs des capteurs


                  test.drawCar(carArray[i],window); // Affichage de la voiture

                  test.drawSensors(carArray[i],window); // Affichage des capteurs

                }
              }
              window.display();

              usleep(10000); // Attente 0.5 sec
            }//Toutes les voitures sont mortes(ou ont finis)
            TotalGenSize=0;
            for(int i=0; i<carArray.size(); i++)
            {
              TotalGenSize+=carArray[i].getSize();//Implent this
            }
            //Check for the best Car and put it straight
            //into the baby vector

        }
        // Affichage de l'écran de fin

        window.clear();
        test.writeCrash(window);
        window.display();

        usleep(1500000);
        break;

    }

    window.close();

    carArray.clear();
    cout << carArray.size() << endl;
	return 0;
}
