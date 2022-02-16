#pragma once
#ifndef _CCORRUPTED_GAUSSIAN_H_
#define _CCORRUPTED_GAUSSIAN_H_

#include <gsl/gsl_randist.h>
#include <vector>
#include "MixturesDef.h"

/*!
 \file cCorruptedGaussian.h
 \brief Definition of the class for N(m, s2) distributions.
 * Corrupted for the need of illustrating debugging

 \author Jean-Baptiste DURAND
 \date jan-28-2022
*/

namespace Mixtures {

	/*! 
	 * \class cCorruptedGaussian
	 * \brief Class to implement N(m, s2) distributions.
	 */
        using namespace std;

    
	class cCorruptedGaussian  
	{
            protected :                
                vector<double> parameter; ///< parameters (mean, variance)            
                gsl_rng* mtR ; ///< random generator

            public :
                cCorruptedGaussian(const vector<double>& theDistrParameter, 
                          bool theSimulFlag=true) ; ///< a simple constructor
                cCorruptedGaussian(float theMean, float theVariance, 
                          bool theSimulFlag=true) ; ///< a simple constructor
                virtual ~cCorruptedGaussian() ; ///< a simple destructor
                /** Compute pdf */
                double Density(double theY, bool theLog=false) const ;
                /** Draw a sample from distribution */
                void Generate(uint theNSample, vector<double>& theYt) const ; 
                /** Return distribution parameters */
                vector<double> GetParams(void) const ;
                /** Return the number of parameters in distribution */
                uint GetNParam(void) const ;
                /** Return distribution name */
                ostringstream Name() const; 
                void Plot(bool show=true) const; ///< plot pdf with python
                /** Print distribution name and parameters */
                void Print(ostream& theOut) const ; 
	} ;

}

#endif //_CCORRUPTED_GAUSSIAN_H_

