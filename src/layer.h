#ifndef DEF_LAYER
#define DEF_LAYER

#include <iostream>
#include <string>
#include <vector>

class Layer
{
    public:
    Layer();
    Layer(Layer const& toCopy);
    Layer(int const& nbIn, int const& nbOut);
    //Couche(std::string nom, int degats);
    //void changer(std::string nom, int degats);
    void randomFilling();//Initialisations
    void setMatrixComponent(int const& i, int const& j, float const& a);
    float getMatrixComponent(int const& i, int const& j) const;
    void toString() const;
    int getNbIn() const;
    int getNbOut() const;
    private:

    int nbIn, nbOut;
    std::vector<std::vector<float>> matrix;
};

Layer operator*(Layer const& a, Layer const& b);
#endif
/*
Evalue()
Use this function to make all the compution of the network assuming the layer 1 is the input and the last*/
