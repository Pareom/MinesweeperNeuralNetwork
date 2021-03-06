#ifndef DEF_NNETWORK
#define DEF_NNETWORK

#include <iostream>
#include <string>
#include <vector>
#include "layer.h"

class NNetwork // Classe nNetwork
{
    public:

    NNetwork(std::vector<int> const& layerSize);
    NNetwork(NNetwork const& a);
    void setLayers(std::vector<int> layerSize);
    int evalue(std::vector<float> const& v);
    int fitness(int const& shot);
    void gimmebaby(NNetwork a, NNetwork b);
    void setLayer(int i, float number,int k, int l);
    float getLayerComponent(int i, int k, int l) const;
    Layer getLayer(int const& i) const;
    int getLayerSize() const;
    void toString();
    void gradiant(std::vector<int> inputs, std::vector<int> const& wantedOutput, std::vector<int> const& actualOutput);

    private:

    std::vector<Layer> layers;
    std::vector<Layer> inputs;
};

#endif
