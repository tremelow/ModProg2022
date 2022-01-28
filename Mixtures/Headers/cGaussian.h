#pragma once
#ifndef _CGAUSSIAN_H_
#define _CGAUSSIAN_H_

#include <gsl/gsl_randist.h>
#include <vector>
#include "MixturesDef.h"

/*!
 \file cGaussian.h
 \brief Definition of the class for N(m, s2) distributions.

 \author Jean-Baptiste DURAND
 \date jan-27-2022
*/

namespace Mixtures {

	/*! 
	 * \class cGaussian
	 * \brief Class to implement N(m, s2) distributions.
	 */
        using namespace std;
    
	class cGaussian
	{
            friend std::ostream& operator<<(std::ostream &os, const cGaussian& distrib);
        
            protected :
                /// parameters (mean, variance)
                vector<double> parameter;            
                gsl_rng* mtR ; ///< random generator

            public :
                cGaussian(const vector<double>& theDistrParameter, 
                          bool theSimulFlag=true) ; ///< a simple constructor
                cGaussian(float theMean, float theVariance, 
                          bool theSimulFlag=true) ; ///< a simple constructor
                virtual ~cGaussian() ; ///< a simple destructor
                // virtual cAbstDistribution* PtrCopy() const ; /// < Return a copy of *this
                double Density(double theY, bool theLog=false) const ;
                /** Return the number of parameters in distribution */
                void Generate(uint theNSample, vector<double>& theYt) const ; ///< Draw a sample from distribution 
                uint GetNParam(void) const ;
                void Plot(bool show=true) const; ///< plot pdf with python
                void Print(ostream& theOut) const ; ///< print the distribution type
	} ;

}

#endif //_CGAUSSIAN_H_

