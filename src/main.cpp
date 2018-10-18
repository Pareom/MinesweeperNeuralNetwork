#include <iostream>
#include <string>
#include "layer.h"
#include "nNetwork.h"

using namespace std;


int main()
{

    srand(time(0));
    vector<int> v(5);
    for(int i =0; i<5;i++){
        v[i]=i+1;
    }
    NNetwork test (v);
    return 0;
}
