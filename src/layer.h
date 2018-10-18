#ifndef DEF_LAYER
#define DEF_LAYER

#include <iostream>
#include <string>
#include <vector>

class Layer
{
    public:
    Layer();
    Layer(int nbIn, int nbOut);
    //Couche(std::string nom, int degats);
    //void changer(std::string nom, int degats);
    void randomFilling();
    void toString() const;
    private:

    int nbIn, nbOut;
    std::vector<std::vector<float>> matrix;
};

#endif
