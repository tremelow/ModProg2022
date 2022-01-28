// TestCPlusPlus.cpp : 
//

#include "StdAfxExamplePlot.h"
#include<vector>
namespace plt = matplotlibcpp;

int main() {
    std::vector<int> data;
    
    data.resize(4);
    data[0] = 1;
    data[1] = 3;
    data[2] = 2;
    data[3] = 4;
    // plt::plot({1,3,2,4});
    plt::plot(data);
    plt::show();
}

