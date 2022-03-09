#include <math.h>  
#include <gsl/gsl_cdf.h>
#include <iostream>
#include <sstream>
#include "cDistribution.h"

using namespace std;

/*!
 \file cDistribution.cpp
 \brief Implementation of the virtual class for (continuous) distributions.

 \author Jean-Baptiste DURAND
 \date jan-27-2022
*/
namespace Mixtures {
    
        using namespace std;

	/*!
	 * \fn cDistribution::cDistribution()
         * 
	 */
	cDistribution::cDistribution()
        : parameter()
        {
            mtR = NULL;
        }
	/*!
	 * \fn cDistribution::cDistribution(const vector<double>& theDistrParameter, 
                                            bool theSimulFlag)
	 * \param bool theSimulFlag: true if created for simulation
	 */
	cDistribution::cDistribution(const vector<double>& theDistrParameter, 
                                     bool theSimulFlag)
	{           
            parameter = theDistrParameter;
            
            if (theSimulFlag)
            {	// random generator simulation
                gsl_rng_env_setup() ;
                mtR = gsl_rng_alloc(gsl_rng_default) ;
            }
            else
                mtR = NULL ;
            
            MESS_CREAT("cDistribution")
	}
	/*!
	 * \fn cDistribution::cDistribution(const cDistribution& theDistrib) ; 

	 * \param const cDistribution& theDistrib: source
	 * \brief Copy theDistrib into *this
	 */
	cDistribution::cDistribution(const cDistribution& theDistrib)
	{
            parameter = theDistrib.parameter;
            
            if (theDistrib.mtR)
            {	// random generator simulation
                gsl_rng_env_setup() ;
                mtR = gsl_rng_alloc(gsl_rng_default) ;
            }
            else
                mtR = NULL ;
            
            MESS_CREAT("cDistribution")
	}
	/*!
	 * \fn cDistribution::~cDistribution
	 */
	cDistribution::~cDistribution()
	{
            if (mtR != NULL)
            {	// random generator destructor
                gsl_rng_free(mtR) ;
                mtR = NULL ;
            }
            MESS_DESTR("cDistribution")
	}
        
	/*!
	 * \fn vector<double> cDistribution::GetParams(void) const
	 * \param void.
	 * \brief Return distribution parameters 
	 */
        vector<double> cDistribution::GetParams(void) const
        {
            vector<double> myParams = parameter;
            
            return(myParams);
        }

	/*!
	 * \fn double cDistribution::GetNParam(void)
	 * \param void.
	 * \brief return the number of parameters (2)
	 */
	uint cDistribution::GetNParam(void) const
	{
		return parameter.size() ;
	}


	/*!
	 * \fn void cDistribution::ParameterPrint(ostream& theOut) const
	 * \param ostream& theOut: the output stream, default cout.
	 */
	void cDistribution::ParameterPrint(ostream& theOut) const
	{
            uint i, myNParams = parameter.size();
            theOut << "parameters: ";
            
            for (i=0; i < myNParams-1; i++)
                theOut << parameter[i] << "; ";

            theOut << parameter[myNParams-1] << endl;
	}
        
	/*!
         * Default Print method
	 * \fn void cDistribution::Print(ostream& theOut) const
	 * \param ostream& theOut: the output stream, default cout.
	 */
	void cDistribution::Print(ostream& theOut) const
	{
            ostringstream myName;
            myName = Name();
            theOut << (myName.str()).c_str() ;
            theOut << " distribution with " ;
            ParameterPrint(theOut);
            theOut << endl ;

	}

}//namespace
