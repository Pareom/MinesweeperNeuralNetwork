#include "layer.h"
#include "nNetwork.h"

using namespace std;

NNetwork::NNetwork(vector<int> const& layerSize)//Normal
{
    setLayers(layerSize);
    //toString();
    //cout<<endl;
}
NNetwork::NNetwork(NNetwork const& a)
{
  for(int i=0; i<(int)(a.layers.size()); i++)//Attention
  {
    this->layers.push_back(Layer(a.layers[i]));//copy each layer
  }
}

void NNetwork::setLayers(vector<int> layerSize)
{
    for(int i=0; i<((int)layerSize.size()-1); i++)
    {
        this->layers.push_back((Layer(layerSize[i],layerSize[i+1])));
    }
}

int NNetwork::evalue(vector<float> const& v)
{
  int iMax=0;
  float nMax;
    vector<float> test(5,1);
    Layer copy(v);//mettre "v" à la place de test

    for(int i=0; i<(int)this->layers.size(); i++)
    {
        copy=copy*layers[i];
    }
    nMax=copy.getMatrixComponent(0,0);
    for(int i=0; i<copy.getNbOut(); i++)
    {
      if(nMax<copy.getMatrixComponent(0,i))
      {
        iMax=i;
        nMax=copy.getMatrixComponent(0,i);
      }
    }
    return iMax;
}
int NNetwork::fitness(int const& shot)
{
  return shot*shot;
}
void NNetwork::gimmebaby(NNetwork a, NNetwork b)
{
  int mutation=5;
  int max; //sure?
  //NNetwork c(a);//Faire la copy(construct), faire un destructeur
  for(int i=0; i<a.getLayerSize(); i++)
  {
    //a.getLayer(i).getNbIn()*a.getLayer(i).getNbOut());
    for(int k=0; k<a.getLayer(i).getNbIn(); k++)
    {
      for(int l=0; l<a.getLayer(i).getNbOut(); l++)//Implementer getLayer()
      {
        if(rand()%mutation)
        {
          max=rand()%(2);
          if(max){//Implementer la mutation
            this->setLayer(i,a.getLayerComponent(i,k,l),k,l);//Implementer setLayer()
          }else
          {
            this->setLayer(i,b.getLayerComponent(i,k,l),k,l);
          }
        }else
        {
          this->setLayer(i,((float)(rand() % 200000))/100000 -1,k,l);
          //this->setLayer(i,0.f,k,l);
        }
      }
    }
  }
}
void NNetwork::setLayer(int i, float number,int k, int l)
{
  this->layers[i].setMatrixComponent(k,l,number);
}
float NNetwork::getLayerComponent(int i, int k, int l) const
{
  return layers[i].getMatrixComponent(k,l);
}
Layer NNetwork::getLayer(int const& i) const
{
  return this->layers[i];
}
int NNetwork::getLayerSize() const
{
  return this->layers.size();
}
void NNetwork::toString()
{
    for(int i = 0; i<(int)this->layers.size(); i++)
    {
        this->layers[i].toString();
    }
}
