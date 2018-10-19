#include <iostream>
#include <string>
#include "layer.h"
#include "nNetwork.h"

using namespace std;


int main()
{

    srand(time(0));
    vector<int> v(4);
    for(int i =1; i<(int)v.size();i++){
        v[i]=3;
    }
    NNetwork test (v);
    return 0;
}
