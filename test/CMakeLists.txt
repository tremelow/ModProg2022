add_executable(test1 TestCPlusPlus.cpp)

target_include_directories(test1 PUBLIC
    "${ERROR_INCLUDE}" "${MATPLOTLIB_INCLUDE}" "${MIXTURES_INCLUDE}"
)

target_link_libraries(test1 INTERFACE matplotlib)
target_link_libraries(test1 PUBLIC mixtures GSL::gsl)