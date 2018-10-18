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
    void setLayers(std::vector<int> layerSize);
    void toString();

    private:

    std::vector<Layer> layers;
};

#endif
