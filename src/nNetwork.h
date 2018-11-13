#ifndef DEF_NNETWORK
#define DEF_NNETWORK

#include <iostream>
#include <string>
#include <vector>
#include "layer.h"

class NNetwork
{
    public:

    NNetwork(std::vector<int> layerSize);
    NNetwork(NNetwork const& a);
    void setLayers(std::vector<int> layerSize);
    void evalue(std::vector<int> const& v);
    int fitness(int const& shot);
    void gimmebaby(NNetwork a, NNetwork b);
    void setLayer(int i, float number,int k, int l);
    float getLayerComponent(int i, int k, int l) const;
    Layer getLayer(int const& i) const;
    int getLayerSize() const;
    void toString();

    private:

    std::vector<Layer> layers;
};

#endif
