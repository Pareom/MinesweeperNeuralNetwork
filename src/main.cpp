#include <iostream>
#include <string>
#include "layer.h"
#include "nNetwork.h"

using namespace std;


int main()
{

    srand(time(0));//A laisser
    vector<int> v(4);
    vector<int> inputV(3);
    //Setting each layer's size
    for(int i =0; i<(int)v.size();i++){
        v[i]=3;
    }
    NNetwork test1 (v);
    NNetwork test2 (v);
    NNetwork test3 (v);
    cout << "BEBE" << endl;
    test3.gimmebaby(test1,test2);
    /*
    //Setting the Input vector
    for(int i =0; i<(int)inputV.size();i++){
        inputV[i]=1;
    }
    test.evalue(inputV);
    */
    return 0;
}
