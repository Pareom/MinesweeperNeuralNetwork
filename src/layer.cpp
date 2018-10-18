#include "layer.h"
#include <ctime> // pour le random
#include <cstdlib> // pour le random
using namespace std;

Layer::Layer(){}
Layer::Layer(int m_nbIn, int m_nbOut): nbIn(m_nbIn),nbOut(m_nbOut)
{
    randomFilling();
    //toString();
}

void Layer::randomFilling(){
    for(int i=0; i<nbIn; i++){
        this->matrix.push_back(vector<float>(nbOut));
        for(int j=0; j<nbOut; j++){
            this->matrix[i][j]=((float)(rand() % 200000))/100000;//Entre 0 et 2 le tout -1 donc entre -1 et 1 (5chiffres après la virgule)
        }
    }

}

void Layer::toString() const{
    cout << "Taille : " << this->matrix.size() << " : " << this->matrix[0].size() << endl;
    /*for(int i=0; i<nbIn; i++){
        for(int j=0; j<nbOut; j++){
            cout << this->matrix[i][j] << " ";
        }
        cout << endl;
    }*/
}
