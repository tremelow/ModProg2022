#pragma once
#ifndef _CDISTRIBUTION_H_
#define _CDISTRIBUTION_H_

#include <gsl/gsl_randist.h>
#include <vector>
#include "MixturesDef.h"

/*!
 \file cDistribution.h
 \brief Definition of the virtual class for (continuous) distributions.

 \author Jean-Baptiste DURAND
 \date jan-28-2022
*/

namespace Mixtures {

	/*! 
	 * \class cDistribution
	 * \brief Definition of the virtual class for (continuous) distributions.
	 */
        using namespace std;
    
	class cDistribution
	{
            friend std::ostream& operator<<(std::ostream &os, const cDistribution& distrib);
        
            protected :                
                vector<double> parameter; ///< parameters (mean, variance)            
                gsl_rng* mtR ; ///< random generator
                
                // Common part of "Print" method: print parameters
                void ParameterPrint(ostream& theOut) const ;

            public :
                /** Dummy constructor required by other constructors in 
                 derived classes */
                cDistribution() ; 
                cDistribution(const vector<double>& theDistrParameter, 
                              bool theSimulFlag=true) ; ///< a simple constructor
                cDistribution(const cDistribution& theDistrib) ; ///< a copy constructor
                virtual ~cDistribution() ; ///< a simple destructor
                // A completer
                /** Compute pdf */
                double Density(double theY, bool theLog=false) const;
                /** Draw a sample from distribution */
                void Generate(uint theNSample, vector<double>& theYt) const; 
                /** Return distribution parameters */
                vector<double> GetParams(void) const ;
                /** Return the number of parameters in distribution */
                uint GetNParam(void) const ;
                /** Return distribution name */
                ostringstream Name() const ; 
                /** Return the number of parameters in distribution */
                void Plot(bool show=true) const; ///< plot pdf with python
                /** Print distribution name and parameters */
                void Print(ostream& theOut) const; 
	} ;

}

#endif //_CDISTRIBUTION_H_

