#include <math.h>  
#include <gsl/gsl_cdf.h>
#include <iostream>
#include <sstream>
#include "cCorruptedGaussian.h"
#include "matplotlibcpp.h"

using namespace std;

/*!
 \file cCorruptedGaussian.cpp
 \brief Definition of the class for N(m, s2) distributions.
 * Corrupted for the need of illustrating debugging

 \author Jean-Baptiste DURAND
 \date jan-27-2022
*/
namespace Mixtures {
    
        using namespace std;
         
         /*!
	 * \fn Gaussian::cCorruptedGaussian(const vector<double>& theDistrParameter, 
                                   bool theSimulFlag)
	 * \param bool theSimulFlag: true if created for simulation
	 */
	cCorruptedGaussian::cCorruptedGaussian(const vector<double>& theDistrParameter, 
                                               bool theSimulFlag)
	{
            uint myNbParameters = theDistrParameter.size();
            
            parameter = theDistrParameter;
            
            if (myNbParameters != 2) 
            {
                cError("Number of parameters must be 2") ;
            }
            else 
            {
                if (parameter[1] <= 0) 
                {
                    cError("Variance parameter must be > 0") ;
                }
            }
            if (theSimulFlag)
            {	// random generator simulation
                gsl_rng_env_setup() ;
                mtR = gsl_rng_alloc(gsl_rng_default) ;
            }
            else
                mtR = NULL ;
            
            MESS_CREAT("cCorruptedGaussian")
	}
	/*!
	 * \fn cCorruptedGaussian(float theMean, float theVariance, 
                         bool theSimulFlag) ; 

	 * \param float theMean: Mean
	 * \param float theVariance: Variance
	 * \param bool theSimulFlag: true if created for simulation
	 */
	cCorruptedGaussian::cCorruptedGaussian(float theMean, float theVariance, 
                             bool theSimulFlag)
	{
            parameter.resize(2);
            
            parameter[0] = theMean;
            parameter[1] = theVariance;
            if (theVariance <= 0) 
            {
                cError("Variance parameter must be > 0") ;
            }
            if (theSimulFlag)
            {	// random generator simulation
                gsl_rng_env_setup() ;
                mtR = gsl_rng_alloc(gsl_rng_default) ;
            }
            else
                mtR = NULL ;
            
            MESS_CREAT("cCorruptedGaussian")
	}
	/*!
	 * \fn cCorruptedGaussian::~cCorruptedGaussian
	 * \details: nothing to do here
	 */
	cCorruptedGaussian::~cCorruptedGaussian()
	{
            MESS_DESTR("cCorruptedGaussian")
	}

	/*!
	 * \fn void cCorruptedGaussian::Generate(const uint theNSample, vector<double>& theYt) const
	 * \param uint theNSample: sample size
	 * \param vector<double>& theYt: output vector
	 */	
	void cCorruptedGaussian::Generate(uint theNSample, vector<double>& theYt) const 
	{
		theYt.resize(theNSample) ;

		for (uint t = 0 ; t < theNSample ; t++)
			theYt[t] = sqrt(parameter[1])*gsl_ran_ugaussian(mtR)  + 
                                parameter[0];                
                
	}
	
        /*!
	 * \fn vector<double> cCorruptedGaussian::GetParams(void) const
	 * \param void.
	 * \brief Return distribution parameters 
	 */
        vector<double> cCorruptedGaussian::GetParams(void) const
        {
            vector<double> myParams = parameter;
            
            return(myParams);
        }

	/*!
	 * \fn cCorruptedGaussian::Density(double theY, bool theLog=false) 
	 * \param double theY: the point where density is computed.
	 * \brief Compute the log density of N(0, 1)
	 */
	double cCorruptedGaussian::Density(double theY, bool theLog) const
	{
            double d = -(theY-parameter[0])*(theY-parameter[0])/(2.0 * parameter[1]) ;
            
            d += -LOG_SQRT_2_PI - 0.5 * log(parameter[1]);
            
            if (theLog)
                return(d);
            else
                return(exp(d));
	}

	/*!
	 * \fn double cCorruptedGaussian::GetNParam(void)
	 * \param void.
	 * \brief return the number of parameters (2)
	 */
	uint cCorruptedGaussian::GetNParam(void) const
	{
		return 2 ;
	}
	
        /*!
	 * \fn ostringstream cCorruptedGaussian::Name() const
	 * \param ostream& theOut: the output stream, default cout.
	 */
	ostringstream cCorruptedGaussian::Name() const
	{
            ostringstream theOut; 
            
            theOut << "Gaussian" ;
            
            return(theOut);
	}
        
	/*!
	 * \fn void cCorruptedGaussian::Print(ostream& theOut) const
	 * \param ostream& theOut: the output stream, default cout.
	 */
	void cCorruptedGaussian::Print(ostream& theOut) const
	{
		theOut << "Gaussian distribution with mean "
                        << parameter[0] << " and variance " 
                        << parameter[1] << endl ;

	}

	/*!
	 * \fn void cCorruptedGaussian::Plot() const
	 * \detail plot pdf with python.
	 */
	void cCorruptedGaussian::Plot(bool show) const
	{
            // Compute support to display using quantiles
            double q1, q2;
            uint t, my_nb_points=200;
            std::vector<float> abs, ord;
            
            abs.resize(my_nb_points);
            ord.resize(my_nb_points);
            
            q1 = gsl_cdf_gaussian_Pinv(0.001, sqrt(parameter[1]));
            q2 = gsl_cdf_gaussian_Pinv(0.999, sqrt(parameter[1]));   

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
