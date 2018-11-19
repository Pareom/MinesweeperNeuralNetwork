#include "layer.h"
#include <ctime> // pour le random
#include <cstdlib> // pour le random
using namespace std;

Layer::Layer(){}
Layer::Layer(Layer const& toCopy):nbIn(toCopy.getNbIn()), nbOut(toCopy.getNbOut())
{
    for(int i=0; i<this->nbIn; i++){
        this->matrix.push_back(vector<float>(this->nbOut));
        for(int j=0; j<this->nbOut; j++){
            this->matrix[i][j]=toCopy.getMatrixComponent(i,j);//Entre 0 et 2 le tout -1 donc entre -1 et 1 (5chiffres après la virgule)
        }
    }
}
Layer::Layer(int const& m_nbIn, int const& m_nbOut): nbIn(m_nbIn),nbOut(m_nbOut)
{
    randomFilling();
}
Layer::Layer(vector<float> const& v): nbIn(1),nbOut(v.size())
{
    randomFilling();//Clean this
    for(int i=0; i<(int)v.size(); i++)
    {
        this->matrix[0][i]=(float)v[i];
    }
}

void Layer::randomFilling(){
    for(int i=0; i<nbIn; i++){
        this->matrix.push_back(vector<float>(nbOut));
        for(int j=0; j<nbOut; j++){
            this->matrix[i][j]=((float)(rand() % 200000))/100000 -1;//Entre 0 et 2 le tout -1 donc entre -1 et 1 (5chiffres après la virgule)
        }
    }

}
void Layer::setMatrixComponent(int const& i, int const& j, float const& a){
    this->matrix[i][j] = a;
}

float Layer::getMatrixComponent(int const& i, int const& j) const{
    return this->matrix[i][j];
}
int Layer::getNbIn() const{
    return this->nbIn;
}
int Layer::getNbOut() const{
    return this->nbOut;
}
void Layer::toString() const{
    cout << "Taille : " << this->matrix.size() << " : " << this->matrix[0].size() << endl;
    for(int i=0; i<nbIn; i++){
        for(int j=0; j<nbOut; j++){
            cout << this->matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------------------" << endl;
}


Layer operator*(Layer const& a, Layer const& b){
    //cout << a.getNbIn()<< " : " << a.getNbOut()<< " U " << b.getNbIn()<< " : " << b.getNbOut()<<endl;
    Layer result(a.getNbIn(),b.getNbOut());
    float cpt;
    for(int i=0; i<a.getNbIn(); i++){
        for(int j=0; j<b.getNbOut(); j++){
                cpt=0;
                for(int k=0; k<a.getNbOut(); k++){
                    cpt += a.getMatrixComponent(i,k)*b.getMatrixComponent(k,j);
                }
                result.setMatrixComponent(i,j,cpt);//You may divide the result by k to avoid "inf" values
        }
    }
    return result;
}
