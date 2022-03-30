
#include <stdio.h>


#include <iostream>
#include <ostream>
#include <gsl/gsl_cdf.h>

#include "StdAfxMixtures.h"
#include "matplotlibcpp.h"

#include <vector>

using namespace ErrorNameSpace;
using namespace Mixtures ;
using namespace std;

enum Plot_Types {
    pdf,
    hist,
    none
};

int main(int argc, char* argv[])
{
    cout.precision(12) ; 
    const Plot_Types plot_type = hist; // type of plot

    cExponential myExponential(1.5);
    cExponential myExponentialCp = myExponential;
    cExponential myExponentialCp2(1.0);

    uint mySampleSize = 10, t;
    vector<double> mySample, mySample2, abs, ord;
    // Simulate
    
    // myExponentialCp2 = myExponential;
    cout << "Created model " ;
    myExponential.Print(cout);

    cout << "Created model (Distribution::Print)" ;
    myExponential.cDistribution::Print(cout);

    // cout << "Copy: " << myExponentialCp << endl;
    
    myExponential.Generate(mySampleSize, mySample); 
    myExponentialCp.Generate(mySampleSize, mySample2);
    
    cout << "Simulated variables: " << endl;
    for (t=0; t < mySampleSize-1; t++)
        cout << mySample[t] << "\t";
    cout << mySample[mySampleSize-1] << endl;   

    cout << "Simulated variables: " << endl;
    for (t=0; t < mySampleSize-1; t++)
        cout << mySample2[t] << "\t";
    cout << mySample2[mySampleSize-1] << endl;   

    // Plot pdf
    abs.resize(1000);
    ord.resize(1000);
    for (t=0; t < 1000; t++)
    {
        abs[t] = -0.2 + t * 3. / 1000;
        ord[t] = myExponential.Density(abs[t]);
    }
    
    
    // Simulate larger sample and plot histogram
    myExponential.Generate(1000, mySample);
        
    // switch (plot_type)
    // {
    //   case pdf :
    //      myExponential.Plot();
    //      break;
    //   case hist :
    //      matplotlibcpp::hist(mySample);
    //      matplotlibcpp::show();
    //      break;
    // }
    
    
    
    return 0 ;


}