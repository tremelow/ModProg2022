// Test.cpp : definit le point d'entree pour l'application console.
//

#include "StdAfxTestCPlusPlus.h"
#include <vector>

using namespace ErrorNameSpace;
using namespace Mixtures ;
using namespace std;

int main(int argc, char* argv[])
{
    cout.precision(12) ; 

    cGaussian myGaussian(4, 4);
    uint mySampleSize = 10, t;
    vector<double> mySample, abs, ord;
    // Simulate
    
    cout << "Created model " ;
    myGaussian.Print(cout);
    
    myGaussian.Generate(mySampleSize, mySample);    
    
    cout << "Simulated variables: " << endl;
    for (t=0; t < mySampleSize-1; t++)
        cout << mySample[t] << "\t";        
    cout << mySample[mySampleSize-1] << endl;   

    // Plot pdf
    matplotlibcpp::subplot(1, 2, 1);
    abs.resize(1000);
    ord.resize(1000);
    for (t=0; t < 1000; t++)
    {
        abs[t] = -2 + t * 12. / 1000;
        ord[t] = myGaussian.Density(abs[t]);
        cout << "(" << abs[t] << "; " << ord[t] << ")" << endl;
    }
    matplotlibcpp::plot(abs, ord);
    
    // Simulate larger sample and plot histogram
    myGaussian.Generate(1000, mySample);
    matplotlibcpp::subplot(1, 2, 2);    
    matplotlibcpp::hist(mySample);
    matplotlibcpp::show();
    
    return 0 ;


}
