file(GLOB MIXTURES_SRC "*.cpp")
file(GLOB MIXTURES_H "${MIXTURES_INCLUDE}/*.h")

add_library(mixtures ${MIXTURES_SRC})

target_link_libraries(mixtures INTERFACE matplotlib PUBLIC error GSL::gsl)

# avoid global `include_directories`
target_include_directories(mixtures PUBLIC 
    "${ERROR_INCLUDE}" "${MATPLOTLIB_INCLUDE}" "${MIXTURES_INCLUDE}"
)
# new in CMake 3.16 (2019), to speed up compilation 
# (like stdafx.h files in Visual Studio)
target_precompile_headers(mixtures PUBLIC "${MIXTURES_H}")