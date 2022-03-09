#include <math.h>  
#include <gsl/gsl_cdf.h>
#include <iostream>
#include <sstream>
#include "cExponential.h"
#include "matplotlibcpp.h"

using namespace std;

/*!
 \file cExponential.cpp
 \brief implementation of the class for exponential distributions

 \author Jean-Baptiste DURAND
 \date jan-27-2022
*/
namespace Mixtures {
    
        using namespace std;
         
         /*!
	 * \fn cExponential::cExponential(const vector<double>& theDistrParameter, 
                                   bool theSimulFlag)
	 * \param bool theSimulFlag: true if created for simulation
	 */
	cExponential::cExponential(const vector<double>& theDistrParameter, 
                                   bool theSimulFlag)
        :cDistribution(theDistrParameter, theSimulFlag)
	{
            uint myNbParameters = theDistrParameter.size();
            
            // parameter = theDistrParameter;
            
            if (myNbParameters != 1) 
            {
                cError("Number of parameters must be 1") ;
            }
            else 
            {
                if (parameter[0] <= 0) 
                {
                    cError("Parameter must be > 0") ;
                }
            }
            if (theSimulFlag)
            {	// random generator simulation
                gsl_rng_env_setup() ;
                mtR = gsl_rng_alloc(gsl_rng_default) ;
            }
            else
                mtR = NULL ;
            
            MESS_CREAT("cExponential")
	}
	/*!
	 * \fn cExponential::cExponential(float theParam, bool theSimulFlag) ; 

	 * \param float theParam: parameter
	 * \param bool theSimulFlag: true if created for simulation
	 */
	cExponential::cExponential(float theParam, bool theSimulFlag)
	{
            parameter.resize(1);
            
            parameter[0] = theParam;
            if (theParam <= 0) 
            {
                cError("Parameter must be > 0") ;
            }
            if (theSimulFlag)
            {	// random generator simulation
                gsl_rng_env_setup() ;
                mtR = gsl_rng_alloc(gsl_rng_default) ;
            }
            else
                mtR = NULL ;
            
            MESS_CREAT("cExponential")
	}
	/*!
	 * \fn cExponential::~cExponential
	 * \details: nothing to do here
	 */
	cExponential::~cExponential()
        
	{
            MESS_DESTR("cExponential")
	}

	/*!
	 * \fn cAbstCondVar* cNormResiduals::::PtrCopy()
	 */

	/* cAbstResiduals* cNormResiduals::PtrCopy() const
	{
		cNormResiduals *mycNormResiduals = NULL ;
		bool mySimulFlag = false ;

		if (mtR != NULL)
			mySimulFlag = true ;

		mycNormResiduals = new cNormResiduals(NULL, mySimulFlag);

		return mycNormResiduals;
	}*/

	/*!
	 * \fn void cExponential::Generate(const uint theNSample, vector<double>& theYt) const
	 * \param uint theNSample: sample size
	 * \param vector<double>& theYt: output vector
	 */	
	void cExponential::Generate(uint theNSample, vector<double>& theYt) const 
	{
		theYt.resize(theNSample) ;

		for (uint t = 0 ; t < theNSample ; t++)
			theYt[t] = gsl_ran_exponential(mtR, parameter[0]);
                
	}

	/*!
	 * \fn cExponential::Density(double theY, bool theLog=false) 
	 * \param double theY: the point where density is computed.
	 * \brief Compute the log density of N(0, 1)
	 */
	double cExponential::Density(double theY, bool theLog) const
	{
            double d = log(parameter[0]) - parameter[0] * theY;
            
            if (theY < 0)
            {
                if (theLog)
                    cError("Cannot compute exponential log density for y < 0") ;
                else
                    return(0);
            }
            else
            {
                if (theLog)
                    return(d);
                else
                    return(exp(d));
            }
	}

	/*!
	 * \fn double cExponential::GetNParam(void)
	 * \param void.
	 * \brief return the number of parameters (2)
	 */
	uint cExponential::GetNParam(void) const
	{
		return 1 ;
	}
	
        /*!
	 * \fn ostringstream cExponential::Name() const
	 * \param ostream& theOut: the output stream, default cout.
	 */
	ostringstream cExponential::Name() const
	{
            ostringstream theOut; 
            
            theOut << "Exponential" ;
            
            return(theOut);
	}
        
	/*!
	 * \fn void cExponential::Print(ostream& theOut) const
	 * \param ostream& theOut: the output stream, default cout.
	 */
	void cExponential::Print(ostream& theOut) const
	{
		theOut << "Exponential distribution with parameter "
                        << parameter[0] << endl ;

	}

	/*!
	 * \fn void cExponential::Plot() const
	 * \detail plot pdf with python.
	 */
	void cExponential::Plot(bool show) const
	{
            // Compute support to display using quantiles
            double q1, q2;
            uint t, my_nb_points=200;
            std::vector<float> abs, ord;
            
            abs.resize(my_nb_points);
            ord.resize(my_nb_points);
            
            q1 = 0;
            q2 = -1/parameter[0] * log(0.05);

            for (t=0; t<my_nb_points; t++)
            {
                abs[t] = parameter[0] + q1 + t * (q2 - q1) / my_nb_points;
                ord[t] = Density(abs[t]);
            }
            matplotlibcpp::plot(abs, ord);
            if (show)
                matplotlibcpp::show();

	}


}//namespace
