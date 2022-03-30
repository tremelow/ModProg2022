#pragma once
#ifndef _CGAUSSIAN_H_
#define _CGAUSSIAN_H_

#include <gsl/gsl_randist.h>
#include <vector>
#include "MixturesDef.h"
#include "cDistribution.h"

/*!
 \file cGaussian.h
 \brief Definition of the class for N(m, s2) distributions.

 \author Jean-Baptiste DURAND
 \date jan-28-2022
*/

namespace Mixtures {

	/*! 
	 * \class cGaussian
	 * \brief Class to implement N(m, s2) distributions.
	 */
        using namespace std;

    
	class cGaussian : public cDistribution
	{
            friend std::ostream& operator<<(std::ostream &os, const cGaussian& thecGaussian);
        
            public :
                cGaussian(const vector<double>& theDistrParameter, 
                          bool theSimulFlag=true) ; ///< a simple constructor
                cGaussian(float theMean, float theVariance, 
                          bool theSimulFlag=true) ; ///< a simple constructor
                ///< = operator for cGaussian Class
                cGaussian& operator=(const cGaussian& thecGaussian) ; 
                virtual ~cGaussian() ; ///< a simple destructor
                /** Compute pdf */
                double Density(double theY, bool theLog=false) const ;
                /** Draw a sample from distribution */
                void Generate(uint theNSample, vector<double>& theYt) const ; 
                /** Return the number of parameters in distribution */
                uint GetNParam(void) const ;
                /** Return distribution name */
                ostringstream Name() const; 
                void Plot(bool show=true) const; ///< plot pdf with python
                /** Print distribution name and parameters */
                void Print(ostream& theOut) const ; 
	} ;

}

#endif //_CGAUSSIAN_H_

