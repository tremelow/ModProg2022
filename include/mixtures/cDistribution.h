#pragma once
#ifndef _CDISTRIBUTION_H_
#define _CDISTRIBUTION_H_

#include <gsl/gsl_randist.h>
#include <vector>
#include <memory>
#include "StdAfxError.h"
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

    // Global RNG (not used)
    inline std::unique_ptr<gsl_rng, void(*)(gsl_rng*)> 
        rng(gsl_rng_alloc(gsl_rng_default), gsl_rng_free);
    
	class cDistribution
	{
        friend std::ostream& operator<<(std::ostream &os, const cDistribution& distrib);
        
        protected :                
            vector<double> parameter; ///< parameters (mean, variance)            
            gsl_rng* mtR ; ///< random generator

            // Common part of "Print" method: print parameters
            void ParameterPrint(ostream& theOut) const ;
            // < Copy attribute from instance theDistribution into *this
		    virtual void copy(const cDistribution& theDistribution); 

        public :
            /** Dummy constructor required by other constructors in 
             derived classes */
            cDistribution() ; 
            cDistribution(const vector<double>& theDistrParameter, 
                            bool theSimulFlag=true) ; ///< a simple constructor
            cDistribution(const cDistribution& theDistrib) ; ///< copy constructor
            cDistribution& operator=(const cDistribution& theDistrib); ///< copy operator
            virtual ~cDistribution() ; ///< a simple destructor

            /** Compute pdf */
            virtual double Density(double theY, bool theLog=false) const = 0;
            /** Draw a sample from distribution */
            virtual void Generate(uint theNSample, vector<double>& theYt) const = 0; 
            /** Return distribution parameters */
            vector<double> GetParams(void) const ;
            /** Return the number of parameters in distribution */
            virtual uint GetNParam(void) const ;
            /** Return distribution name */
            virtual ostringstream Name() const = 0; 
            /** Return the number of parameters in distribution */
            virtual void Plot(bool show=true) const = 0; ///< plot pdf with python
            /** Print distribution name and parameters */
            virtual void Print(ostream& theOut) const; 
	} ;
}

#endif //_CDISTRIBUTION_H_

