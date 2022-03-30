
add_library(error StdAfxError.cpp cError.cpp)

# new in 3.13 (2018), to avoid having to do global `include_directories`
target_include_directories(error PUBLIC "${ERROR_INCLUDE}")

# new in CMake 3.16 (2019), to speed up compilation 
# (like stdafx.h files in Visual Studio)
# target_precompile_headers(error PUBLIC ${ERROR_H})