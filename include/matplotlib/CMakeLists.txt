set(MATPLOTLIB_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}")

add_library(matplotlib INTERFACE matplotlibcpp.h)
target_link_libraries(matplotlib INTERFACE Python::Python Python::NumPy)
