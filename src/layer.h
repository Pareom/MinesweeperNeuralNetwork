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
    Layer(std::vector<float> const& v);
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
