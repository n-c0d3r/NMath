
#####################################################################################
#   Includes
#####################################################################################
include(NCPP/ConfigureCompiler)



#####################################################################################
#   Options
#####################################################################################
set(NMATH_DEFAULT_FP_TYPE "ncpp::f32" CACHE STRING "Default floating-point type")
set(NMATH_DEFAULT_INT_TYPE "ncpp::i32" CACHE STRING "Default integer type")



#####################################################################################
#   Generated files
#####################################################################################
# nmath target configure file
configure_file(source/nmath/.config "${NMATH_GENERATED_FILES_DIR}/config.hpp")



#####################################################################################
#   nmath target's files
#####################################################################################
set(NMATH_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/source" PARENT_SCOPE)

# nmath target source files
file(GLOB_RECURSE source_files
    "source/*.cpp"
    "source/*.hpp"
)

# Exclude the windows platform files from the list if not using windows
if(NOT WIN32)
    list(FILTER source_files EXCLUDE REGEX "source/nmath/windows/*.*")
endif()

# Exclude the posix platform files from the list if not using posix
if(NOT UNIX)
    list(FILTER source_files EXCLUDE REGEX "source/nmath/posix/*.*")
endif()

# create source group
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/source PREFIX source FILES ${source_files})

file(GLOB_RECURSE generated_files
    "${CMAKE_CURRENT_BINARY_DIR}/generated_files/*.cpp"
    "${CMAKE_CURRENT_BINARY_DIR}/generated_files/*.hpp"
)
source_group(TREE "${CMAKE_CURRENT_BINARY_DIR}/generated_files" PREFIX generated_files FILES ${generated_files})



#####################################################################################
#   Create nmath target
#####################################################################################
add_library(nmath STATIC
    ${source_files}
    ${generated_files}
)



#####################################################################################
#   nmath target settings
#####################################################################################
set_target_properties(nmath
    PROPERTIES 
        FOLDER "nmath"
)
target_link_libraries(nmath
    PUBLIC 
        ncpp
)
target_include_directories(nmath
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/source
        ${CMAKE_CURRENT_BINARY_DIR}/generated_files
)

# MSVC compile options
if(MSVC)
  target_compile_options(nmath PUBLIC /GT)
endif()



#####################################################################################
#   Dependencies
#####################################################################################
add_dependencies(nmath ncpp)



#####################################################################################
#   Add dependencies
#####################################################################################
add_subdirectory(samples)



