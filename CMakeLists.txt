cmake_minimum_required (VERSION 3.16.3)

## Project name and the programming language
project(DistribMixture CXX)

## Force a certain standard
set(CMAKE_CXX_STANDARD 17)

## Indique les options de compilations pour le projet
## -pg : donne la possibilité de faire du profiling
## -Wall : affiche les warnings
set(CMAKE_CXX_FLAGS "-g")# Wall -Wextra -Weverything -Wno-c++98-compat-pedantic -Wno-c++98-compat")

find_package(GSL REQUIRED) # imports GSL::gsl
## If the package is not found, you might be able to use the 
## untested commands below
# include(FetchContent)
# FetchContent_Declare(
#     GSL
#     GIT_REPOSITORY git://git.savannah.gnu.org/gsl.git
#     GIT_TAG release-2-7
# )

find_package(Python COMPONENTS Interpreter Development NumPy)

## usual Python setup
set(PYTHON_INCLUDE_DIR "/usr/include/python3.8")
## ad-hoc Python include directories because it does not behave well 
## on my system
# set(PYTHON_INCLUDE_DIR 
#     "/Users/tremelow/opt/miniconda3/envs/modprog/include/python3.8")
# set(NUMPY_INCLUDE_DIR 
#     "/Users/tremelow/opt/miniconda3/envs/modprog/lib/python3.8/site-packages/numpy/core/include")
# ^ numpy.get_include()

include_directories(${PYTHON_INCLUDE_DIR} ${NUMPY_INCLUDE_DIR})
# ^ not the best practice to have a global include but it is used 
# everywhere in the project...

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(test)
