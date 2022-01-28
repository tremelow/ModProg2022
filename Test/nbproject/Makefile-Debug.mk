#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Sources/TestCPlusPlus.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../Error/build/Debug/GNU-Linux-x86 -L../Mixtures/build/Debug/GNU-Linux-x86 -Wl,-rpath,'../Mixtures/dist/Debug/GNU-Linux' -L../Mixtures/dist/Debug/GNU-Linux -lMixtures -Wl,-rpath,'../Error/dist/Debug/GNU-Linux' -L../Error/dist/Debug/GNU-Linux -lError -lgsl -lgslcblas -lpython3.8

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/test

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/test: ../Mixtures/dist/Debug/GNU-Linux/libMixtures.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/test: ../Error/dist/Debug/GNU-Linux/libError.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/test: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/test ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Sources/TestCPlusPlus.o: Sources/TestCPlusPlus.cpp
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/python3.8 -I../Error/Headers -I../VectorAndMatrix/Headers -I../Mixtures/Headers -IHeaders -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sources/TestCPlusPlus.o Sources/TestCPlusPlus.cpp

# Subprojects
.build-subprojects:
	cd ../Mixtures && ${MAKE}  -f Makefile CONF=Debug
	cd ../Error && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libMixtures.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libError.so
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/test

# Subprojects
.clean-subprojects:
	cd ../Mixtures && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../Error && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
