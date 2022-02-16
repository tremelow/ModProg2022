// Test.cpp : definit le point d'entree pour l'application console.
//
// Pour executer en dehors de netbeans: 
// export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./Mixtures/dist/Debug/GNU-Linux/:./Error/dist/Debug/GNU-Linux/
#include "StdAfxTestCPlusPlus.h"

using namespace ErrorNameSpace;
using namespace Mixtures;

int main(int argc, char* argv[])

{
    int i;
    std::vector<double> vec;
    double v;
    cCorruptedGaussian **myGaussianCollection = new cCorruptedGaussian*[10];
    
    cout.precision(12) ; 

    
    for (i=0; i < 10; i++)  
    {
        myGaussianCollection[i] = new cCorruptedGaussian(i+1, i*0.1);
        // myGaussianCollection[i] = new cCorruptedGaussian(i+1, i+0.1);
    }

    vec = myGaussianCollection[0]->GetParams();
    for (i=0; i < 3; i++)  
    {
        v = vec[i];
    }
    
    for (i=0; i < 11; i++)  
    {
        delete myGaussianCollection[i];
        // myGaussianCollection[i] = NULL;
    }
    
    myGaussianCollection[9]->Print(cout);
    
    delete [] myGaussianCollection;
    myGaussianCollection = NULL;
    
    return 0 ;


}
