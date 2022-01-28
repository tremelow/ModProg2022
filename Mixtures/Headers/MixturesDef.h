#pragma once 
#ifndef _MIXTURESDEF_H_
#define _MIXTURESDEF_H_
/*!
	\file MixturesDef.h
	\brief Common definitions for all the classes.
	
	\author Jean-Baptiste DURAND
	\date jan-27-2022
*/

#include "cError.h"

namespace Mixtures {
	using namespace ErrorNameSpace;

	using namespace std;

	#ifndef MIN
		#define MIN(p, q) ( (p) < (q) ? (p): (q) ) ///< Definition of MIN if doesn't exist.
	#endif // MIN

	#ifndef MAX
		#define MAX(p, q) ( (p) > (q) ? (p): (q) ) ///< Definition of MAX if doesn't exist.
	#endif // MAX

	#ifndef SIGN
		#define SIGN(p) ( (p) > 0 ? 1: -1 )
	#endif // SIGN

	#ifndef PI
		#define PI 3.1415926535897931159979634685
	#endif //PI

	#ifndef SQRT_PI
		#define SQRT_PI 1.7724538509055161039640324816
	#endif // SQRT_PI

	#ifndef SQRT_2_PI
		#define SQRT_2_PI 2.50662827463100050241576528481 ///< useful value
	#endif //SQRT_2_PI

	#ifndef LOG_SQRT_2_PI
		#define LOG_SQRT_2_PI 0.918938533204672741780329736406
	#endif // LOG_SQRT_2_PI

	#ifndef LOG_PI
		#define LOG_PI 1.1447298858494001638774761886
	#endif // LOG_PI

	// FOR DEBUGGING
	#ifdef _MESS_CREAT
		#ifdef _DEBUG
			#define MESS_CREAT(p)  std::cout << "creating " << p << std::endl ;
			#define MESS_DESTR(p)  std::cout << "deleting  " << p << std::endl ;
		#else
			#define MESS_CREAT(p) ///< used for debugging 
			#define MESS_DESTR(p) ///< used for debugging
		#endif //_DEBUG
	#else
		#define MESS_CREAT(p) ///< used for debugging
		#define MESS_DESTR(p) ///< used for debugging
	#endif //_MESS_CREAT

}


#endif // _REGARCHDEF_H_

