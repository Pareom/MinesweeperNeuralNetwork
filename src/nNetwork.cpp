#include "layer.h"
#include "nNetwork.h"

using namespace std;

NNetwork::NNetwork(vector<int> layerSize)//Normal
{
    setLayers(layerSize);
    toString();
    cout<<endl;
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

void NNetwork::evalue(vector<int> const& v)
{
    cout << "----------Evalue---------"<<endl;
    Layer copy(v);
    for(int i=0; i<(int)this->layers.size(); i++)
    {
        copy=copy*layers[i];

    }
    copy.toString();

}
int NNetwork::fitness(int const& shot)
{
  return shot*shot;
}
void NNetwork::gimmebaby(NNetwork a, NNetwork b)
{
  int mutation=5;
  int wich=0, cpt=0;
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
  this->toString();
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
