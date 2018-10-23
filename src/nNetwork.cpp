//#include "layer.h"
#include "nNetwork.h"

using namespace std;

NNetwork::NNetwork(vector<int> layerSize){

    setLayers(layerSize);
    toString();
}

void NNetwork::setLayers(vector<int> layerSize){
    for(int i=0; i<((int)layerSize.size()-1); i++){
        this->layers.push_back((Layer(layerSize[i],layerSize[i+1])));
    }
}

void NNetwork::evalue(vector<int> const& v){
    cout << "----------Evalue---------"<<endl;
    Layer copy(v);
    for(int i=0; i<(int)this->layers.size(); i++){
        copy=copy*layers[i];

    }
    copy.toString();

}
void NNetwork::toString(){
    for(int i = 0; i<(int)this->layers.size(); i++){
        this->layers[i].toString();
    }

}
