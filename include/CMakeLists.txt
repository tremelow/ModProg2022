set(MATPLOTLIB_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/matplotlib" PARENT_SCOPE)
add_subdirectory(matplotlib)

set(ERROR_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/error" PARENT_SCOPE)
file(GLOB ERROR_H "${ERROR_INCLUDE}/*.h")

set(MIXTURES_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/mixtures" PARENT_SCOPE)

# ^ ou bien faire file(GLOB ...) pour faire des "listes" de headers à link
