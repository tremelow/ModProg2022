#pragma once
#ifndef _CEXPONENTIAL_H_
#define _CEXPONENTIAL_H_

#include <gsl/gsl_randist.h>
#include <vector>
#include "MixturesDef.h"
#include "cDistribution.h"

/*!
 \file cExponential.h
 \brief Definition of the class for exponential distributions.

 \author Jean-Baptiste DURAND
 \date jan-28-2022
*/

namespace Mixtures {

	/*! 
	 * \class cExponential
	 * \brief Class to implement N(m, s2) distributions.
	 */
        using namespace std;

    
	class cExponential : public cDistribution
	{
            friend std::ostream& operator<<(std::ostream &os, const cExponential& distrib);
        
            public :
                cExponential(const vector<double>& theDistrParameter, 
                          bool theSimulFlag=true) ; ///< a simple constructor
                cExponential(float theParam, bool theSimulFlag=true) ; ///< a simple constructor
                virtual ~cExponential() ; ///< a simple destructor
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

#endif //_CEXPONENTIAL_H_

